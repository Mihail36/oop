#pragma once
#include <vector>
#include <iosfwd>

std::vector <double> ReadVector(std::vector <double>& numbers, std::istream& input);
std::vector <double> ProcessVector(std::vector <double>& numbers, double min);
void PrintVector(const std::vector<double>& numbers);