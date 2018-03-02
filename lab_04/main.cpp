#include "funcs.h"
#include <iostream>
#include <string>

int main()
{   std::string s;

    std::cout << "Printing 7 x 4 box\n";
    s = box(7,4);
    std::cout << s;

    std::cout << "Printing 11 x 6 checkerboard\n";
    s = checkerboard(11,6);
    std::cout << s;

    std::cout << "Printing cross of size 8\n";
    s = cross(8);
    std::cout << s;

    std::cout << "Printing lower triangle of length 6\n";
    s = lower(6);
    std::cout << s;

    std::cout << "Printing upper triangle of length 6\n";
    s = upper(6);
    std::cout << s;

    std::cout << "Printing trapezoid of width 12 and height 5\n";
    s = trapezoid(12,5);
    std::cout << s;

    std::cout << "Printing trapezoid of width 12 and height 7 (impossible trapezioid)\n";
    s = trapezoid(12,7);
    std::cout << s;
    std::cout << "\n";
    return 0;
}