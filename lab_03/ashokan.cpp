#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

double east_storage(string dateIn)
{
	ifstream f("Current_Reservoir_Levels.tsv");
	string junk, date;
	getline(f, junk);
	double eastSt, d1, d2, d3;
	while (f >> date >> eastSt >> d1 >> d2 >> d3)
	{
		if (date == dateIn)
			return eastSt; 
	}
	return 0.0;
}


int main()
{
	cout << east_storage("02/05/2016"); //pls send help
	return 0;
}