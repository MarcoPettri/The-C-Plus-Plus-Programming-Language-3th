// Exercise 5.4
/*
		Write a function that swaps (exchanges the values of) two integers. Use int* as the argument type.
		Write another swap function using int& as the argument type.
*/


#include<iostream>

void swap(int*, int*);
void swap(int&, int&);

int main()
{
	int first{ 33 };
	int second{ 13 };


	std::cout << "First: " << first
		<< "\nSecond: " << second << std::endl;
	
	
	::swap(&first, &second);

	std::cout << "\nSwap with Pointers" <<
		"\nFirst: " << first
		<< "\nSecond: " << second << std::endl;	
	
	
	::swap(first, second);
	std::cout << "\nSwap with references" <<
		"\nFirst: " << first
		<< "\nSecond: " << second << std::endl;


	return 0;
}

void swap(int* rhs, int* lhs)
{
	int temp{ *rhs };
	*rhs = *lhs;
	*lhs = temp;
}

void swap(int& rhs, int& lhs) 
{
	int temp{ rhs };
	rhs = lhs;
	lhs = temp;

}