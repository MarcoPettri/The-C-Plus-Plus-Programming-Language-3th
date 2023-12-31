// Exercise 7.3
/*

	Write a program like ''Hello, world!'' that takes a name as a command-line argument
	and writes ''Hello, name !''. Modify this program to take any number of names as arguments
	and to say hello to each.
*/

#include<iostream>

int main(int argc, char* argv[]) {

	if (argc > 1) {
		for (int i{ 1 }; i != argc; ++i) {
			std::cout << "Hello, " << argv[i] << " !\n";
		}
	}
	else {
		std::cerr << "No arguments" << std::endl;

	}

	return 0;
}