#pragma once
#include <vector>

//A data storage could later be implemented as a queue class with a support of concurrent push/pop operations

using AudioBuf = std::vector<char>;
using InputBuffer = std::vector<AudioBuf>;
using OutputBuffer = std::vector<AudioBuf>;
