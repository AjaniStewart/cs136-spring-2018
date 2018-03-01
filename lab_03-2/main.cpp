#include <iostream>
#include <fstream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"

int main()
{
    std::cout << east_storage("09/13/2016") << std::endl;
	std::cout << "minimum: " << mineast() << std::endl;
	std::cout << "maximum: " << maxeast() << std::endl;
	std::cout << compare("09/13/2016", "09/16/2016");
	std::cout << reverse_order("05/29/2016","06/02/2016");
	return 0;
}
