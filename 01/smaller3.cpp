/*
Author: Ajani Stewart
Course: CSCI-133
Instructor: Professor Zamansky
Assignment: Lab1B

Prints the smallest of 3 numbers
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

	std::cout << "Enter the third number: ";
	int z;
	std::cin >> z;

	int smallest = ((x > y ? y : x) > z ? z : (x > y ? y : x));
	std::cout << "\n\n\n";

	std::cout << "The smaller of the three is " << smallest << '\n';
	return 0;
}