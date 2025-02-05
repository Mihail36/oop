#include <iostream>
#include <limits>
#include <fstream>
#include <windows.h>
#include <cmath>
#include <string>

const char RUSSIAN_LANGUAGE[8] = "Russian";
const int RUSSIAN_ENCODING = 1251;

const int ERROR_OUT_OF_RANGE = 2;
const int ERROR_UNCORRECT_BIN = 3;

const int NUMBER_PARAMETER = 1;

const int MAX_STRING_SIZE = 32;

const std::string MESSAGE_ERROR = "Error: ";
const std::string MESSAGE_NUMBER_NOT_ENTERED = "Number isn't entered!\n";
const std::string MESSAGE_OUT_OF_RANGE = "Out of range!\n";
const std::string MESSAGE_UNCORRECT_BIN = " isn't a 0 or 1!\n";
const std::string MESSAGE_EXAMPLE_INPUT = "Example of input: bin2dec.exe <число в двоичной системе>\n";

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	SetConsoleCP(RUSSIAN_ENCODING);
	SetConsoleOutputCP(RUSSIAN_ENCODING);

	if (argv[NUMBER_PARAMETER] == NULL)
	{
		std::cout << MESSAGE_ERROR << MESSAGE_NUMBER_NOT_ENTERED;
		std::cout << MESSAGE_EXAMPLE_INPUT;
		return 1;
	}

	std::string inputStr(argv[NUMBER_PARAMETER]);
	int decFromBin = 0;;
	if (inputStr.size() >= MAX_STRING_SIZE)
	{
		std::cout << MESSAGE_ERROR << MESSAGE_OUT_OF_RANGE;
		std::cout << MESSAGE_EXAMPLE_INPUT;
		return ERROR_OUT_OF_RANGE;
	}
	
	reverse(inputStr.begin(), inputStr.end());
	int sizeStr = inputStr.size();
	int levelTwo;
	for (int i = 0; i < sizeStr; i++)
	{
		if (inputStr[i] == '0' || inputStr[i] == '1')
		{
			if (inputStr[i] == '1')
			{
				levelTwo = 1 << i;
				decFromBin = decFromBin + levelTwo;
			}
		}
		else
		{
			std::cout << MESSAGE_ERROR << inputStr[i] << MESSAGE_UNCORRECT_BIN;
			std::cout << MESSAGE_EXAMPLE_INPUT;
			return ERROR_UNCORRECT_BIN;
		}
	}

	std::cout << decFromBin << std::endl;
	return 0;