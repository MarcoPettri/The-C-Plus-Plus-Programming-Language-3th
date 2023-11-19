// Exercise 5.11
/*

	 Read a sequence of words from input. Use Quit as a word that terminates the input. Print
	the words in the order they were entered. Don't print a word twice. Modify the program to sort
	the words before printing them.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main()
{	
	std::string str;
	std::vector<std::string> words;
	std::cout << "Enter the words (Quit to exit)-> ";

	while (std::cin >> str && str != "Quit") {
		
		if (std::find(words.cbegin(),
			words.cend(), str) == words.cend()) {

			words.push_back(str);
		}
		std::cout << "\n-> ";
	}
	
	std::cout << "Words: ";
	for (auto const& word : words) {
		std::cout << word << " ";
	}	
	std::cout << std::endl;
	
	std::sort(words.begin(), words.end());

	std::cout << "Sorted words: ";
	for (auto const& word : words) {
		std::cout << word << " ";
	}

	
	std::cout << std::endl;
	
	return 0;
}