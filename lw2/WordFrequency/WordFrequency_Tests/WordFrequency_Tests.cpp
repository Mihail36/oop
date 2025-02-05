#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "../../../catch2/catch.hpp"
#include "../WordFrequency/WordFrequency.h"



TEST_CASE("ToLower function")
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SECTION("Empty string")
	{
		std::string testStr = "";
		ToLower(testStr);
		REQUIRE(testStr == "");
		std::cout << "ToLower function, empty string - Completed" << std::endl;
	}

	SECTION("Lowercase letters")
	{
		std::string testStr = "world";
		ToLower(testStr);
		REQUIRE(testStr == "world");
		std::cout << "ToLower function, lowercase letters - Completed" << std::endl;
	}

	SECTION("Mixed letters")
	{
		std::string testStr = "MixEdCaSe";
		ToLower(testStr);
		REQUIRE(testStr == "mixedcase");
		std::cout << "ToLower function, mixed letters - Completed" << std::endl;
	}

	SECTION("Non-letter characters")
	{
		std::string testStr = "123$%#";
		ToLower(testStr);
		REQUIRE(testStr == "123$%#");
		std::cout << "ToLower function, non-letter characters - Completed" << std::endl;
	}

	SECTION("Russian letters")
	{
		std::string testStr = "Го гО го ГО";
		ToLower(testStr);
		REQUIRE(testStr == "го го го го");
		std::cout << "ToLower function, russian letters - Completed" << std::endl;
	}
	std::cout << std::endl;
}

TEST_CASE("CountWordFrequency function")
{
	SECTION("Empty input")
	{
		std::istringstream input("");
		auto result = CountWordFrequency(input);
		std::map<std::string, int> expected = {};
		REQUIRE(result == expected);
		std::cout << "CountWordFrequency function, empty input - Completed" << std::endl;

	}

	SECTION("One word")
	{
		std::istringstream input("Hello");
		auto result = CountWordFrequency(input);
		std::map<std::string, int> expected = { {"hello", 1} };
		REQUIRE(result == expected);
		std::cout << "CountWordFrequency function, one word - Completed" << std::endl;
	}

	SECTION("Multiple words with mixed letters")
	{
		std::istringstream input("Hello World hELLO");
		auto result = CountWordFrequency(input);
		std::map<std::string, int> expected = { {"hello", 2}, {"world", 1} };
		REQUIRE(result == expected);
		std::cout << "CountWordFrequency function, multiple words with mixed letters - Completed" << std::endl;
	}
	std::cout << std::endl;
}


TEST_CASE("PrintWordFrequency function")
{
	std::stringstream ss;

	SECTION("Empty map")
	{
		std::map<std::string, int> frequency;
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintWordFrequency(frequency);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "");
		std::cout << "PrintWordFrequency function, empty map - Completed" << std::endl;
	}

	SECTION("Non-empty map")
	{
		std::map<std::string, int> frequency = { {"apple", 3}, {"banana", 1}, {"orange", 2} };
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintWordFrequency(frequency);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "apple 3\nbanana 1\norange 2\n");
		std::cout << "PrintWordFrequency function, non-empty map - Completed" << std::endl;
	}
	std::cout << std::endl;
}