#pragma once

#include "Converter.h"
#include <functional>
#include <thread>

class DataProcesser
{
public:
	DataProcesser(const Converter::InputBuffer &inBuf,
			Converter::OutputBuffer &outBuf,
			std::function<void(const Converter::InputBuffer::value_type &,
				Converter::OutputBuffer::value_type &)> func) :
		m_InBuf(inBuf),
		m_OutBuf(outBuf),
		m_Job(func)
	{ 
		m_nThreads = std::thread::hardware_concurrency();
	}

	void doJob();

private:

	static void _job(const Converter::InputBuffer &inbuf,
		const std::vector<size_t>::const_iterator &firstIdx,
		const std::vector<size_t>::const_iterator &lastIdx,
		Converter::OutputBuffer &outbuf,
		std::function<void(const Converter::InputBuffer::value_type &,
			Converter::OutputBuffer::value_type &)> func);

	const Converter::InputBuffer &m_InBuf;
	Converter::OutputBuffer &m_OutBuf;
	std::function<void(const Converter::InputBuffer::value_type &,
		Converter::OutputBuffer::value_type &)> m_Job;
	unsigned m_nThreads;
};