// Exercise 6.17
/*

		Write a function itoa(int i, char b[]) that creates a string representation of i in b and
		returns b
*/


#include<iostream>
#include<stdexcept>


//Start Namespace Global
namespace Global {
	char* itoa(int, char[]);

} // END Namespace Global


int main()
{
	char num[4]{'0', '0', '0'};
	int number{ 123 };

	Global::itoa(number, num);

	std::cout << num;

	return 0;
}

//Start Namespace Global
namespace Global {

	char* itoa(int i, char b[]) {

		int index{ 0 };

		while (i) {
			/* 
				// 48 = 0 in ASCII character set,
				// so for example 123 % 10 = 3 -> 3 + 48 = 53 = '3' in ASCII character set
			 */
			b[index++] = static_cast<char>(48 + i % 10);
			i /= 10;
		}
		
		// As the number is stored in reverse order, they must be reversed. 
		char* beg = &b[0];
		char* rbeg = &b[--index]; // last character digit 

		char* middle = beg + (rbeg - beg) / 2;

		while (beg != middle) {
			char temp{ *beg };
			*beg = *rbeg;
			*rbeg = temp;

			++beg, --rbeg;
		}
		return b;
	}

} // END Namespace Global