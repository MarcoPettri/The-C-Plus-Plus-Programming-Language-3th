// Exercise 7.1
/*

		Write declarations for the following: a function taking arguments of type pointer to character 
		and reference to integer and returning no value; a pointer to such a function; a function taking such a pointer as an argument; and a function returning such a pointer. Write the definition
		of a function that takes such a pointer as an argument and returns its argument as the return
		value. Hint: Use typedef.
*/

void f(char*, int&);
typedef void (*FunctPTR)(char*, int&);

FunctPTR pf;

void f1(FunctPTR);
FunctPTR f2();

FunctPTR f3(FunctPTR arg) { return arg; }