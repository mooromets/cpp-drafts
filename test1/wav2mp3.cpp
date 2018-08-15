#include <iostream>
#include <string> 
#include <list> 
#include <functional> 
#include <filesystem>
#include <thread>

using namespace std;
using namespace std::experimental::filesystem::v1;

void callOnEachFile(const string &path, std::function<void(const string &)> func)
{
	for (auto& p : directory_iterator(path))
		func(p.path().string());
}

void convertToMp3(const string &filename)
{
	cout << "..." << filename << "..." << endl;
};


int main(int argc, char *argv[]) 
{
	if (argc != 2) 
	{
		cout << "call: wav2mp3 <path_name>" << endl;
		return 0;
	} 

	callOnEachFile(argv[1], 
		[](const string &fname) 
		{
			if (fname.compare(fname.length() - 3, 3, ".wav"))
			{
				convertToMp3(fname);
			}
		});

	unsigned concurentThreadsSupported = std::thread::hardware_concurrency();
	
	cout << "ff";
	return 0;
}