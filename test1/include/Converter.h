#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include <vector>

using PcmBuf = std::vector<short int>;
using Mp3Buf = std::vector<unsigned char>;
using InputBuffer = std::vector<PcmBuf>;
using OutputBuffer = std::unordered_map<unsigned, Mp3Buf>;

template <class Ty_Encoder>
class Converter
{
public:
	Converter (const Ty_Encoder &encoder, 
				size_t chunkSize = 20000, 
				size_t maxBufSize = 100000000) :
		m_Encoder(encoder),
		m_ChunkSize(chunkSize), 
		m_MaxBufLength(maxBufSize / sizeof(short)) {}

	void convert(const std::string &filename) 
	{
		ifstream ifile(filename, std::ifstream::binary);
		//m_InBuf.clear();

		// buffer
		ifile.seekg(0, ifile.end);
		size_t length = ifile.tellg();
		ifile.seekg(0, ifile.beg);
		length = min(length, MaxBufLength);

		PcmBuf buffer(length);

		while (ifile) {
			ifile.read(reinterpret_cast<char* >(buffer.data()), length * sizeof(short));
			if (ifile.gcount() == 0)
			{
				break;
			}

			//prepare input
			fillInput(buffer);

			//TODO 
			//DataProcesser comes here

			m_Encoder.encode(m_InBuf[0], m_OutBuf[0]);
		}
	}
private:
	void Converter::fillInput(const PcmBuf &rawBuf)
	{
		const short *pBeg = rawBuf.data();
		const short *pEnd = nullptr;
		do {
			pEnd = min(pBeg + ChunkSize, rawBuf.data() + rawBuf.size());
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