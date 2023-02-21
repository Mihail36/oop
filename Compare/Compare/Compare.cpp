#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

const char RUSSIAN_LANGUAGE[8] = "Russian";
const int RUSSIAN_ENCODING = 1251;

const int ERROR_DIFFERENT_FILES = 1;
const int ERROR_NO_FILES = 2;
const int ERROR_NO_SECOND_FILE = 3;

const int FIRST_FILE_PARAMETER = 1;
const int SECOND_FILE_PARAMETER = 2;

const char LINE_BREAK[3] = "\n";

const std::string MESSAGE_NO_FILES = "No files entered!\n";
const std::string MESSAGE_NO_SECOND_FILE = "No second file!\n";
const std::string MESSAGE_EQUAL_FILES = "Files are equal\n";
const std::string MESSAGE_DIFFERENT_FILES = "Files are different. Line number is ";

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	SetConsoleCP(RUSSIAN_ENCODING);
	SetConsoleOutputCP(RUSSIAN_ENCODING);

	if (argv[FIRST_FILE_PARAMETER] == NULL)
	{
		std :: cout << MESSAGE_NO_FILES;
		return ERROR_NO_FILES;
	}
	if (argv[SECOND_FILE_PARAMETER] == NULL)
	{
		std:: cout << MESSAGE_NO_SECOND_FILE;
		return ERROR_NO_SECOND_FILE;
	}

	std:: ifstream inputFirstFile(argv[FIRST_FILE_PARAMETER]);
	std:: ifstream inputSecondFile(argv[SECOND_FILE_PARAMETER]);
	std:: string strFirstFile = "";
	std:: string strSecondFile = "";
	int countStr = 0;
	
	while (getline(inputFirstFile, strFirstFile))
	{
		if (getline(inputSecondFile, strSecondFile))
		{
			if (strFirstFile == strSecondFile)
				countStr++;
			else
			{
				countStr++;
				goto err;
			}
		}
		else
		{
			countStr++;
			goto err;
		}
	};

	if (!getline(inputFirstFile, strFirstFile))
	{
		if (getline(inputSecondFile, strSecondFile))
		{
			countStr++;
			goto err;
		}
	}

	std:: cout << MESSAGE_EQUAL_FILES;
	return 0;

err:
	std:: cout << MESSAGE_DIFFERENT_FILES << countStr << LINE_BREAK;
	return ERROR_DIFFERENT_FILES;

}