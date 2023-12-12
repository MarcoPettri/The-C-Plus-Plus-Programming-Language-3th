// Exercise 8.6
/*

	Modify the program from Exercise 8.5 to measure if there is a difference in the cost of 
	catching exceptions depending on where in a class stack the exception is thrown. Add a 
	string object to each function and measure again.
*/



#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

struct {
    int level = 0;
    unsigned long catch_cnt = 0UL;
    std::clock_t end = std::clock() + 5 * CLOCKS_PER_SEC;

    void reset() {
        level = 0;
        catch_cnt = 0UL;
        end = std::clock() + 5 * CLOCKS_PER_SEC;
    }
    
    void without_string(int throw_level) {

        if (throw_level == ++level){ throw level; }
           
        else { without_string(throw_level); }
    }

    void with_string(int throw_level) {

        std::string s;

        if (throw_level == ++level) { throw level; }

        else { with_string(throw_level); }
    }

    unsigned long get_time() const { return catch_cnt / 5; }


} benchmark;



int main() {


    int throw_level = 10;

    while (std::clock() < benchmark.end) {

        try {
            benchmark.without_string(throw_level);
        }
        catch (...) {
            ++benchmark.catch_cnt;
            benchmark.level = 0;
        }

    }

    std::cout << "Without string: " << benchmark.get_time()
        << " catches/second." << std::endl ;


    benchmark.reset();

    while (std::clock() < benchmark.end) {

        try {
            benchmark.with_string(throw_level);
        }
        catch (...) {
            ++benchmark.catch_cnt;
            benchmark.level = 0;
        }
    }

    std::cout << "With string: " << benchmark.get_time()
        << " catches/second." << std::endl;
    

    return EXIT_SUCCESS;
}
