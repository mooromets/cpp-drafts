#pragma once
#include <string>
#include <functional>

bool isWavFile	(const std::string &path);

void applyEachFile	(const std::string &path, 
					std::function<void(const std::string &)> func, 
					std::function<bool(const std::string &)> cond = isWavFile);

std::string wavPathToMp3(const std::string &pathWav);