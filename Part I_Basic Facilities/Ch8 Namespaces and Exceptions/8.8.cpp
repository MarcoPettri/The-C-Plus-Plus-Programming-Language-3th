// Exercise 8.8
/*


	Write a function that either returns a value or throws that value based on an argument. 
	Measure the difference in run-time between the two ways. 
*/


#include<iostream>
#include<ctime>


static inline int func_throw(int num)
{

	if (!num) { throw num; }

	return num * num;
}

int main() 
{
	unsigned long return_cnt = 0UL;
	std::clock_t end = std::clock() + 5 * CLOCKS_PER_SEC;


	for (int dummy; std::clock() < end; ++return_cnt) { dummy = func_throw(1); }

	std::cout << "Plain Return: " << return_cnt / 5 
		<< " Times Per Second " << std::endl;

	
	for (end = std::clock() + 5 * CLOCKS_PER_SEC, return_cnt = 0UL; 
			std::clock() < end;) {

		try { func_throw(0); }

		catch (...) { ++return_cnt; }
	}

	std::cout << "Thrown Return: " << return_cnt / 5
		<< " Times Per Second" << std::endl; 

	return 0;
}