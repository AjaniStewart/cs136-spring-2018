#include <string>
#include <cmath>
std::string box(int width, int height)
{
    std::string str = "";
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            str.append("*");
        str.append("\n");
    }
    return str;
}

std::string checkerboard(int width, int height)
{
    std::string str = "";
    for (int rows = 0; rows < height; ++rows)
    {
        for (int cols = 0; cols < width; ++cols)
        {
            if ((rows + cols) % 2 == 0)
                str.append("*");
            else
                str.append(" ");
        }
        str.append("\n");
    }
    return str;
}

std::string cross(int size)
{
    std::string str = "";
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < i; ++j) //print leading whitespace
            str.append(" ");
        str.append("*");
        for (int k = i + 1; k < size - i); ++k)
            str.append(" ");
        str.append("*\n");
    }
    return str;
}