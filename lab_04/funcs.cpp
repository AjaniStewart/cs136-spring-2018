#include <string>
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
    for (int height = 1; height < size + 1 ; ++height)
    {
        for (int width = 0; width < size + 1; ++width)
            if (height == width || width + height == size + 1)
                str.append("*");
            else
                str.append(" ");
        str.append("\n");
    }
    return str;
}

std::string lower(int length)
{
    std::string str = "";
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
            str.append("*");
        str.append("\n");
    }
    return str;
}

std::string upper(int length)
{
    std::string str = "";
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < i; ++j)
            str.append(" ");
        for (int k = i; k < length; ++k)
            str.append("*");
        str.append("\n");
    }
    return str;
}

std::string trapezoid(int width, int height)
{
    if (height * 2 > width) return "";

    std::string str = "";
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < i; ++j)
            str.append(" ");
        for (int k = i; k < width - i; ++k)
            str.append("*");

        str.append("\n");
    }
    return str;
}