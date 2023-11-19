// Exercise 5.7
/*
		Define a table of the names of months of the year and the number of days in each month.
		Write out that table. Do this twice; once using an array of char for the names and an array for
		the number of days and once using an array of structures, with each structure holding the name
		of a month and the number of days in it.

*/

#include<iostream>
#include<ctime>



int numberOfDays(int);

struct Month
{	
	int  const  days;
	char const* name;

};


int main()
{

    int constexpr SIZE{ 12 };

	{

		char const* MONTHS[SIZE]{
			"January", "February", "March",
			"April", "May", "June",
			"July", "August", "September",
			"October", "November", "December"
		};

		int const DAYS[SIZE]{
            numberOfDays(1), 
            numberOfDays(2), 
            numberOfDays(3), 
            numberOfDays(4), 
            numberOfDays(5), 
            numberOfDays(6), 
            numberOfDays(7), 
            numberOfDays(8), 
            numberOfDays(9), 
            numberOfDays(10), 
            numberOfDays(11), 
            numberOfDays(12), 

		};

        for (int i{ 0 }; i < SIZE; ++i) {
            std::cout << MONTHS[i] << ": " << DAYS[i] << '\n';
        }
        std::cout << std::endl;
	}


    {
        Month const* MONTHS[SIZE]{
            new Month{ numberOfDays(1),  "January"},
            new Month{ numberOfDays(2),  "February"},
            new Month{ numberOfDays(3),  "March"},
            new Month{ numberOfDays(4),  "April"},
            new Month{ numberOfDays(5),  "May"},
            new Month{ numberOfDays(6),  "June"},
            new Month{ numberOfDays(7),  "July"},
            new Month{ numberOfDays(8),  "August"},
            new Month{ numberOfDays(9),  "September"},
            new Month{ numberOfDays(10), "October"},
            new Month{ numberOfDays(11), "November"},
            new Month{ numberOfDays(12), "December"},

        };

        for (int i{ 0 }; i < SIZE; ++i) {

            Month const* MOTNH{ MONTHS[i] };

            std::cout << MOTNH->name << ": " << MOTNH->days << '\n';
        }       

        for (int i{ 0 }; i < SIZE; ++i) {

            delete MONTHS[i];
        }
    }
}

int numberOfDays(int month)
{

    static std::time_t const t{ std::time(nullptr) };
    static std::tm *const pTInfo{ std::localtime(&t) };
    static int const      year{ pTInfo->tm_year };

    switch (month)
    {
    case 1: // January
    case 3: // March
    case 5: // May
    case 7: // July
    case 8: // August
    case 10: // October
    case 12: return 31; // December

    case 4: // April, 
    case 6: // June,
    case 9: // September
    case 11: return 30; // November

    case 2: // February 
        if (not(year % 400) || (not(year % 4) && (year % 100))) // leap
            return 29;

        else// non-leap
            return 28;

    default:
        return 0;
    }
}