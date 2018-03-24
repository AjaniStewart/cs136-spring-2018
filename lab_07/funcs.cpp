#include <string>
#include <iostream>

void testascii(std::string str)
{
    for (int i = 0, s = str.size(); i < s; ++i)
        std::cout << str[i] << " " << static_cast<int>(str[i]) << std::endl;
}

//--------------------------Helper Functions-------------------------------------------
bool isLower(char c)
{
    return c >= 'a' && c <= 'z';
}

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char shiftChar(char c, int rShift)
{
    int s;
    if (isLower(c))
        s = (((static_cast<int>(c) - 'a') + rShift) % 26) + 'a';
    else
        s = (((static_cast<int>(c) - 'A') + rShift) % 26) + 'A';

    if (!isLetter(s))
        s += 26;
    else
        if (isLower(c) && !isLower(s))
            s += 26;

    return static_cast<char>(s);
}


//------------------------Encrypt functions------------------------------------------------


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
    int k = 0;
    for (int i = 0, s = plaintext.size(); i < s; ++i)
    {
        if (isLetter(plaintext[i]))
        {
            //to make sure the keyword repeats as many times as needed
            char curKeyLetter = keyword[k % keyword.size()];
            int shift;
            if (isLower(curKeyLetter))
                shift = static_cast<int>(curKeyLetter) - 'a';
            else
                shift = static_cast<int>(curKeyLetter) - 'A';
            cipher += shiftChar(plaintext[i], shift);
            ++k;
        }
        else
            cipher += plaintext[i];
    }
    return cipher;
}


//---------------------------Decrypt Functions------------------------------------
std::string decryptCaesar(std::string cipher, int rShift)
{
    return encryptCaesar(cipher, rShift * -1);
}

std::string decryptVigenere(std::string cipher, std::string keyword)
{
    std::string plaintext = "";
    int k = 0;
    for (int i = 0, s = cipher.size(); i < s; ++i)
    {
        if (isLetter(cipher[i]))
        {
            //to make sure the keyword repeats as many times as needed
            char curKeyLetter = keyword[k % keyword.size()];
            int shift;
            if (isLower(curKeyLetter))
                shift = static_cast<int>(curKeyLetter) - 'a';
            else
                shift = static_cast<int>(curKeyLetter) - 'A';
            plaintext += shiftChar(cipher[i], -1 * shift);
            ++k;
        }
        else
            plaintext += cipher[i];
    }
    return plaintext;
}