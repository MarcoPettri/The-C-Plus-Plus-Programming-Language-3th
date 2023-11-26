// Exercise 6.13
/*
	Write a function cat() that takes two C-style string arguments and returns a string that is
	the concatenation of the arguments. Use new to find store for the result
*/

#include<iostream>
#include<cstdlib>

char const* cat(char const*, char const*);

int main() {

	char const* lh = "This";
	char const* rh = " is a test";

	char const* result = cat(lh, rh);

	std::cout << result;

	delete[] result;

	return 0;
}

char const* cat(char const* lhs, char const* rhs){

	
	std::size_t len_lhs = 0;
	std::size_t len_rhs = 0;
	std::size_t len;

	while (*lhs++) { ++len_lhs;}
	while (*rhs++) { ++len_rhs; }

	len = ++len_lhs + len_rhs++; 

	char* concat = new char[len];

	lhs -= len_lhs; // points back to the first character
	rhs -= len_rhs; // points back to the first character

	//Note: this loop also copies '\0'
	while (*concat++ = *lhs++);

	// points to '\0' and then rewrites it with the first character of rhs
	concat -= 1;

	while (*concat++ = *rhs++);

	concat -= len; // points back to the first character

	return concat;

}