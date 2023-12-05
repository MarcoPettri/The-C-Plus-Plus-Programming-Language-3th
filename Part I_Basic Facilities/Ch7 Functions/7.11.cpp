// Exercise 7. 11
/*
		write an error function that takes a printf-style format string containing %s, %c, and
		%d directives and an arbitrary number of arguments. Don't use printf(). Look at &21.8
		if you don't know the meaning of %s, %c, and %d. Use <cstdarg>.

*/

#include<iostream>
#include<cstdarg>
#include<stdexcept>

static void error(char const* fmt, ...) {
	
	if (!fmt) { return; }

	std::va_list list;
	va_start(list, fmt);

	for (char const* str = fmt; *str; ++str) {

		if (*str != '%') { std::cerr.put(*str); }
		else {
			switch (*(++str)) {

			case '%':
				std::cerr.put(*str); break;

			case 's':
				std::cerr << va_arg(list, char const*); break;

			case 'd':
			case 'i':
				std::cerr << va_arg(list, int); break;		

			case 'u':
				std::cerr << va_arg(list, unsigned); break;

			case 'c':
				std::cerr << va_arg(list, char); break;
			
			case 'f':
			case 'F':
				std::cerr << va_arg(list, float); break;

			default:
				throw std::invalid_argument("Invalid Specifier");
			}
		}
	}

}

