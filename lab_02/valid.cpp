/*
Author: Ajani Stewart
Course: CSCI-133
Instructor: Professor Zamansky
Assignment: Lab2A

The program asks the user to input an integer in the range 0 < n < 100. 
If the number is out of range, the program asks to re-enter until a valid number is input.
After a valid value is obtained,the print square of the number is printed.
*/

#include <iostream>

int main()
{
	std::cout << "Please enter an integer: ";
	int num;
	std::cin >> num;
	while(num <= 0 || num >= 100 || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Please re-enter: ";
		std::cin >> num;
	}
	std::cout << "The number squared is " << num * num << '\n';
}
