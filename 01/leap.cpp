/*
Author: Ajani Stewart
Course: CSCI-133
Instructor: Professor Zamansky
Assignment: Lab 1C

Determines whether or not a given year is a leap year.
*/

#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Enter year: ";
	int year;
	std::cin >> year;

	bool leap;

	if (year % 4 == 0 && (year % 100 != 0  || year % 400 == 0))
		leap = true;
	else
		leap = false;

	if (leap)
		std::cout << "Leap year\n";
	else
		std::cout << "Common year\n";

	return 0;
}