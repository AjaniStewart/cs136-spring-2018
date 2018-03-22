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

std::string encryptCaesar(std::string plainText, int rShift)
{
    std::string cipher = "";
    for (int i = 0, s = plainText.size(); i < s; ++i)
    {
        //check if it is valid character
        if (isLetter(plainText[i]))
            cipher += shiftChar(plainText[i], rShift);
        else
            cipher += plainText[i];
    }
    return cipher;
}

//for vigenere
char shiftChar(char c, char k)
{
    char r = ' ';
    return r;
}

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
    std::string cipher = "";
    return cipher;

}