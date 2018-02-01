/*
Author: Ajani Stewart
Course: CSCI-133
Instructor: Professor Zamansky
Assignment: Lab1D

Prints the number of days in a given month and year
*/

#include <iostream>

bool isLeap(int year)
{
	return year % 4 == 0 && (year % 100 != 0  || year % 400 == 0);
}

int main(int argc, char const *argv[])
{
	std::cout << "Enter year: ";
	int year;
	std::cin >> year;

	std::cout << "Enter month: ";
	int month;
	std::cin >> month;

	if (month == 1)
		std::cout << "31 days\n";
	else if (month == 2)
	{
		if (isLeap(year))
			std::cout << "29 days\n";
		else
			std::cout << "28 days\n";
	} else if (month == 3)
		std::cout << "31 days\n";
	else if (month == 4)
		std::cout << "30 days\n";
	else if (month == 5)
		std::cout << "31 days\n";
	else if (month == 6)
		std::cout << "30 days\n";
	else if (month == 7)
		std::cout << "31 days\n";
	else if (month == 8)
		std::cout << "31 days\n";
	else if (month == 9)
		std::cout << "30 days\n";
	else if (month == 10)
		std::cout << "31 days\n";
	else if (month == 11)
		std::cout << "30 days\n";
	else
		std::cout << "31 days\n";

	return 0;
}