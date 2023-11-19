// Exercise 5.13
/*
	Define a struct Date to keep track of dates. Provide functions that read Dates from
	input, write Dates to output, and initialize a Date with a date.
*/

#include<iostream>
#include<iomanip>


struct Date
{
	friend std::ostream& operator<<(std::ostream& out, const Date& rhs) {
		out << rhs.day << "-" << rhs.month << "-" << rhs.year;

		return out;
	}

	friend std::istream& operator>>(std::istream& input, Date& rhs) {
		input >> rhs.day;
		input.ignore();
		input >> rhs.month;
		input.ignore();
		input >> rhs.year;

		return input;
	}
public:
	Date(int dd, int mm, int yyyy) {
		day = dd;
		month = mm;
		year = yyyy;
	}
	Date(const Date& rhs) {
		day = rhs.day;
		month = rhs.month;
		year = rhs.year;
	}
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}

private:
	int day;
	int month;
	int year;
};


int main()
{


	Date date1{ 12,12,2012 };
	Date date2 = date1;
	Date date3;

	std::cout << "Date 1: " << date1 << std::endl;
	std::cout << "Date 2: " << date2 << std::endl;

	std::cout << "Enter date(dd-mm-yyyy): ",
		std::cin >> date3;

	std::cout << "Date 3: " << date3 << std::endl;


	
}