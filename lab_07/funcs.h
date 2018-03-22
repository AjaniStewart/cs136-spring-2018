#pragma once
#include <string>

void testascii(std::string str);
char shiftChar(char c, int rShift);
std::string encryptCaesar(std::string plaintext, int rShift);