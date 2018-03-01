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
    return 0;
}