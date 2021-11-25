#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

bool cmpFunc(const std::pair<std::string, int> &crLhs,
			 const std::pair<std::string, int> &crRhs)
{
	if (crLhs.second == crRhs.second)
	{
		return crLhs.first < crRhs.first;
	}

	return crLhs.second > crRhs.second;
}

int main()
{
	std::map<std::string, int> wordsAndCounters;
	while (true)
	{
		std::string tmpTextLine;
		getline(std::cin, tmpTextLine);

		if (tmpTextLine.empty())
		{
			break;
		}

		std::string tmpWord;
		std::istringstream inputTextStream(tmpTextLine);

		while (inputTextStream >> tmpWord)
		{
			wordsAndCounters[tmpWord]++;
		}
	}

	std::vector<std::pair<std::string, int>> sortedWordsAndCounters;
	for (const auto &rWordAndCounter : wordsAndCounters)
	{
		sortedWordsAndCounters.push_back(rWordAndCounter);
	}
	std::sort(sortedWordsAndCounters.begin(), sortedWordsAndCounters.end(), cmpFunc);

	for (const auto &crSortedWordAndCounter : sortedWordsAndCounters)
	{
		std::cout << crSortedWordAndCounter.first << "\n";
	}

	return 0;
}
