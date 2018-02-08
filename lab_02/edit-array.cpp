/*
Author: Ajani Stewart
Course: CSCI-133
Instructor: Professor Zamansky
Assignment: Lab2C

This progam creates an array of 10 integers, and provides 
the user with an interface to edit any of its elements.
*/

#include <iostream>

//Janky solution
void edit_array()
{
	int myData[10];
	for (int i = 0; i < 10; ++i)
	{
		myData[i] = 1;
		std::cout << myData[i] << ' ';
	}
	std::cout << '\n';
	int i;
	do
	{
		std::cout << "Input index: ";
		// int i;
		std::cin >> i;

		std::cout << "Input value: ";
		int v;
		std::cin >> v;

		if (i > 9 || i < 0)
		{
			std::cout << "Index out of range. Exit.\n";
			continue;
		}

		myData[i] = v;
		for (int j = 0; j < 10; ++j)
			std::cout << myData[j] << ' ';
		std::cout << '\n';
	} while (i >= 0 && 10 > i);
}

int main()
{
	edit_array();
}
