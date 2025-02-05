#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Date/CTime.h"


TEST_CASE("CTime constructor - Hours, minutes, seconds")
{
	SECTION("Valid time")
	{
		CTime time(10, 30, 45);
		REQUIRE(time.GetHours() == 10);
		REQUIRE(time.GetMinutes() == 30);
		REQUIRE(time.GetSeconds() == 45);
		std::cout << "CTime constructor - Hours, minutes, seconds (Valid time) - Completed" << std::endl;
	}

	SECTION("Invalid time")
	{
		REQUIRE_THROWS_AS(CTime(25, 0, 0), std::invalid_argument);
		REQUIRE_THROWS_WITH(CTime(25, 0, 0), ERROR_TIME_NOT_CORRECT);
		REQUIRE_THROWS_AS(CTime(0, 60, 0), std::invalid_argument);
		REQUIRE_THROWS_WITH(CTime(0, 60, 0), ERROR_TIME_NOT_CORRECT);
		REQUIRE_THROWS_AS(CTime(0, 0, 60), std::invalid_argument);
		REQUIRE_THROWS_WITH(CTime(0, 0, 60), ERROR_TIME_NOT_CORRECT);
		REQUIRE_THROWS_AS(CTime(25, 60, 60), std::invalid_argument);
		REQUIRE_THROWS_WITH(CTime(25, 60, 60), ERROR_TIME_NOT_CORRECT);
		std::cout << "CTime constructor - Hours, minutes, seconds (Invalid time) - Completed" << std::endl;
	}
}

TEST_CASE("CTime constructor - Seconds after midnight")
{
	SECTION("Valid time")
	{
		CTime time(37845);
		REQUIRE(time.GetHours() == 10);
		REQUIRE(time.GetMinutes() == 30);
		REQUIRE(time.GetSeconds() == 45);
		std::cout << "CTime constructor - Seconds after midnight (Valid time) - Completed" << std::endl;
	}

	SECTION("Invalid time")
	{
		REQUIRE_THROWS_AS(CTime(MAX_SECONDS_IN_DAY + 1), std::invalid_argument);
		REQUIRE_THROWS_WITH(CTime(MAX_SECONDS_IN_DAY + 1), ERROR_TIME_NOT_CORRECT);
		std::cout << "CTime constructor - Seconds after midnight (Invalid time) - Completed" << std::endl;
	}
}


TEST_CASE("GetHours function")
{
	SECTION("Get hours from valid time")
	{
		CTime time(10, 30, 45);
		REQUIRE(time.GetHours() == 10);
		std::cout << "Get hours from valid time - Completed" << std::endl;
	}

	SECTION("Get hours from zero time")
	{
		CTime time(0);
		REQUIRE(time.GetHours() == 0);
		std::cout << "Get hours from zero time - Completed" << std::endl;
	}

	SECTION("Get hours from maximum time")
	{
		CTime time(MAX_SECONDS_IN_DAY);
		REQUIRE(time.GetHours() == HOURS_IN_DAY - 1);
		std::cout << "Get hours from maximum time - Completed" << std::endl;
	}
}

TEST_CASE("GetMinutes")
{
	SECTION("Get minutes from 0 seconds")
	{
		CTime time(0);
		REQUIRE(time.GetMinutes() == 0);
		std::cout << "Get minutes from 0 seconds - Completed" << std::endl;
	}

	SECTION("Get minutes from 60 seconds")
	{
		CTime time(60);
		REQUIRE(time.GetMinutes() == 1);
		std::cout << "Get minutes from 60 seconds - Completed" << std::endl;
	}

	SECTION("Get minutes from 3600 seconds")
	{
		CTime time(3600);
		REQUIRE(time.GetMinutes() == 0);
		std::cout << "Get minutes from 3600 seconds - Completed" << std::endl;
	}

	SECTION("Get minutes from 3723 seconds")
	{
		CTime time(3723);
		REQUIRE(time.GetMinutes() == 2);
		std::cout << "Get minutes from 3723 seconds - Completed" << std::endl;
	}
}

