#include <string>
#include <cctype>
#include <iostream>

std::string removeLeadingSpaces(std::string line)
{
    std::string newString = "";
    int count = 0;
    while(isspace(line[count]))
        ++count;
    for (int i = count; i < line.size(); ++i)
        newString += line[i];
    return newString;
}

int countChar(std::string line, char c)
{
    int count = 0;
    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] == c)
            ++count;
    }
    return count;
}

