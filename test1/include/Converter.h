#pragma once

#include <string>
#include <functional>
#include <fstream>
#include <algorithm>

#include "DataStorage.h"

template <class Ty_Encoder>
class Converter
{
public:
	Converter (const Ty_Encoder &encoder, 
				size_t chunkSize = 20 * 1024, 
				size_t maxBufSize = 100000 * 1024) :
		m_Encoder(encoder),
		m_ChunkSize(chunkSize), 
		m_MaxBufLength(maxBufSize) {}


	void convert(const std::string &filename) 
	{
		m_InBuf.clear();
		m_OutBuf.clear();
		ifstream ifile(filename, std::ifstream::binary);

		// buffer
		auto length = min (fileLength(filename), m_MaxBufLength);
		AudioBuf buffer(length);
		AudioBuf output;

		while (ifile) {
			ifile.read(buffer.data(), length);
			auto read = ifile.gcount();
			if (read == 0) {
				m_Encoder.flush(output);
				break;
			} else {
				//prepare input
				fillInput(buffer);

				//TODO 
				//DataProcesser comes here

				AudioBuf ab;
				m_Encoder.encode(m_InBuf[0], output);
			}
		}
	}
private:
	void Converter::fillInput(const AudioBuf &rawBuf)
	{
		const char *pBeg = rawBuf.data();
		const char *pEnd = nullptr;
		do {
			pEnd = min(pBeg + m_ChunkSize, rawBuf.data() + rawBuf.size());
			m_InBuf.emplace_back(pBeg, pEnd);
			pBeg = pEnd;
		} while (pBeg != rawBuf.data() + rawBuf.size());
	}

	const size_t m_ChunkSize;
	const size_t m_MaxBufLength;
	const Ty_Encoder &m_Encoder;
	InputBuffer m_InBuf;
	OutputBuffer m_OutBuf;
};