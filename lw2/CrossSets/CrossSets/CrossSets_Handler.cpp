#include "CrossSets_Handler.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <cctype>

const char MINUS = '-';
const char DELIMITER[] = " ";

const std::string MESSAGE_ERROR_NO_PARAMETER = "The input number is not entered!";
const std::string MESSAGE_ERROR_NEGATIVE = "A negative number is entered!";
const std::string MESSAGE_ERROR_NOT_DIGIT = "Entered not a digit!";
const std::string MESSAGE_RULE = "The rule of entry is - CrossSets.exe <number>";
const std::string INTERSECTION = "Intersection: ";

const int FIRST_CHAR = 0;
const int BASE = 10;
const int EVEN_DIGIT_SUM = 2;
const int DIGIT_PARAMETER = 1;

const int ERROR_NO_PARAMETER = 2;
const int ERROR_NEGATIVE = 3;
const int ERROR_NOT_DIGIT = 4;

int GetError(int argc, char* argv[], int& n)
{
	if (argc <= DIGIT_PARAMETER)
	{
		std::cout << MESSAGE_ERROR_NO_PARAMETER << std::endl;
		std::cout << MESSAGE_RULE << std::endl;
		std::cout << std::endl;
		return ERROR_NO_PARAMETER;
	}

	std::string nStr = argv[DIGIT_PARAMETER];

	if (nStr[FIRST_CHAR] == MINUS)
	{
		std::cout << MESSAGE_ERROR_NEGATIVE << std::endl;
		std::cout << MESSAGE_RULE << std::endl;
		std::cout << std::endl;
		return ERROR_NEGATIVE;
	}

	for (char ch : nStr)
	{
		if (!std::isdigit(ch))
		{
			std::cout << MESSAGE_ERROR_NOT_DIGIT << std::endl;
			std::cout << MESSAGE_RULE << std::endl;
			std::cout << std::endl;
			return ERROR_NOT_DIGIT;
		}
	}

	n = std::stoi(nStr);

	return 0;
}


int SumOfDigits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % BASE;
		n /= BASE;
	}
	return sum;
}

std::set<int> CreateDivSumSet(int n)
{
	std::set<int> divSumSet;
	for (int i = 1; i <= n; i++)
	{
		if (i % SumOfDigits(i) == 0)
			divSumSet.insert(i);
	}
	return divSumSet;
}

std::set<int> CreateEvenSumSet(int n)
{
	std::set<int> evenSumSet;
	for (int i = 1; i <= n; i++)
	{
		if (SumOfDigits(i) % EVEN_DIGIT_SUM == 0)
			evenSumSet.insert(i);
	}
	return evenSumSet;
}

std::set<int> CrossSet(std::set<int> const& divDigitSumSet, std::set<int> const& evenDigitSumSet)
{
	std::set<int> resultSet;
	std::set_intersection(divDigitSumSet.begin(), divDigitSumSet.end(), evenDigitSumSet.begin(), evenDigitSumSet.end(), std::inserter(resultSet, resultSet.begin()));
	return resultSet;
}

void PrintSets(std::set<int> const& divSumSet, std::set<int> const& evenSumSet)
{
	std::set<int> intersectionSet = CrossSet(divSumSet, evenSumSet);
	std::cout << INTERSECTION;
	std::copy(intersectionSet.begin(), intersectionSet.end(), std::ostream_iterator<int>(std::cout, DELIMITER));
}