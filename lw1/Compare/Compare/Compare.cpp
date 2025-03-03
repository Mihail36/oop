﻿#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

const char RUSSIAN_LANGUAGE[8] = "Russian";
const int RUSSIAN_ENCODING = 1251;

const int ERROR_NO_FILES = 2;
const int ERROR_NO_SECOND_FILE = 3;
const int ERROR_FILE_NOT_EXIST = 4;

const int FIRST_FILE_PARAMETER = 1;
const int SECOND_FILE_PARAMETER = 2;

const std::string MESSAGE_NO_FILES = "No files entered!\n";
const std::string MESSAGE_NO_SECOND_FILE = "No second file!\n";
const std::string MESSAGE_EQUAL_FILES = "Files are equal\n";
const std::string MESSAGE_EXAMPLE =  "Example: compare.exe <file1> <file2>\n";
const std::string MESSAGE_DIFFERENT_FILES = "Files are different. Line number is ";
const std::string MESSAGE_ERROR_NO_FIRST_FILE = "The first file does not exist!\n";
const std::string MESSAGE_ERROR_NO_SECOND_FILE = "The second file does not exist!\n";

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	SetConsoleCP(RUSSIAN_ENCODING);
	SetConsoleOutputCP(RUSSIAN_ENCODING);

	if (argv[FIRST_FILE_PARAMETER] == NULL)
	{
		std :: cout << MESSAGE_NO_FILES;
		std::cout << MESSAGE_EXAMPLE;
		return ERROR_NO_FILES;
	}
	if (argv[SECOND_FILE_PARAMETER] == NULL)
	{
		std:: cout << MESSAGE_NO_SECOND_FILE;
		std::cout << MESSAGE_EXAMPLE;
		return ERROR_NO_SECOND_FILE;
	}

	std:: ifstream inputFirstFile;
	std:: ifstream inputSecondFile;
	std:: string strFirstFile = "";
	std:: string strSecondFile = "";
	int countStr = 1;

	inputFirstFile.open(argv[FIRST_FILE_PARAMETER]);
	inputSecondFile.open(argv[SECOND_FILE_PARAMETER]);

	if (!inputFirstFile.is_open())
	{
		std::cout << MESSAGE_ERROR_NO_FIRST_FILE;
		std::cout << MESSAGE_EXAMPLE;
		return ERROR_FILE_NOT_EXIST;
	}
	if (!inputSecondFile.is_open())
	{
		std::cout << MESSAGE_ERROR_NO_SECOND_FILE;
		std::cout << MESSAGE_EXAMPLE;
		return ERROR_FILE_NOT_EXIST;
	}
	
	while (getline(inputFirstFile, strFirstFile))
	{
		if (getline(inputSecondFile, strSecondFile))
			if (strFirstFile == strSecondFile)
				countStr++;
			else
			{
				std::cout << MESSAGE_DIFFERENT_FILES << countStr << std::endl;
				return 1;
			}
		else
		{
			std::cout << MESSAGE_DIFFERENT_FILES << countStr << std::endl;
			return 1;
		}
	}

	std:: cout << MESSAGE_EQUAL_FILES;
	return 0;
}

//open()
// endl
// goto 
// countStr