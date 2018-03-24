#include "funcs.h"
#include <iostream>

int main()
{
    testascii("Hello, World!");
    std::cout << "CAESAR: Hello, World! = " << encryptCaesar("Hello, World!", 10) << "\n";
    std::cout << "VIGENER: Hello, World! = " << encryptVigenere("Hello, World!", "cake") << '\n';
    std::cout << "CAESAR D: Success! " << decryptCaesar(encryptCaesar("Hello, World!", 10), 10) << "\n";
    std::cout << "VIGENERE D: hello, world! = " << decryptVigenere(encryptVigenere("hello, world!", "cake"),"cake") << "\n";
}