TEST_CASE("GetSeconds")
{
	SECTION("Get seconds from non-zero seconds")
	{
		CTime time(0, 0, 45);
		REQUIRE(time.GetSeconds() == 45);
		std::cout << "Get seconds from non-zero seconds - Completed" << std::endl;
	}

	SECTION("Get seconds from 0 seconds")
	{
		CTime time(10, 30, 0);
		REQUIRE(time.GetSeconds() == 0);
		std::cout << "Get seconds from 0 seconds - Completed" << std::endl;
	}
}

TEST_CASE("operator++")
{
	SECTION("Increment at the beginning")
	{
		CTime time(0);
		REQUIRE(time.GetHours() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetSeconds() == 0);

		++time;

		REQUIRE(time.GetHours() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetSeconds() == 1);
		std::cout << "operator++ Increment at the beginning - Completed" << std::endl;
	}

	SECTION("Increment in the middle")
	{
		CTime time(3720);
		REQUIRE(time.GetHours() == 1);
		REQUIRE(time.GetMinutes() == 2);
		REQUIRE(time.GetSeconds() == 0);

		++time;

		REQUIRE(time.GetHours() == 1);
		REQUIRE(time.GetMinutes() == 2);
		REQUIRE(time.GetSeconds() == 1);
		std::cout << "operator++ Increment in the middle - Completed" << std::endl;
	}

	SECTION("Increment at the end")
	{
		CTime time(MAX_SECONDS_IN_DAY);
		REQUIRE(time.GetHours() == 23);
		REQUIRE(time.GetMinutes() == 59);
		REQUIRE(time.GetSeconds() == 59);

		++time;

		REQUIRE(time.GetHours() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetSeconds() == 0);
		std::cout << "operator++ Increment at the end - Completed" << std::endl;
	}
}

TEST_CASE("operator-- ")
{
	SECTION("Decrement at the beginning")
	{
		CTime time(0);
		--time;
		REQUIRE(time.GetHours() == 23);
		REQUIRE(time.GetMinutes() == 59);
		REQUIRE(time.GetSeconds() == 59);
		std::cout << "operator-- Decrement at the beginning - Completed" << std::endl;
	}

	SECTION("Decrement in the middle")
	{
		CTime time(3600);
		--time;
		REQUIRE(time.GetHours() == 0);
		REQUIRE(time.GetMinutes() == 59);
		REQUIRE(time.GetSeconds() == 59);
		std::cout << "operator-- Decrement in the middle - Completed" << std::endl;
	}
}

TEST_CASE("operator+")
{
	SECTION("Add two times within the same day")
	{
		CTime time1(60);
		CTime time2(120);
		CTime expected(180);
		CTime result = time1 + time2;
		REQUIRE(result.GetHours() == expected.GetHours());
		REQUIRE(result.GetMinutes() == expected.GetMinutes());
		REQUIRE(result.GetSeconds() == expected.GetSeconds());
		std::cout << "operator+ Add two times within the same day - Completed" << std::endl;
	}

	SECTION("Add two times that cross midnight")
	{
		CTime time1(86340);
		CTime time2(120);
		CTime expected(60);
		CTime result = time1 + time2;
		REQUIRE(result.GetHours() == expected.GetHours());
		REQUIRE(result.GetMinutes() == expected.GetMinutes());
		REQUIRE(result.GetSeconds() == expected.GetSeconds());
		std::cout << "operator+ Add two times that cross midnight - Completed" << std::endl;
	}
}

