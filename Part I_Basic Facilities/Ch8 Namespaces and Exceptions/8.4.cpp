// Exercise 8.4
/*
		
		 Write a program that throws an exception in one function and catches it in another

*/

#include<iostream>
#include<stdexcept>


template<typename T> inline
static T factorial(T arg) {

	if (arg < 0) { throw std::domain_error("Negative Factorial"); }

	T result = 1;

	while (arg > 1) { result *= arg--; }

	return result;
}

// print x! mod y 
template<typename T, typename T2>
static void modFactorial(T x, T2 y) {

	try {
		
		if (!y) { throw std::invalid_argument("ZeroDivision"); }
		std::cout << factorial(y) % y;
		
	}
	catch (const std::invalid_argument& exc) { std::cerr << exc.what() << std::endl;}
	catch (const std::domain_error& exc) { std::cerr << exc.what() << std::endl; }
}
int main() {


	double num{ 5.34 };

	short  num2{ -4 };
	short  num3{ 0 };


	modFactorial(num, num2);
	std::cout << '\n';

	modFactorial(num, num3);

	




}