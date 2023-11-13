// Exercise 4.4
/*
	Write a program that prints out the letters 'a'..'z' and the digits '0'..'9' and their
	integer values. Do the same for other printable characters. Do the same again but use hexa-
	decimal notation

*/


#include<iostream>
#include<cstdlib>

int main()
{
	std::size_t const SIZE_AlP{ 26 };
	std::size_t const SIZE_DIG{ 10 };

	char const ALPHABET[SIZE_AlP]{
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
		'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
		't', 'u', 'v', 'w', 'x', 'y', 'z'
	};

	char const DIGITS[SIZE_DIG]{ 
		'0', '1', '2', '3', '4', 
		'5', '6', '7', '8', '9'
	};


	for (std::size_t index{ 0 }; index < SIZE_AlP; ++index) {

		char const& chr{ ALPHABET[index] };
		std::cout << chr << ": " << static_cast<int>(chr) << '\n';
	}	

	std::cout << std::endl;
	for (std::size_t index{ 0 }; index < SIZE_DIG; ++index) {

		char const& chr{ DIGITS[index] };
		std::cout << chr << ": " << static_cast<int>(chr) << '\n';
	}	

	std::cout << std::hex << std::endl;

	for (std::size_t index{ 0 }; index < SIZE_AlP; ++index) {

		char const& chr{ ALPHABET[index] };
		std::cout << chr << ": " << static_cast<int>(chr) << '\n';
	}	

	std::cout << std::endl;
	for (std::size_t index{ 0 }; index < SIZE_DIG; ++index) {

		char const& chr{ DIGITS[index] };
		std::cout << chr << ": " << static_cast<int>(chr) << '\n';
	}

}

