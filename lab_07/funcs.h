#pragma once
#include <string>

void testascii(std::string str);
char shiftChar(char c, int rShift);
std::string encryptCaesar(std::string plaintext, int rShift);
std::string encryptVigenere(std::string plaintext, std::string keyword);
bool isLower(char c);
bool isLetter(char c);
std::string decryptCaesar(std::string cipher, int rShift);
std::string decryptVigenere(std::string cipher, std::string keyword);