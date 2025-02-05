#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../../../catch2/catch.hpp"
#include "../vector/Vector_Handler.h"

TEST_CASE("ReadVector function")
{
	SECTION("Reading empty vector")
	{
		std::vector<double> numbers;
		std::stringstream input;
		REQUIRE(ReadVector(numbers, input) == numbers);
		REQUIRE(numbers.empty());
		std::cout << "Reading empty vector - Completed" << std::endl;
	}

	SECTION("Reading vector")
	{
		std::vector<double> numbers;
		std::stringstream input("1.23 4.56 -7.89\n");
		REQUIRE(ReadVector(numbers, input) == numbers);
		REQUIRE(numbers.size() == 3);
		std::cout << "Reading vector - Completed" << std::endl;
	}
	std::cout << std::endl;
}

TEST_CASE("ProcessVector function")
{
	SECTION("ProcessVector returns a vector with the same values as input vector")
	{
		std::vector<double> numbers{ 1.0, 2.0, 3.0 };
		double min = *min_element(numbers.begin(), numbers.end());
		std::vector<double> result = ProcessVector(numbers, min);
		REQUIRE(result == numbers);
		std::cout << "ProcessVector returns a vector with the same values as input vector - Completed" << std::endl;
	}

	SECTION("ProcessVector returns a vector with zero values")
	{
		std::vector<double> numbers{ 0.0, 1.0, 2.0 };
		double min = *min_element(numbers.begin(), numbers.end());
		std::vector<double> expected{ numbers[0] * 0.0, numbers[1] * 0.0, numbers[2] * 0.0 };
		std::vector<double> result = ProcessVector(numbers, min);

		REQUIRE(result == expected);
		std::cout << "ProcessVector returns a vector with the zero values - Completed" << std::endl;
	}

	SECTION("ProcessVector returns a vector with transformed values")
	{
		std::vector<double> numbers{ 1.0, -2.0, 3.0 };
		double min = *min_element(numbers.begin(), numbers.end()); 
		std::vector<double> expected{ numbers[0] * -2.0, numbers[1] * -2.0, numbers[2] * -2.0 };
		std::vector<double> result = ProcessVector(numbers, min);

		REQUIRE(result == expected);
		std::cout << "ProcessVector returns a vector with transformed values - Completed" << std::endl;
	}
	std::cout << std::endl;
}

TEST_CASE("PrintVector function")
{
	std::stringstream ss;

	SECTION("PrintVector prints empty vector")
	{
		std::vector<double> numbers;
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintVector(numbers);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "");
		std::cout << "PrintVector prints empty vector - Completed" << std::endl;
	}

	SECTION("PrintVector prints vector")
	{
		std::vector<double> numbers{ 1.0, 2.0, 3.0 };
		std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
		PrintVector(numbers);
		std::cout.rdbuf(old_cout);
		REQUIRE(ss.str() == "1 2 3 ");
		std::cout << "PrintVector prints vector - Completed" << std::endl;
	}
	std::cout << std::endl;
}