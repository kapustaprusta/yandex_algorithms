#include <set>
#include <vector>
#include <sstream>
#include <iostream>

int calcNumberOfSameNumbers(const std::vector<int> &crFirstListOfNumbers,
							const std::vector<int> &crSecondListOfNumbers)
{
	std::set<int> uniqueNumbersOfFirstList;	
	for (const auto &crNumber : crFirstListOfNumbers)
	{
		uniqueNumbersOfFirstList.insert(crNumber);
	}

	std::set<int> sameNumbers;
	for (const auto &crNumber : crSecondListOfNumbers)
	{
		if (sameNumbers.find(crNumber)              == sameNumbers.end()
		&&  uniqueNumbersOfFirstList.find(crNumber) != uniqueNumbersOfFirstList.end())
		{
			sameNumbers.insert(crNumber);
		}
	}

	return sameNumbers.size();
}

int main()
{
	int tmpNumber = 0;
	std::string tmpLine;

	std::vector<int> firstListOfNumbers;
	std::vector<int> secondListOfNumbers;

	getline(std::cin, tmpLine);
	std::istringstream stringStream(tmpLine);

	while (stringStream >> tmpNumber)
	{
		firstListOfNumbers.emplace_back(tmpNumber);
	}

	getline(std::cin, tmpLine);
	stringStream = std::istringstream(tmpLine);

	while (stringStream >> tmpNumber)
	{
		secondListOfNumbers.emplace_back(tmpNumber);
	}

	std::cout << calcNumberOfSameNumbers(firstListOfNumbers,
										 secondListOfNumbers) << "\n";

	return 0;
}