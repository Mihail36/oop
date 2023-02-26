#include <iostream>
#include <limits>
#include <fstream>
#include <windows.h>
#include <cmath>
#include <string>

const int ERROR_FILE_NOT_ENTERED = 1;
const int ERROR_NUMBER_NOT_ENTERED = 2;
const int ERROR_OUT_OF_RANGE = 3;
const int ERROR_UNCORRECT_NUMBER = 4;

const int FILE_PARAMETER = 1;

const int MAX_STRING_SIZE = 32;

const char LINE_BREAK[3] = "\n";

const std::string MESSAGE_NUMBER_NOT_ENTERED = "Error: Number not entered!\n";
const std::string MESSAGE_OUT_OF_RANGE = "Error: Out of range!\n";
const std::string MESSAGE_UNCORRECT_NUMBER = "Error: Not a digit or not a bin digit!\n";
const std::string MESSAGE_FILE_NOT_ENTERED = "Error: File isn't entered!\n";

int main(int argc, char* argv[])
{
	if (argv[FILE_PARAMETER] == NULL)
	{
		std::cout << MESSAGE_FILE_NOT_ENTERED;
		return ERROR_FILE_NOT_ENTERED;
	}

	std::ifstream decFile(argv[FILE_PARAMETER]);
	std::string inputStr;
	double decFromBin = 0;
	getline(decFile, inputStr);
	if (inputStr == "")
	{
		std::cout << MESSAGE_NUMBER_NOT_ENTERED;
		return ERROR_NUMBER_NOT_ENTERED;
	}
	if (inputStr.size() >= MAX_STRING_SIZE)
	{
		std::cout << MESSAGE_OUT_OF_RANGE;
		return ERROR_OUT_OF_RANGE;
	}
	
	reverse(inputStr.begin(), inputStr.end());
	int sizeStr = inputStr.size();
	for (int i = 0; i < sizeStr; i++)
	{
		if (inputStr[i] == '0' || inputStr[i] == '1')
		{
			if (inputStr[i] == '1')
				decFromBin = decFromBin + pow(2, i);
		}
		else
		{
			std::cout << MESSAGE_UNCORRECT_NUMBER;
			return ERROR_UNCORRECT_NUMBER;
		}
	}
	std::cout << decFromBin << LINE_BREAK;
	return 0;
}