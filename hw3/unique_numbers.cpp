#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>

void printUniqueNumbers(const std::vector<int> &crNumbers)
{
	std::unordered_map<int, int> numbersCounters;
	for (const auto &crNumber : crNumbers)
	{
		numbersCounters[crNumber]++;
	}

	for (const auto &crNumber : crNumbers)
	{
		if (numbersCounters.at(crNumber) == 1)
		{
			std::cout << crNumber << " ";
		}
	}

	std::cout << "\n";
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

	printUniqueNumbers(listOfNumbers);

	return 0;
}