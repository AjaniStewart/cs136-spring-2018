#pragma once
#include <string>
#include <fstream>

double east_storage(const std::string &dateIn);
double mineast();
double maxeast();
std::string compare(const std::string &dateStart, const std::string &dateEnd);
std::string reverse_order(const std::string &dateStart, const std::string &dateEnd);