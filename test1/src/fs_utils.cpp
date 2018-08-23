#include <filesystem>

#include "fs_utils.h"

#ifdef _WIN32
namespace std_fs = std::experimental::filesystem::v1;
#else
namespace std_fs = std::filesystem;
#endif

using namespace std;


void applyEachFile(const string &path, function<void(const string &)> func)
{
	for (auto& p : std_fs::directory_iterator(path))
		func(p.path().string());
}