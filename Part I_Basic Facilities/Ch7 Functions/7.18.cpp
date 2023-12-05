// Exercise 7.18

/*
	Write a factorial function that does not use recursion. See Exercise &11.6.

*/

#include<stdexcept>

template<typename T> inline
T factorial(T arg) {

	if (arg < 0) { throw std::domain_error("Negative Factorial"); }

	T result = 1;

	while (arg > 1) { result *= arg--; }

	return result;
}