#include <iostream> // for cin

int main()
{
    int result, num; //declare result, num
    char op; //math operator
    std::cin >> result; //stream first one 

    //stream into op and num
    while (std::cin >> op >> num)
    {   //add if op is '+'
        if (op == '+')
            result += num;
        else if (op == '-') 
            result -= num;
    }
    //print the result to std out
    std::cout << result << '\n';
    return 0;
}