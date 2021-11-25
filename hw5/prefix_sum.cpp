#include <vector>
#include <iostream>

int main()
{
	int numCount = 0;
	int reqCount = 0;

	std::cin >> numCount;
	std::cin >> reqCount;

	long long tmpNum = 0;
	long long prevSum = 0;

	std::vector<long long> nums;
	std::vector<long long> prefixSums;

	for (int i = 0; i < numCount; i++)
	{
		std::cin >> tmpNum;
		nums.push_back(tmpNum);
		prefixSums.push_back(prevSum);

		prevSum += tmpNum;
	}
	prefixSums.push_back(prevSum);

	int lBound = 0;
	int rBound = 0;

	for (int i = 0; i < reqCount; i++)
	{
		std::cin >> lBound;
		std::cin >> rBound;

		std::cout << prefixSums[rBound] - prefixSums[lBound-1] << "\n";
	}

	return 0;
}