TEST_CASE("operator-")
{
	SECTION("Subtracting the lesser from the greater")
	{
		CTime time1(3600);
		CTime time2(1800);
		CTime result = time1 - time2;
		REQUIRE(result.GetHours() == 0);
		REQUIRE(result.GetMinutes() == 30);
		REQUIRE(result.GetSeconds() == 0);
		std::cout << "operator- Subtracting the lesser from the greater - Completed" << std::endl;
	}

	SECTION("Subtracting more from less")
	{
		CTime time1(3600);
		CTime time2(1800);
		CTime result = time2 - time1;
		REQUIRE(result.GetHours() == 23);
		REQUIRE(result.GetMinutes() == 30);
		REQUIRE(result.GetSeconds() == 0);
		std::cout << "operator- Subtracting more from less - Completed" << std::endl;
	}

	SECTION("Subtracting the same time")
	{
		CTime time(3600);
		CTime result = time - time;
		REQUIRE(result.GetHours() == 0);
		REQUIRE(result.GetMinutes() == 0);
		REQUIRE(result.GetSeconds() == 0);
		std::cout << "operator- Subtracting the same time - Completed" << std::endl;
	}
}

TEST_CASE("operator+=")
{
	SECTION("Adding in the middle")
	{
		CTime time1(3600);
		CTime time2(1800);

		time1 += time2;
		REQUIRE(time1.GetHours() == 1);
		REQUIRE(time1.GetMinutes() == 30);
		REQUIRE(time1.GetSeconds() == 0);
		std::cout << "operator+= Adding in the middle - Completed" << std::endl;
	}

	SECTION("Adding up at midnight")
	{
		CTime time3(MAX_SECONDS_IN_DAY);
		CTime time4(1);
		time3 += time4;
		REQUIRE(time3.GetHours() == 0);
		REQUIRE(time3.GetMinutes() == 0);
		REQUIRE(time3.GetSeconds() == 0);
		std::cout << "operator+= Adding up at midnight - Completed" << std::endl;
	}
}

TEST_CASE("operator-=")
{
	SECTION("Subtraction in the middle")
	{
		CTime time1(3600);
		CTime time2(1800);

		time1 -= time2;
		REQUIRE(time1.GetHours() == 0);
		REQUIRE(time1.GetMinutes() == 30);
		REQUIRE(time1.GetSeconds() == 0);
		std::cout << "operator-= Subtraction in the middle - Completed" << std::endl;
	}

	SECTION("Subtraction at midnight")
	{
		CTime time3(0);
		CTime time4(1);
		time3 -= time4;
		REQUIRE(time3.GetHours() == 23);
		REQUIRE(time3.GetMinutes() == 59);
		REQUIRE(time3.GetSeconds() == 59);
		std::cout << "operator-= Subtraction at midnight - Completed" << std::endl;
	}
}

TEST_CASE("operator*")
{
	SECTION("Multiplication in range")
	{
		CTime time(19815);
		CTime result = time * 2;
		REQUIRE(result.GetHours() == 11);
		REQUIRE(result.GetMinutes() == 0);
		REQUIRE(result.GetSeconds() == 30);
		std::cout << "operator*= Multiplication in range - Completed" << std::endl;
	}

	SECTION("Multiplication over a range")
	{
		CTime time(19815);
		CTime result = time * 5;
		REQUIRE(result.GetHours() == 3);
		REQUIRE(result.GetMinutes() == 31);
		REQUIRE(result.GetSeconds() == 15);
		std::cout << "operator*= Multiplication over a range - Completed" << std::endl;
	}

	SECTION("Multiplication by zero")
	{
		CTime time(19815);
		CTime result = time * 0;
		REQUIRE(result.GetHours() == 0);
		REQUIRE(result.GetMinutes() == 0);
		REQUIRE(result.GetSeconds() == 0);
		std::cout << "operator*= Multiplication by zero - Completed" << std::endl;
	}
}

TEST_CASE("operator/")
{

	SECTION("Valid division")
	{
		CTime time1(3600);
		CTime time2(1800);
		CTime result(0);
		result = time1 / 2;
		REQUIRE(result == time2);
		REQUIRE((time1 / time2) == 2);
		std::cout << "operator/ Valid division - Completed" << std::endl;
	}

	SECTION("Dividing by zero throws an exception")
	{
		CTime time(3600);
		CTime timeZero(0);
		REQUIRE_THROWS_AS(time / timeZero, std::invalid_argument);
		REQUIRE_THROWS_WITH(time / timeZero, ERROR_TIME_ZERO);
		std::cout << "operator/ Dividing by zero throws an exception - Completed" << std::endl;
	}
}

