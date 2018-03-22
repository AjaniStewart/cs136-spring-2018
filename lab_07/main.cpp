#include "funcs.h"
#include <iostream>

int main()
{
    testascii("Hello, World!");
    std::cout << "Hello, World! = " << encryptCaesar("Hello, World!", 10) << "\n";
}