#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include <algorithm>

#include "../../../catch2/catch.hpp"
#include "../HTMLDecode/HTMLDecode_Handler.h"

TEST_CASE("Decode Check")
{
	SECTION("Decode empty input")
	{
		std::stringstream in("");
		std::stringstream out;
		HtmlDecodeInStreams(in, out);
		REQUIRE(out.str().empty());
		std::cout << "Decode empty input - Completed" << std::endl;
	};
	SECTION("Decode for string with no special characters ")
	{
		std::stringstream in("Hello my friend!");
		std::stringstream out;
		HtmlDecodeInStreams(in, out);
		REQUIRE(out.str() == "Hello my friend!\n");
		std::cout << "Decode for string with no special characters - Completed" << std::endl;
	}
	SECTION("Decode for text with special characters ")
	{
		std::stringstream in("Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s");
		std::stringstream out;
		HtmlDecodeInStreams(in, out);
		REQUIRE(out.str() == "Cat <says> \"Meow\". M&M's\n");
		std::cout << "Decode for text with special characters - Completed" << std::endl;
	}
	std::cout << std::endl;
}