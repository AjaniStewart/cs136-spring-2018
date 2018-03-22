#include "funcs.h"
#include <iostream>

int main()
{
    testascii("Hello, World!");
    std::cout << "CAESAR: Hello, World! = " << encryptCaesar("Hello, World!", 10) << "\n";
    std::cout << "VIGENER: Hello, World! = " << encryptVigenere("Hello, World!", "cake") << '\n';
}