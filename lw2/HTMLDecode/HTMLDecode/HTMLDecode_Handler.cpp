#include "HTMLDecode_Handler.h"

constexpr char UNIVERSAL_LETTER = '&';


using Dict = std::vector<std::pair<std::string, std::string>>;

const Dict RULES_OF_REPLACE =
{
	{ "\"", "&quot;" },
	{ "'", "&apos;" },
	{ "<", "&lt;" },
	{ ">", "&gt;" },
	{ "&", "&amp;" }
};

std::string FindAndReplaceEntity(std::string html, size_t& replacePos)
{
	for (size_t rule = 0; rule < RULES_OF_REPLACE.size(); ++rule)
	{
		if (html.compare(replacePos, RULES_OF_REPLACE[rule].second.length(), RULES_OF_REPLACE[rule].second) == 0)
		{
			replacePos += RULES_OF_REPLACE[rule].second.length();
			return RULES_OF_REPLACE[rule].first;
		}
	}
	++replacePos;

	return  { UNIVERSAL_LETTER };
};

std::string HTMLDecode(std::string const& html)
{
	size_t searchPos = 0;
	std::string result;

	while (searchPos < html.length())
	{
		size_t replacePos = html.find(UNIVERSAL_LETTER, searchPos);
		result.append(html, searchPos, replacePos - searchPos);

		if (replacePos == std::string::npos)
		{
			break;
		}
		auto const pattern = FindAndReplaceEntity(html, replacePos);
		result.append(pattern);
		searchPos = replacePos;
	}
	return result;
}

void HtmlDecodeInStreams(std::istream& input, std::ostream& output)
{
	std::string line;
	while (std::getline(input, line))
	{
		output << HTMLDecode(line) << "\n";
	}
}