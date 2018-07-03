#include <iostream>
#include <pybind11/pybind11.h>
namespace py = pybind11;

// pybind11 example
int add(int i, int j) {
	return i + j;
}

PYBIND11_MODULE(examplepy, m) {
	m.doc() = "pybind11 examplepy plugin"; // optional module docstring

	m.def("add", &add, "A function which adds two numbers");
}