#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <cmath>

const int FIRST_FILE_PARAMETER = 1;
const int SECOND_FILE_PARAMETER = 2;

const int ERROR_NO_NAME_FILES = 1;
const int ERROR_NO_NAME_SECOND_FILE = 2;
const int ERROR_NO_FILE = 3;
const int ERROR_FILE_IS_EMPTY = 4;

const std::string MESSAGE_ERROR_NO_NAME_FILES = "No file names entered!\n";
const std::string MESSAGE_ERROR_NO_NAME_SECOND_FILE = "No name of second file entered!\n";
const std::string MESSAGE_ERROR_NO_FIRST_FILE = "The first file does not exist!\n";
const std::string MESSAGE_ERROR_NO_SECOND_FILE = "The second file does not exist!\n";
const std::string MESSAGE_ERROR_FIRST_FILE_IS_EMPTY = "The first file is empty!\n";
const std::string MESSAGE_ERROR_SECOND_FILE_IS_EMPTY = "The second file is empty!\n";

const int MAX_MATRIX = 3;

void MultMatrix(double firstMatrix[MAX_MATRIX][MAX_MATRIX], double secondMatrix[MAX_MATRIX][MAX_MATRIX], double res[MAX_MATRIX][MAX_MATRIX])
{
	for (int i = 0; i < MAX_MATRIX; i++)
	{
		for (int j = 0; j < MAX_MATRIX; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < MAX_MATRIX; k++)
			{
				res[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
}

bool IsOpenFile(std::fstream &file, int numberFile)
{
	if (!file.is_open())
	{
		if (numberFile == 1)
			std::cout << MESSAGE_ERROR_NO_FIRST_FILE;
		if (numberFile == 2)
			std::cout << MESSAGE_ERROR_NO_SECOND_FILE;
		return false;
	}
	return true;
}

bool IsEmptyFile(std::fstream &file, int numberFile)
{
	if (file.peek() == EOF)
	{
		if (numberFile == 1)
			std::cout << MESSAGE_ERROR_FIRST_FILE_IS_EMPTY;
		if (numberFile == 2)
			std::cout << MESSAGE_ERROR_SECOND_FILE_IS_EMPTY;
		return true;
	}
	return false;
}

void FillMatrix(std::fstream &file, double matrix[MAX_MATRIX][MAX_MATRIX])
{
	for (int i = 0; i <= MAX_MATRIX - 1; i++)
	{
		for (int j = 0; j <= MAX_MATRIX - 1; j++)
		{
			file >> matrix[i][j];
		}
	}
}

void OutMatrix(double matrix[MAX_MATRIX][MAX_MATRIX])
{
	for (int i = 0; i < MAX_MATRIX; i++)
	{
		for (int j = 0; j < MAX_MATRIX; j++)
		{
			std::cout << std::fixed << std::setprecision(3) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char* argv[])
{
	std::fstream firstMatrixFile;
	std::fstream secondMatrixFile;
	double  inputMatrixFirst[MAX_MATRIX][MAX_MATRIX], inputMatrixSecond[MAX_MATRIX][MAX_MATRIX], resultMatrix[MAX_MATRIX][MAX_MATRIX];
	
	if (argv[FIRST_FILE_PARAMETER] == NULL)
	{
		std::cout << MESSAGE_ERROR_NO_NAME_FILES;
		return ERROR_NO_NAME_FILES;
	}
	if (argv[SECOND_FILE_PARAMETER] == NULL)
	{
		std::cout << MESSAGE_ERROR_NO_NAME_SECOND_FILE;
		return ERROR_NO_NAME_SECOND_FILE;
	}

	firstMatrixFile.open(argv[FIRST_FILE_PARAMETER]);
	secondMatrixFile.open(argv[SECOND_FILE_PARAMETER]);

	if (!IsOpenFile(firstMatrixFile, FIRST_FILE_PARAMETER) || !IsOpenFile(secondMatrixFile, SECOND_FILE_PARAMETER))
		return ERROR_NO_FILE;
	if (IsEmptyFile(firstMatrixFile, FIRST_FILE_PARAMETER) || IsEmptyFile(secondMatrixFile, SECOND_FILE_PARAMETER))
		return ERROR_FILE_IS_EMPTY;

	FillMatrix(firstMatrixFile, inputMatrixFirst);
	FillMatrix(secondMatrixFile, inputMatrixSecond);

	MultMatrix(inputMatrixFirst, inputMatrixSecond, resultMatrix);
	
	OutMatrix(resultMatrix);
	return 0;
}

/*
1) Setprecision и fixed
2) Убрать использование указателей
3) Названия у функций исправить
*/