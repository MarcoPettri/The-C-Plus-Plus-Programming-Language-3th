// Exercise 4.3
/*

	Write a program that prints the sizes of the fundamental types, a few pointer types, and a
	few enumerations of your choice. Use the sizeof operator.

*/

#include<iostream>

int main()
{
	short  sh;
	short* shPtr;

	int  integ;
	int* integPtr;

	float  fl;
	float* flPtr;

	double  doubl;
	double* doublPtr;

	unsigned unsigInteg;
	unsigned long unsigIntegLL;

	long double longDouble;

	enum enumeration{ZERO, ONE = 33, CHAR = 'A' };

	std::cout << "short: " << sizeof(sh)
		<< "\nshort Ptr: " << sizeof(shPtr)
		<< '\n';

	std::cout << "int: " << sizeof(integ)
		<< "\nint ptr: " << sizeof(integPtr)
		<< '\n';

	std::cout << "float: " << sizeof(fl)
		<< "\nfloat ptr: " << sizeof(flPtr)
		<< '\n';

	std::cout << "double: " << sizeof(doubl)
		<< "\ndouble ptr: " << sizeof(doublPtr)
		<< '\n';

	std::cout << "unsigned: " << sizeof(unsigInteg)
		 << "\nunsigned long: " << sizeof(unsigIntegLL)
		<< "\nlong double: " << sizeof(longDouble)
		<< '\n';
	
	std::cout << "enumeration ZERO: " << sizeof(enumeration::ZERO)
		<< "\nenumeration ONE: " << sizeof(enumeration::ONE)
		<< "\nenumeration CHAR: " << sizeof(enumeration::CHAR)
		<< '\n';


	return 0;
}