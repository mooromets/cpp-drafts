#pragma once

#include <iostream>

template <int N>
class dummy {
public:
	int id;
	dummy() : id(N) { std::cout << "dummy" << id << "::ctor() def" << std::endl; }
	dummy(dummy&& d) : id(std::move(d.id)) { std::cout << "dummy" << id << "::ctor() move" << std::endl; }
	dummy(const dummy& d) : id(d.id) { std::cout << "dummy" << id << "::ctor() copy" << std::endl; }
};