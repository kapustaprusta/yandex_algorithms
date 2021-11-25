#include <map>
#include <string>
#include <sstream>
#include <iostream>

int main()
{
	int packagesNumber = 0;
	std::map<long, long> colorsAndWeights;

	std::cin >> packagesNumber;
	for (int i = 0; i < packagesNumber; i++)
	{
		long tmpColor = 0;
		long tmpWeight = 0;
		
		for (int j = 0; j < 2; j++)
		{
			j % 2 == 0 ? std::cin >> tmpColor
					   : std::cin >> tmpWeight;
		}

		colorsAndWeights[tmpColor] += tmpWeight;
	}

	for (const auto &crColorAndWeight : colorsAndWeights)
	{
		std::cout << crColorAndWeight.first << " " << crColorAndWeight.second << "\n";
	}

	return 0;
}