#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

void printNumbersRepitability(const std::vector<int> &crNumbers)
{
	std::set<int> repeatableNumbers;
	for (const auto &crNumber : crNumbers)
	{
		if (repeatableNumbers.find(crNumber) == repeatableNumbers.end())
		{
			std::cout << "NO\n";
		}
		else
		{
			std::cout << "YES\n";
		}

		repeatableNumbers.insert(crNumber);
	}
}

int main()
{
	int tmpNumber = 0;
	std::string tmpLine;

	std::vector<int> listOfNumbers;

	getline(std::cin, tmpLine);
	std::istringstream stringStream(tmpLine);

	while (stringStream >> tmpNumber)
	{
		listOfNumbers.emplace_back(tmpNumber);
	}

	printNumbersRepitability(listOfNumbers);

	return 0;
}