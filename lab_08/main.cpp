#include <iostream>
#include <string>
#include "funcs.h"

int main()
{
    std::string line;
    int openBraces = 0, closedBraces = 0;
    while(getline(std::cin,line))
    {
        line = removeLeadingSpaces(line);
        if (line[0] == '}') closedBraces += 1;
        for (int i = 0; i < openBraces - closedBraces; ++i)
            std::cout << "\t";
        std::cout << line << '\n';
        openBraces += countChar(line, '{');
        closedBraces += countChar(line, '}');
    }
}