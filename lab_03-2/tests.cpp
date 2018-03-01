#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"

TEST_CASE("Testing East Storage"){
	std::cout << "East Storage\n";
	CHECK(east_storage("01/02/2016")==71.97);
	CHECK(east_storage("01/01/2016")==71.99);
	CHECK(east_storage("12/31/2016")==58.12);
	CHECK(east_storage("01/02/2017")==0.0);
	CHECK(east_storage("")==0.0);
}

TEST_CASE("Testing Minimum East") {
	std::cout <<"\nMinimum East\n";
	CHECK(mineast()==49.34);
}

TEST_CASE("Testing Maximum East") {
	std::cout << "\nMaximum East\n";
	CHECK(maxeast()==81.0);
}

TEST_CASE("Testing Compare") {
	std::cout << "\nCompare\n";
	std::string ans = "09/13/2016 East\n09/14/2016 East\n09/15/2016 Equal\n09/16/2016 West\n09/17/2016 West\n";
	CHECK(compare("09/13/2016", "09/17/2016")==ans);
}

TEST_CASE("Testing Reverse Code") {
	std::cout << "\nReverse Code\n";
	std::string ans = "06/02/2016  587.66 ft\n06/01/2016  587.81 ft\n05/31/2016  587.93 ft\n05/30/2016  588.02 ft\n05/29/2016  588.17 ft";
	CHECK(reverse_order("05/29/2016","06/02/2016")==ans);
}



