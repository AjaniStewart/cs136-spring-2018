/*
Author: Ajani Stewart
Course: CSCI-133
Instructor: Professor Zamansky
Assignment: Lab2D

 This program uses an array of ints to compute and print
 all Fibonacci numbers from F(0) to F(59).
*/

#include <iostream>

void fib()
{
	int fib[60];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < 60; ++i)
		fib[i] = fib[i-1] + fib[i-2];

	for (int i = 0; i < 60; ++i)
		std::cout << fib[i] << "\n";
	/*The fibonacci numbers get extremely big
	the biggest number that a signed int (on my computer) can hold is 2^31 - 1
	As a result, the largest number it can hold is fib[46]
	which is 1836311903
	Afterwards, integer overflow occurs	
	*/
}

int main()
{
	fib();
}