#pragma once
#include <string>
#include <functional>

void applyEachFile(const std::string &path, std::function<void(const std::string &)> func);