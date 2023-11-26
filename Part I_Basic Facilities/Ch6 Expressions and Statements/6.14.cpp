// Exercise 6.14
/*

		 Write a function rev() that takes a string argument and reverses the characters in it. That
		 is, after rev(pp) the last character of pp will be the first, etc.
*/

#include<iostream>
#include<string>

typedef std::string string;
typedef std::string::iterator iter;
typedef std::string::reverse_iterator r_iter;

void rev(string&);


int main()
{
	string str{ "Marco" };
	string str2{ "Reversed" };

	rev(str);
	rev(str2);

	std::cout << str << '\n' << str2;
	return 0;
}
void rev(string& arg)
{
	iter beg{ arg.begin() };

	r_iter rbeg{ arg.rbegin() };

	iter middle{ beg + (arg.end() - beg) / 2 };

	while (beg != middle) {
		char temp{ *beg };
		*beg = *rbeg;
		*rbeg = temp;

		++beg, ++rbeg;
	}
}