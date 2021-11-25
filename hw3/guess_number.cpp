#include <map>
#include <list>
#include <string>
#include <sstream>
#include <iostream>

void printProbablyNumbers(int maxNumber,
						  std::list<int> trueNumbers,
						  std::list<int> falseNumbers)
{
	int maxCount = 0;
	std::map<int, int> probablyNumbers;

	for (int i = 1; i <= maxNumber; i++)
	{
		probablyNumbers[i]++;
	}

	for (const auto &crTrueNumber : trueNumbers)
	{
		if (crTrueNumber <= maxNumber)
		{
			probablyNumbers[crTrueNumber]++;
			if (probablyNumbers[crTrueNumber] > maxCount)
			{
				maxCount = probablyNumbers[crTrueNumber];
			}
		}
	}

	for (const auto &crFalseNumber : falseNumbers)
	{
		if (crFalseNumber <= maxNumber)
		{
			probablyNumbers.erase(crFalseNumber);
		}
	}

	for (const auto &crProbablyNumber : probablyNumbers)
	{
		if (crProbablyNumber.second >= maxCount)
		{
			std::cout << crProbablyNumber.first << " ";
		}
	}

	std::cout << "\n";
}

int main()
{
	int maxNumber = 0;
	std::cin >> maxNumber;

	int lineIdx = 0;
	int tmpNumber = 0;
	std::string tmpLine;
	std::list<int> tmpNumbers;
	std::list<int> trueNumbers;
	std::list<int> falseNumbers;

	getline(std::cin, tmpLine);
	while (true)
	{
		getline(std::cin, tmpLine);
		if (tmpLine.find("HELP") != std::string::npos)
		{
			break;
		}

		if (lineIdx % 2 == 0)
		{
			std::istringstream stringStream(tmpLine);
			while (stringStream >> tmpNumber)
			{
				if (tmpNumber <= maxNumber)
				{
					tmpNumbers.emplace_back(std::move(tmpNumber));
				}
			}
		}
		else if (lineIdx % 2 == 1)
		{
			if (tmpLine.find("YES") != std::string::npos)
			{
				trueNumbers.insert(trueNumbers.end(),
								   tmpNumbers.begin(),
								   tmpNumbers.end());
			}
			else
			{
				falseNumbers.insert(falseNumbers.end(),
									tmpNumbers.begin(),
									tmpNumbers.end());
			}

			tmpNumbers.clear();
		}

		lineIdx++;
	}

	printProbablyNumbers(maxNumber,
						 std::move(trueNumbers),
						 std::move(falseNumbers));

	return 0;
}