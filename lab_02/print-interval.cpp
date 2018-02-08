/*
Author: Ajani Stewart
Course: CSCI-133
Instructor: Professor Zamansky
Assignment: Lab2B

Prints all integers in a specified range
*/

#include <iostream>

void print_interval(int L, int U)
{
	for (int i = L; i < U; ++i)
		std::cout << i << ' ';
	std::cout << '\n';
}

int main()
{
	std::cout << "Internal from -5 to 5\n";
	print_interval(-5,5);
	return 0;
}