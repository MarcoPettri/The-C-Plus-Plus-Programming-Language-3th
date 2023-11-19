// Exercise 5.12
/*

	Write a function that counts the number of occurrences of a pair of letters in a string and
	another that does the same in a zero-terminated array of char (a C-style string). For example,
	the pair "ab" appears twice in "xabaacbaxabb".
*/


#include<iostream>
#include<string>

int ocurrences(const std::string&, const char[3]);
int ocurrences(char[], char[3]);

int main()
{
	std::string str1{ "xabaacbaxabb" };
	char str2[]{ "xabaacb-axabbxab" };


	std::cout << "Target: " << "ab"
		<< "\nString: " << str1
		<< "\nOccurrences: " << ocurrences(str1, "ab") << std::endl;

	std::cout << "\nTarget: " << "xa"
		<< "\nString: " << str2
		<< "\nOccurrences: " << ocurrences(str2, "xa") << std::endl;;




	return 0;
}

int ocurrences(const std::string& str, const char occ[3]) {

	int count{ 0 };

	if (str.empty()) { return count; }

	for (auto it{ str.cbegin()}; it != str.cend();) {

		bool first{ *it == occ[0]};

		if (++it != str.cend()) {
			bool second{ *it == occ[1] };
			if (first && second) { ++count; }
		}

	}
	return count;
}

int ocurrences(char str[], char occ[3]) {

	int size{ 0 };
	int count{ 0 };

	while (str[size] != '\0') { ++size; }

	if (size) {
		for (int i{ 0 }; i < size;) {

			bool first{ str[i]  == occ[0]};
			
			if (++i < size) {
				bool second{ str[i] == occ[1] };

				if (first && second) { ++count; }
			}
		}

	}

	return count;
}