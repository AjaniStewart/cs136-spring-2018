#include <iostream>
#include <fstream>
#include <string>
//#include <cstdlib>

using namespace std;
/*
	@param: date in mm/dd/yyyy format
	@return the storage in the east basin for that day
*/
double east_storage(const string &dateIn)
{
	ifstream f("Current_Reservoir_Levels.tsv");
	string junk, date;
	getline(f, junk);
	double eastSt, d1, d2, d3;
	while (f >> date >> eastSt >> d1 >> d2 >> d3)
		if (date == dateIn)
			return eastSt; 
	return 0.0;
}

/*
	@return the maximum storage in the east basin
*/
double maxeast()
{
	ifstream fin("Current_Reservoir_Levels.tsv");
	string junk, date;
	getline(fin, junk);
	double eastSt, eastEl, westSt, westEl;
	double max = -1.0;
	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
		if (eastSt > max)
			max = eastSt;
	return max;
}

/*
	@return the minumum storage in the east basin
*/
double mineast()
{
	ifstream fin("Current_Reservoir_Levels.tsv");
	string junk, date;
	getline(fin, junk);
	double eastSt, eastEl, westSt, westEl;
	double min = 1e9;
	while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
		if (eastSt < min)
			min = eastSt;
	return min;
}
/*
	@param the start and end date in mm/dd/yyyy format
	@return a string containing a date in the interval and
		which basin had the higher elevation on that day
*/

string compare(const std::string &dateStart, const std::string &dateEnd)
{
	string str = "";
	ifstream f("Current_Reservoir_Levels.tsv");
	string junk, date;
	getline(f, junk);
	double eastSt, eastEl, westSt, westEl;
	while (f >> date >> eastSt >> eastEl >> westSt >> westEl)
		if (date == dateStart)
		{
			str += date + " ";
			if (eastEl > westEl)
				str += "East\n";
			else if (eastEl < westEl)
				str += "West\n";
			else
				str += "Equal\n";
			break;
		}

	while (f >> date >> eastSt >> eastEl >> westSt >> westEl)
	{
		
		str += date + " ";
		if (eastEl > westEl)
			str += "East\n";
		else if (eastEl < westEl)
			str += "West\n";
		else
			str += "Equal\n";

		if (date == dateEnd)
			break;
	}
	return str;
}

/*
	@param the start and end date in mm/dd/yyyy format
	@return a string that reports the West basin elevation for 
		all days in the interval in the reverse chronological order 
*/
std::string reverse_order(const std::string &dateStart, const std::string &dateEnd)
{
	string str = "";

	ifstream f("Current_Reservoir_Levels.tsv");
	string junk, date, westEl;
	getline(f, junk);
	double eastSt, eastEl, westSt;
	string dates[365];
	while (f >> date >> eastSt >> eastEl >> westSt >> westEl)
		if (date == dateStart)
		{
			dates[0] = date + " " + westEl + " ft";
			break;
		}
	int count = 1;
	while (f >> date >> eastSt >> eastEl >> westSt >> westEl)
	{
		dates[count] = date + " " + westEl + " ft";
		if (date == dateEnd)
			break;
		++count;
	}

	for (int i = count; i >= 0; --i)
		str = str + dates[i] + "\n";


	return str;
}