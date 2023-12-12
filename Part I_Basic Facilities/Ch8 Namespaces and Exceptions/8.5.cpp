// Exercise 8.5 

/*

		Write a program consisting of functions calling each other to a calling depth of 10. Give 
		each function an argument that determines at which level an exception is thrown. Have 
		main() catch these exceptions and print out which exception is caught. Don’t forget the 
		case in which an exception is caught in the function that throws it.
*/

#include<iostream>
#include<cstdlib>

namespace {

	inline static void func(int throw_lev,int level = 0) 
	{
		return (throw_lev == level ? throw level : func2(throw_lev, ++level));
	}	

	inline static void func2(int throw_lev, int level) 
	{
		return (throw_lev == level ? throw level : func3(throw_lev, ++level)); 
	}

	inline static void func3(int throw_lev, int level) 
	{
		return (throw_lev == level ? throw level : func4(throw_lev, ++level));

	}

	inline static void func4(int throw_lev, int level)
	{
		return (throw_lev == level ? throw level : func5(throw_lev, ++level));
		
	}

	inline static void func5(int& throw_lev, int level) 
	{
		return (throw_lev == level ? throw level : func(throw_lev, ++level));

	}	

}

int main(int argc, char** argv) {

	try {
		if (argc < 2 || not std::atoi(argv[1])) {
			throw 0;
		}
		else {
			func(std::atoi(argv[1]));
		}
	}
	catch (int dep) {
		std::cout << "Caught level "
			<< dep << " exception" << std::endl;
	}

	return EXIT_SUCCESS;
}
