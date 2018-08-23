#include <filesystem>

#include "fs_utils.h"

#ifdef _WIN32
namespace std_fs = std::experimental::filesystem::v1;
#else
namespace std_fs = std::filesystem;
#endif

using namespace std;


void applyEachFile(const string &path, function<void(const string &)> func, function<bool(const string &)> cond)
{
	for (auto& p : std_fs::directory_iterator(path))
		if (cond(p.path().string()))
			func(p.path().string());
}


bool isWavFile(const std::string &path) 
{
	return std_fs::path(path).extension() == ".wav" ? true : false;
}


std::string wavPathToMp3(const std::string &pathWav) 
{
	std_fs::path wav(pathWav);
	auto ret = wav.parent_path() /= wav.filename().stem().string() + ".mp3";
	return ret.string();
}