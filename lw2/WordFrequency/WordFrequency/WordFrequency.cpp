#include <iostream>
#include <algorithm>
#include "WordFrequency.h"

int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::map<std::string, int> frequency = CountWordFrequency(std::cin);
	PrintWordFrequency(frequency);

	return 0;
}