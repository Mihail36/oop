
#include "CrossSets_Handler.h"
#include <iostream>
#include <string>
#include <cctype>


int main(int argc, char* argv[])
{
	int n;

	int errorCode = GetError(argc, argv, n);
	if (errorCode != 0)
		return errorCode;

	std::set<int> divSumSet = CreateDivSumSet(n);
	std::set<int> evenSumSet = CreateEvenSumSet(n);
	PrintSets(divSumSet, evenSumSet);

	return 0;
}