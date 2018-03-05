#include <iostream> // for cin
#include <sstream> //to convert from string to ints
#include <string> //for string type


int main()
{
    //declare and initialize variables
    std::string s;
    int sum = 0, num;
    //while there is stuff to read
    while (std::cin >> s)
    {
        //use a string stream to convert it from a string to an int
        std::istringstream iss(s);
        //stream that int to num
        iss >> num;
        //add num to sum
        sum += num;
    }
    //print the output
    std::cout << sum << std::endl;
}