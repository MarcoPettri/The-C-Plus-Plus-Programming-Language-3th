// Exercise 7.4
/*
	write a program that reads an arbitrary number of files whose names are given as
	command-line arguments and writes them one after another on cout. Because this program
	concatenates its arguments to produce its output, you might call it cat.

*/

#include<iostream>
#include<fstream>

void cat_stream(std::istream& input);

int main(int argc, char* argv[]) {
	
	if (argc > 1) {
		for (int i{ 1 }; i != argc; ++i) {
			std::ifstream  infile(argv[i] );

			cat_stream(infile);


		}
	}
	else {
		cat_stream(std::cin);
	}
}



void cat_stream(std::istream& input) 
{
	char ch;
	while (input.get(ch)) {
		std::cout.put(ch);
	}
}


