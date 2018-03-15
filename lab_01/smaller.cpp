/*
Author: Ajani Stewart
Course: CSCI-133
Instructor: Professor Zamansky
Assignment: Lab1A

Finds the smaller of 2 numbers
*/

#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Enter the first number: ";
	int x;
	std::cin >> x;

	std::cout << "Enter the second number: ";
	int y;
	std::cin >> y;

	std::cout << "The smaller of the two is " << (x > y ? y : x) << '\n';
	return 0;
}