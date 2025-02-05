#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "Vector_Handler.h"

const int ERROR_EMPTY_VECTOR = 1;

const std::string MESSAGE_ERROR_EMPTY_VECTOR = "You have not entered any value!";

int main()
{
	std::vector <double> numbers;
	int errorCode;

	numbers = ReadVector(numbers, std::cin);

	if (numbers.empty())
	{
		std::cout << MESSAGE_ERROR_EMPTY_VECTOR << std::endl;
		return ERROR_EMPTY_VECTOR;
	}

	double min = *min_element(numbers.begin(), numbers.end());

	numbers = ProcessVector(numbers, min);

	std::sort(std::begin(numbers), std::end(numbers));

	PrintVector(numbers);

	return 0;
}