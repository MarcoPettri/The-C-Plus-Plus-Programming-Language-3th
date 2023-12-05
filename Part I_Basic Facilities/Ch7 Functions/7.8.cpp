// Exercise 7.8
/*
	Write a function to invert a two-dimensional array. Hint: &C.7.

*/

#include<iostream>
#include<array>
#include<cstdlib>

std::size_t const ROW = 12;
std::size_t const COLUMN = 6;

void invert(int[ROW][COLUMN]);

std::ostream& operator<<(std::ostream&, int const[ROW][COLUMN]);

int main()
{


    int arr2d[ROW][COLUMN] = {
        { 0,  1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10, 11},
        {12, 13, 14, 15, 16, 17},
        {18, 19, 20, 21, 22, 23},
        {24, 25, 26, 27, 28, 29},
        {30, 31, 32, 33, 34, 35},
        {36, 37, 38, 39, 40, 41},
        {42, 43, 44, 45, 46, 47},
        {48, 49, 50, 51, 52, 53},
        {54, 55, 56, 57, 58, 59},
        {60, 61, 62, 63, 64, 65},
        {66, 67, 68, 69, 70, 71}
    };
	
    
    std::cout << "Original 2D-array\n" << arr2d;
    invert(arr2d);
    std::cout << "\nTransposed 2D-array\n" <<  arr2d;

    

	return 0;
}
void invert(int arr2d[ROW][COLUMN])
{

    int* beg = &arr2d[0][0];
    int* rbeg = &arr2d[ROW - 1][COLUMN - 1];

    int* middle = beg + (rbeg - beg) / 2;

    while (beg != middle) {
        int temp{ *beg };
        *beg = *rbeg;
        *rbeg = temp;
        ++beg, --rbeg;
    }

   
}
std::ostream& operator<<(std::ostream& out, int const rhs[ROW][COLUMN])
{
    for (std::size_t rc = 0, end = ROW * COLUMN; rc != end;) {

        std::size_t r = rc / COLUMN;
        std::size_t c = rc % COLUMN;

        out.width(2);
        out << rhs[r][c] << (!(++rc % COLUMN) ? "\n" : ", ");
    }

    return out;
}