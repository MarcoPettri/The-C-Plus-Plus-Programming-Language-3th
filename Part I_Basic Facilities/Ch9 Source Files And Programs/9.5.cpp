// Exercise 9.5
/*
		An external include guard is a construct that tests outside the file it is guarding and 
		includes it only once per compilation. Define such a construct, devise a way of testing it, 
		and discuss its advantages and disadvantages compared to the include guards described 
		in &9.3.3. Is there any significant run-time advantage to external #include guards on 
		your system? 


*/

#ifndef FILE_HPP
#define FILE_HPP

#include <file.hpp>

#endif // !FILE_HPP
