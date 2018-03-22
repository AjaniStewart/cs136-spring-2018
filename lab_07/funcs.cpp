#include <string>
#include <iostream>

void testascii(std::string str)
{
    for (int i = 0, s = str.size(); i < s; ++i)
    {
        std::cout << str[i] << " " << static_cast<int>(str[i]) << std::endl;
    }
}

bool isLower(char c)
{
    return c >= 'a' && c <= 'z';
}

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
//for caesar
char shiftChar(char c, int rShift)
{
    int s;
    if (isLower(c))
        s = (((static_cast<int>(c) - 'a') + rShift) % 26) + 'a';
    else
        s = (((static_cast<int>(c) - 'A') + rShift) % 26) + 'A';
    return static_cast<char>(s);
}

std::string encryptCaesar(std::string plaintext, int rShift)
{
    std::string cipher = "";
    for (int i = 0, s = plaintext.size(); i < s; ++i)
    {
        //check if it is valid character
        if (isLetter(plaintext[i]))
            cipher += shiftChar(plaintext[i], rShift);
        else
            cipher += plaintext[i];
    }
    return cipher;
}

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
    std::string cipher = "";
    for (int i = 0, s = plaintext.size(); i < s; ++i)
    {
        if (isLetter(plaintext[i]))
        {
            char curKeyLetter = keyword[i % keyword.size()];
            int shift;
            if (isLower(curKeyLetter))
            {
                shift = static_cast<int>(curKeyLetter) - 'a';
            }
            else
            {
                shift = static_cast<int>(curKeyLetter) - 'A';
            }
            cipher += shiftChar(plaintext[i], shift);
        }
        else
            cipher += plaintext[i];
    }
    return cipher;
}