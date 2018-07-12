#include <iostream>

using namespace std;

#include "dummy.h"

void foo(dummy <1> & d1, dummy <2> & d2, dummy <3> & d3) {
	return;
}

struct A
{
	dummy <1> md1;
	dummy <3> md3;
	dummy <2> md2;
	A(dummy <1> & d1, dummy <2> & d2, dummy <3> & d3) :
		md2(d2), md1(d1), md3(d3) { std::cout << "A::ctor" << endl;}
	A() { std::cout << "A::ctor def" << endl; }
};

int main (void)
{
	dummy<1> dOne;
	dummy<1> dTwo = dOne;
	dummy<1> dThree = std::move(dOne);

	std::cout << "foo" << std::endl;

	foo(dummy <1>(), dummy <2>(), dummy <3>());

	std::cout << "class A" << std::endl;

	A a0 = A(dummy <1>(), dummy <2>(), dummy <3>());

	cout << "pam-pam" << endl;
}