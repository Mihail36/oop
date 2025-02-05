#include "Vector_Handler.h"
#include <algorithm>
#include <iostream>
#include <iterator>

std::vector <double> ReadVector(std::vector<double>& numbers, std::istream& input)
{
	double number;
	while (input >> number)
		numbers.push_back(number);
	return numbers;
}
std::vector <double> ProcessVector(std::vector <double>& numbers, double min)
{
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [=](double number) { return (number * min); });
	return numbers;
}
void PrintVector(const std::vector<double>& numbers)
{
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout, " "));
	std::cout << std::endl;
}