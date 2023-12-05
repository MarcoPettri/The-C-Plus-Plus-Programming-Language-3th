// Exercise 7.9

/*

	Write an encryption program that reads from cin and writes the encoded characters to 
	cout. You might use this simple encryption scheme: The encrypted form of a character c 
	is c^key[i] where key is a string passed as a command-line argument. The program 
	uses the characters in key in a cyclic manner until all the input has been read. 
	Re-encrypting encoded text with the same key produces the original text. If no key (or 
	a null string) is passed, then no encryption is done. 
*/

#include<iostream>
#include<cstdlib>
#include<cstring>

int main(int argc, const char* argv[]) {


	const char* key = (argc > 1) ? argv[1] : "";
	std::size_t key_len = (argc > 1) ? std::strlen(key) : 1;
	char ch;

	for (std::size_t i = 0; std::cin.get(ch); i = (i + 1) % key_len) {

		std::cout.put(ch ^ key[i]);
	}




	return 0;

}