#include <iostream>
#include <string>

void printRange(int left, int right)
{
    if (right == left)
        std::cout << left << " ";
    else
    {
        std::cout << left << " ";
        printRange(left+1,right);
    }       
}

int sumRange(int left, int right)
{
    if (right == left)
        return right;
    return sumRange(left+1,right)+left;
}

int sumArray(int *arr, int size)
{
    if (size == 0)
        return 0;
    return sumArray(arr,size-1)+arr[size-1];
}

bool isAlphanumeric(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

bool isAlphanumeric(std::string s)
{
    if (s == "") return true;
    return isAlphanumeric(s[0]) && isAlphanumeric(s.substr(1,s.size()));
}

bool nestedParens(std::string s)
{
    if (s == "") return true;
    return (s[0] == '(' && s[s.size()-1] == ')' && nestedParens(s.substr(1,s.size()-2)));
}

bool divisible(int *prices, int size)
{
    if (size == 2) return prices[0] == prices[1];
}