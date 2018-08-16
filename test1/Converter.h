#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include <vector>


class Converter
{
public:
	using PcmBuf = std::vector<short int>;
	using Mp3Buf = std::vector<unsigned char>;
	using InputBuffer = std::vector<PcmBuf>;
	using OutputBuffer = std::unordered_map<unsigned, Mp3Buf>;
	
	const size_t ChunkSize = 20000; //20KB
	const size_t MaxBufLength = 100000000 / sizeof(short); // 100MB

	Converter(const std::string &path);


private:
	void callOnEachFile(std::function<void(const std::string &)> func);
	void convertToMp3(const std::string &filename);
	void fillInput(const PcmBuf &rawBuf);

	std::string m_Path;
	InputBuffer m_InBuf;
};