// Exercise 6.7
/*
	Write 5 expressions for which the order of evaluation is undefined. Execute them to see
	what one or – preferably – more implementations do with them.
*/


#include<iostream>

int main()
{
	int a = 34;
	int b = 4;
	int i = b;
	int d = a;
	int e = a + b;
	int f = b * a;
	int v[20] = { a, b, d, e, i, f, 45, 234, 19 };

	int c = (b = a + 2) - (a = 1); // (1)  undefined
	int j = i * i++; // (2) undefined 
	a = b += c++ - d + --e / -f; // (3) undefined
	v[i] = i++; // (4) undefined
	v[4] = v[3]--; // (5) undefined


	std::cout << "(1) " << c
		<< "\n(2) " << j
		<< "\n(3) " << a << " " << b
		<< "\n(4) " << v[i]
		<< "\n(5) " << v[4] << std::endl;





	return 0;
}