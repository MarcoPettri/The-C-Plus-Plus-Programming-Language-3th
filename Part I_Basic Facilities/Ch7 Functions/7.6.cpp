// Exerciser 7.6
/*

	Implement ssort() (§7.7) using a more efficient sorting algorithm. Hint: qsort().

*/


#include<cstdlib>


typedef int (*CFT)(void const*, void const*);


void ssort(void* base, std::size_t n, std::size_t sz, CFT cmp) {
	std::qsort(base, n, sz, cmp);
}