TEST_CASE("operator*=")
{
	SECTION("Multiplication")
	{
		CTime time(10, 0, 0);
		time *= 3;
		REQUIRE(time.GetHours() == 6);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetSeconds() == 0);
		std::cout << "operator*= Multiplication - Completed" << std::endl;
	}

	SECTION("Multiplication with zero")
	{
		CTime time(10, 0, 0);
		time *= 0;
		REQUIRE(time.GetHours() == 0);
		REQUIRE(time.GetMinutes() == 0);
		REQUIRE(time.GetSeconds() == 0);
		std::cout << "operator*= Multiplication with zero - Completed" << std::endl;
	}
}

TEST_CASE("operator/=")
{
	SECTION("Valid division")
	{
		CTime time(3600);
		CTime result(1800);
		time /= 2;
		REQUIRE(time == result);
		std::cout << "operator/= Valid division - Completed" << std::endl;
	}

	SECTION("Dividing by zero throws an exception")
	{
		CTime time(3600);
		REQUIRE_THROWS_AS(time /= 0, std::invalid_argument);
		REQUIRE_THROWS_WITH(time /= 0, ERROR_TIME_ZERO);
		std::cout << "operator/= Dividing by zero throws an exception - Completed" << std::endl;
	}
}

TEST_CASE("operator<<")
{
	SECTION("Valid output - 1")
	{
		CTime time(10, 30, 45);
		std::ostringstream oss;
		oss << time;
		REQUIRE(oss.str() == "10:30:45");
		std::cout << "operator<< Valid output - 1 - Completed" << std::endl;
	}

	SECTION("Valid output - 2")
	{
		CTime time(121);
		std::ostringstream oss;
		oss << time;
		REQUIRE(oss.str() == "00:02:01");
		std::cout << "operator<< Valid output - 2 - Completed" << std::endl;
	}
}

TEST_CASE("operator>>")
{
	SECTION("Valid input")
	{
		CTime time;
		std::istringstream input("01:23:45");
		input >> time;
		REQUIRE(time == CTime(1, 23, 45));
		std::cout << "operator>> Valid input - Completed" << std::endl;
	}

	SECTION("Invalid input")
	{
		CTime time;
		std::istringstream input("asd");
		REQUIRE_THROWS_AS(input >> time, std::invalid_argument);
		std::cout << "operator>> Invalid input - Completed" << std::endl;
	}
}

TEST_CASE("comparison operators")
{
	CTime time1(1, 10, 30);
	CTime time2(1, 30, 10);
	CTime time3(2, 10, 30);

	SECTION("operator==")
	{
		REQUIRE(time1 == time1);
		REQUIRE_FALSE(time1 == time3);
		std::cout << "operator== - Completed" << std::endl;
	}

	SECTION("operator!=")
	{
		REQUIRE_FALSE(time2 != time2);
		REQUIRE(time2 != time3);
		std::cout << "operator!= - Completed" << std::endl;
	}

	SECTION("operator<")
	{
		REQUIRE_FALSE(time1 < time1);
		REQUIRE(time2 < time3);
		REQUIRE_FALSE(time3 < time3);
		std::cout << "operator< - Completed" << std::endl;
	}

	SECTION("operator>")
	{
		REQUIRE_FALSE(time1 > time3);
		REQUIRE(time2 > time1);
		REQUIRE(time3 > time2);
		std::cout << "operator> - Completed" << std::endl;
	}

	SECTION("operator<=")
	{
		REQUIRE(time1 <= time3);
		REQUIRE_FALSE(time2 <= time1);
		REQUIRE(time3 <= time3);
		std::cout << "operator<= - Completed" << std::endl;
	}

	SECTION("operator>=")
	{
		REQUIRE(time1 >= time1);
		REQUIRE_FALSE(time2 >= time3);
		REQUIRE(time3 >= time3);
		std::cout << "operator>= - Completed" << std::endl;
	}
}