#include <string>
#include <iostream>

void testascii(std::string str)
{
    for (int i = 0, s = str.size(); i < s; ++i)
    {
        std::cout << str[i] << " " << static_cast<int>(str[i]) << std::endl;
    }
}

char shiftChar(char c, int rShift)
{
    int s;
    if (c >= 'a' && c <= 'z')
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
        if ((plainText[i] >= 'a' && plainText[i] <= 'z') || (plainText[i] >= 'A' && plainText[i] <= 'Z'))
            cipher += shiftChar(plainText[i], rShift);
        else
            cipher += plainText[i];
    }
    return cipher;
}
