// Exercise 5.10
/*

		Define an array of strings in which the strings contain the names of the months. Print those
		strings. Pass the array to a function that prints those strings
*/

#include<iostream>
#include<string>

int constexpr SIZE{ 12 };
void print(std::string const[SIZE]);

int main()
{

	std::string const strs[SIZE]{
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};

	print(strs);

}

void print(std::string const str[SIZE])
{
	for (int i {0 }; i != SIZE;) {

		std::cout << str[i] << (++i != SIZE ? ", " : "\n");
	}
}