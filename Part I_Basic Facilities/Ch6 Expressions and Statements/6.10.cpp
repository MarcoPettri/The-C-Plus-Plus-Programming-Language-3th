// Exercise 6.10
/*

	Write these functions: strlen(), which returns the length of a C-style string; strcpy(),
	which copies a string into another; and strcmp(), which compares two strings. Consider what
	the argument types and return types ought to be. Then compare your functions with the standard library
	versions as declared in <cstring> (<string.h>) and as specified in §20.4.1
*/

#include<iostream>
#include<cstring>
#include<cstdlib>

typedef char const* str;
typedef std::size_t size;

size strLen(char const*);

char* strCpy(char*, char const*);

int strCmp(char const* lhs, char const* rhs);


int main() {

	size const LENGTH = 20;

	str string1  = "Computer Vision";
	str string2 = "Natural Processing";


	std::cout << "string1: " << string1;


	if (size len_string1 = ::strLen(string1);
		len_string1 == std::strlen(string1)) {
	
		std::cout << "\nLength: " << len_string1 << std::endl;
	}
		
	std::cout << "\nstring2: " << string2;

	if (size len = ::strLen(string2);
		len == std::strlen(string2)){ 

	
		std::cout << "\nLength: " << len << std::endl;
	}

	char copy[20];
	char copy2[20];

	::strCpy(copy, string1);
	std::strcpy(copy2, string1);

	if (!strCmp(copy, copy2)) {

		std::cout << "\nCopy 1: " << copy
			<< "\nCopy 2: " << copy2 << std::endl;
	}
	

	if (int cmp = ::strCmp(string1, string2), 
		std_cmp = std::strcmp(string1, string2);

		cmp > 0 && std_cmp > 0) {

		std::cout << "\nstring1 > string2" << std::endl;
	}
	else if (cmp < 0 && std_cmp < 0) {
		std::cout << "\nstring1 < string2" << std::endl;;
	}
	else {
		std::cout << "\nstring1 == string2" << std::endl;;
	}
	

	return 0;
}

size strLen(const char* arg) {

	if (!*arg) { return 0; }
	const char* end = arg;

	while (*(++end));

	return end - arg;
}

char* strCpy(char* dest, char const* src) {
	
	if (!*src) { return dest; }

	while (*dest++ = *src++);

	return dest;
}

int strCmp(char const* lhs, char const* rhs) {

	while (*lhs && *rhs) {

		if (*lhs > *rhs) { return 1; }
		else if (*lhs++ < *rhs++) { return -1; }
	}

	if (!*lhs && !*rhs) { return 0; }
	else if (*lhs) { return 1; }

	return -1; 
}