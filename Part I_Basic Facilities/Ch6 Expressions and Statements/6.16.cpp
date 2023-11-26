// Exercise 6.16
/*
        Write a function atoi(const char*) that takes a string containing digits and returns the
        corresponding int. For example, atoi("123") is 123. Modify atoi() to handle C++ octal and
        hexadecimal notation in addition to plain decimal numbers. Modify atoi() to handle the C++
        character constant notation.

*/

#include<iostream>
#include<cmath>
#include<stdexcept>

//Start Namespace Global
namespace Global {

    int atoi(char const*);
}// END Namespace Global

int main() {


    const char* dec{ "123" };
    const char* oct{ "0173" }; // 123 in decimal
    const char* hex{ "X7B" }; // 123 in decimal

    


    int dec_by_two{ Global::atoi(dec) * 2};
    int oct_by_two{ Global::atoi(oct) * 2};
    int hex_by_two{ Global::atoi(hex) * 2};

    std::cout << dec_by_two << " = " 
        << oct_by_two << " = " 
        << hex_by_two << std::endl;


    return 0;
}


// Start Namespace Global
namespace Global {

    int atoi(char const* arg) {

        /* (47, 58) = [48, 57] = {0, 1, 2, ..., 9} */
        int min_numeric{ 47 };
        int max_numeric{ 58 };
        /* (64, 71) = [65, 70] = {A, B, C, D, E, F} */
        int min_alph{ 64 };
        int max_alph{ 71 };

        int base{ 10 }; // default
        int exp{ -1 }; // the last character must be raised to 10^0 
        int num{ 0 };

        if (*arg == 'X' || *arg == 'x') { base = 16;  ++arg; }
        else if (*arg == '0') { base = 8; ++arg; }

        while (arg[++exp + 1]);

        for (; exp != -1; --exp, ++arg) {

            int ascii_val{ static_cast<int>(*arg) };// get int value of ASCII-based character set
            int subtrahend;

            if (min_numeric < ascii_val && ascii_val < max_numeric) {
                // if 48 = '0', then 48 - 48 =  0; 49 = '1', so 49 - 48 = 1.. etc.
                subtrahend = 48;
            }
            else if (min_alph < ascii_val && ascii_val < max_alph) {
                // if 65 = 'A', then 65 - 55 = 10; 66 = 'B', so 66 - 55 = 11.. etc.
                subtrahend = 55;
            }
            else {

                char excep[19]{ "invalid literal: " };
                excep[18] = *arg;

                throw std::invalid_argument(excep);
            }
            num += (ascii_val - subtrahend) * std::pow(base, exp);

        }

        return num;
}

} // END Namespace Global