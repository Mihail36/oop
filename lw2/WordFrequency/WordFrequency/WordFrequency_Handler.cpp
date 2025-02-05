#include <iostream>
#include <algorithm>
#include "WordFrequency.h"


void ToLower(std::string& str)
{
	transform(str.begin(), str.end(), str.begin(), tolower);
}

std::map<std::string, int> CountWordFrequency(std::istream& input)
{
	std::map<std::string, int> frequency;

	std::string word;
	while (input >> word)
	{
		ToLower(word);
		++frequency[word];
	}

	return frequency;
}

void PrintWordFrequency(const std::map<std::string, int>& frequency)
{
	for (const auto& pair : frequency)
		std::cout << pair.first << " " << pair.second << std::endl;
}