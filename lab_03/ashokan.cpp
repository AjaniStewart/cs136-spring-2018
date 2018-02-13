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
	double eastSt, d1, d2, d3, d4;
	while (f >> date >> eastSt >> d1 >> d2 >> d3 >> d4)
	{
		if (date == dateIn)
			return eastSt;
	}
	return 0.0;
}


int main()
{
	// string date, header;
	// double eastSt, eastEl, westSt, westEl;

	// ifstream fin("Current_Reservoir_Levels.tsv");
	// if (fin.fail())
	// {
	// 	cerr << "File cannot be opened for reading.\n";
	// 	exit(1);
	// }
	// //first line in tsv is the headers
	// getline(fin, header);
	// //while there is shit to read
	// // extract data from file and put it in the variables
	// while (fin >> date >> eastSt >> eastEl >> westSt /*>> westEl*/)
	// {
	// 	if (date == "12/31/2016")
	// 	{
	// 		cout << date << " " << eastSt << endl;
	// 		double help = eastSt;
	// 		cout << eastSt;
	// 	}
	// }
	// cout << '\n';
	cout << east_storage("/01/2016"); //pls send help
	return 0;
}