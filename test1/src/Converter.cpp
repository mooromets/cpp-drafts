#include <fstream>
#include <filesystem>

#include "Converter.h"
#include "encoder.h"

using namespace std;

Converter::Converter(const std::string &path) : m_Path(path)
{
	callOnEachFile([this](const string &fname)
	{
		if (!fname.compare(fname.length() - 4, 4, ".wav"))
		{
			convertToMp3(fname);
		}
	});
	
}

void Converter::callOnEachFile(std::function<void(const string &)> func)
{
	using namespace std::experimental::filesystem::v1;

	for (auto& p : directory_iterator(m_Path))
		func(p.path().string());
}


void Converter::convertToMp3(const string &filename) 
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

		encode<LameEncoder>();
	}
}


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
