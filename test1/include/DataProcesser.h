#pragma once

#include "Converter.h"
#include <functional>
#include <thread>

class DataProcesser
{
public:
	DataProcesser(const InputBuffer &inBuf,
			OutputBuffer &outBuf,
			std::function<void(const InputBuffer::value_type &,
				OutputBuffer::value_type &)> func) :
		m_InBuf(inBuf),
		m_OutBuf(outBuf),
		m_Job(func)
	{ 
		m_nThreads = std::thread::hardware_concurrency();
	}

	void doJob();

private:

	static void _job(const InputBuffer &inbuf,
		const std::vector<size_t>::const_iterator &firstIdx,
		const std::vector<size_t>::const_iterator &lastIdx,
		OutputBuffer &outbuf,
		std::function<void(const InputBuffer::value_type &,
			OutputBuffer::value_type &)> func);

	const InputBuffer &m_InBuf;
	OutputBuffer &m_OutBuf;
	std::function<void(const InputBuffer::value_type &,
		OutputBuffer::value_type &)> m_Job;
	unsigned m_nThreads;
};