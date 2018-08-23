#include <stdio.h>
#include <iostream>
#include <string> 
//#include <list> 
//#include <functional> 
//#include <filesystem>
//#include <thread>
//#include <condition_variable>
//#include <map>
//#include <chrono> // debug
//#include <fstream>
#include "lame.h"
//#include <array>
//#include <unordered_map>
//#include <numeric>
//#include <algorithm>

#include "Converter.h"
#include "fs_utils.h"
#include "encoder.h"

using namespace std;

/*

void convertToMp3(const string &filename)
{
	cout << "..." << filename << "..." << endl;
};


using InputBuffer = vector<vector<char>>;
using OutputBuffer = unordered_map<unsigned, vector<char>>;

InputBuffer in;
mutex mut_Input;

void fillInput(const vector<char> &rawBuf, InputBuffer &inpBuf)
{
		size_t chunk_size = 20000; //20KB

		const char *pBeg = rawBuf.data();
		const char *pEnd = nullptr;
		do {
			pEnd = min(pBeg + chunk_size, rawBuf.data() + rawBuf.size());
			in.emplace_back(pBeg, pEnd);
			pBeg = pEnd;
		} while (pBeg != rawBuf.data() + rawBuf.size());
}

void worker(const InputBuffer &inpBuf, const vector<size_t>& idx, mutex &mut, OutputBuffer &out)
{
	for (auto i : idx)
	{

	}

	unique_lock<mutex> ul(mut);



}


void readFile(InputBuffer &in, mutex &mut)
{
	ifstream ifile("testcase.wav", std::ifstream::binary);
	in.clear();

	// buffer
	size_t maxlength = 100000000; // 100MB
	ifile.seekg(0, ifile.end);
	size_t length = ifile.tellg();
	ifile.seekg(0, ifile.beg);
	length = min(length, maxlength);

	vector<char> buffer(length);

	while (ifile) {
		ifile.read(buffer.data(), length);
		if (ifile.gcount() == 0)
		{
			break;
		}

		//prepare input
		fillInput(buffer, in);

		//prepare queues
		vector<size_t> idx(in.size());
		iota(std::begin(idx), std::end(idx), 0); // fill with indexes
		random_shuffle(std::begin(idx), std::end(idx)); // balance the load


	}
}
*/



int main(int argc, char *argv[]) 
{
	if (argc != 2) 
	{
		cout << "call: wav2mp3 <path_name>" << endl;
		return 1;
	} 

	auto lenc = LameEncoder();
	auto conv = Converter<LameEncoder>(lenc);

	applyEachFile(argv[1], 
		[&conv](const string &fname)
		{
			conv.convert(fname);
		});

	return 0;
}