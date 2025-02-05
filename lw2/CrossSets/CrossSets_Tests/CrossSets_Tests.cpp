#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include <algorithm>

#include "../../../catch2/catch.hpp"
#include "../CrossSets/CrossSets_Handler.h"


const int ERROR_NO_PARAMETER = 2;
const int ERROR_NEGATIVE = 3;
const int ERROR_NOT_DIGIT = 4;

TEST_CASE("GetError function")
{
	char programName[] = "CrossSets.exe";
	
	SECTION("Test ERROR_NO_PARAMETER")
	{
		int argc = 1;
		char* argv[1] = { programName };
		int n = 0;
		int errorCode = GetError(argc, argv, n);
		REQUIRE(errorCode == ERROR_NO_PARAMETER);

		std::cout << "Test ERROR_NO_PARAMETER - Completed";
	}

	SECTION("Test ERROR_NEGATIVE")
	{
		int argc = 2;
		char negativeDigit[] = "-123";
		char* argv[2] = { programName, negativeDigit };
		int n = 0;
		int errorCode = GetError(argc, argv, n);
		REQUIRE(errorCode == ERROR_NEGATIVE);

		std::cout << "Test ERROR_NEGATIVE - Completed";
	}

	SECTION("Test ERROR_NOT_DIGIT")
	{
		int argc = 2;
		char mix[] = "123abc";
		char* argv[2] = { programName, mix };
		int n = 0;
		int errorCode = GetError(argc, argv, n);
		REQUIRE(errorCode == ERROR_NOT_DIGIT);

		std::cout << "Test ERROR_NOT_DIGIT - Completed";
	}

	std::cout << std::endl << std::endl;
}
TEST_CASE("CreateDivSumSet function")
{
	SECTION("CreateDivSumSet: n = 10")
	{
		std::set<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::set<int> result = CreateDivSumSet(10);
		REQUIRE(result == expected);
		std::cout << "CreateDivDigitSumSet: n = 10 - Completed" << std::endl;
	}
	std::cout << std::endl;
}

TEST_CASE("CreateEvenSumSet function")
{
	SECTION("CreateEvenSumSet: n = 10")
	{
		std::set<int> expected = { 2, 4, 6, 8 };
		std::set<int> result = CreateEvenSumSet(10);
		REQUIRE(result == expected);
		std::cout << "CreateEvenSumSet: n = 10 - Completed" << std::endl;
	}
}

TEST_CASE("CrossSet function")
{
	std::set<int> divSumSet = { 1, 2, 3, 4, 5 };
	std::set<int> evenSumSet = { 4, 5, 6, 7, 8 };
	std::set<int> emptySet;
	SECTION("Intersection Sets")
	{
		std::set<int> expected = { 4, 5 };
		std::set<int> result = CrossSet(divSumSet, evenSumSet);
		REQUIRE(result == expected);
		std::cout << "Intersection Sets - Completed" << std::endl;
	}

	SECTION("Intersection of divSumSet and empty set")
	{
		std::set<int> expected = {};
		std::set<int> result = CrossSet(divSumSet, emptySet);
		REQUIRE(result == expected);
		std::cout << "Intersection of divSumSet and empty set - Completed" << std::endl;
	}

	SECTION("Intersection of empty set and evenSumSet")
	{
		std::set<int> expected = {};
		std::set<int> result = CrossSet(emptySet, evenSumSet);
		REQUIRE(result == expected);
		std::cout << "Intersection of empty set and evenSumSet - Completed" << std::endl;
	}

	SECTION("Intersection of two empty sets")
	{
		std::set<int> expected = {};
		std::set<int> result = CrossSet(emptySet, emptySet);
		REQUIRE(result == expected);
		std::cout << "Intersection of two empty sets - Completed" << std::endl;
	}

	std::cout << std::endl;
}

TEST_CASE("PrintSets function")
{
	std::set<int> divSumSet = { 1, 2, 3 };
	std::set<int> evenSumSet = { 2, 3, 4 };
	std::set<int> emptySet;
	std::stringstream ss;

	SECTION("Print intersection")
	{
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintSets(divSumSet, evenSumSet);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "Intersection: 2 3 ");
		std::cout << "Print intersection - Completed" << std::endl;
	}

	SECTION("Print empty intersection")
	{
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintSets(emptySet, emptySet);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "Intersection: ");
		std::cout << "Print empty intersection - Completed" << std::endl;
	}
	std::cout << std::endl;
}