#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../TV/CTVSet.h"

TEST_CASE("First turn on and turn off")
{
	CTVSet tv;
	REQUIRE(tv.IsTurnedOn() == false);
	tv.TurnOn();
	REQUIRE(tv.IsTurnedOn() == true);
	REQUIRE(tv.GetChannel() == 1);
	tv.TurnOff();
	REQUIRE(tv.IsTurnedOn() == false);
	std::cout << "First turn on and turn off - Completed" << std::endl;
}

TEST_CASE("Valid channel selected")
{
	CTVSet tv;
	tv.TurnOn();
	REQUIRE(tv.SelectChannel(25) == true);
	REQUIRE(tv.GetChannel() == 25);
	std::cout << std::endl << "Valid channel selected - Completed" << std::endl;
}

TEST_CASE("Invalid channel selected")
{
	CTVSet tv;
	tv.TurnOn();
	REQUIRE(tv.SelectChannel(-1) == false);
	REQUIRE(tv.SelectChannel(1000) == false);
	std::cout << std::endl << "Invalid channel selected - Completed" << std::endl;
}


TEST_CASE("TV remember channel after turn off")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(30);
	tv.TurnOff();
	tv.TurnOn();
	REQUIRE(tv.GetChannel() == 30);
	std::cout << std::endl << "TV remember channel after turn off - Completed" << std::endl;
}

TEST_CASE("TV selected previous channel")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(5);
	tv.SelectChannel(15);
	tv.SelectPreviousChannel();
	REQUIRE(tv.GetChannel() == 5);
	std::cout << std::endl << "TV selected previous channel - Completed" << std::endl;
}