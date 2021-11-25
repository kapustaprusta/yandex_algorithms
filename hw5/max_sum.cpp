#include <vector>
#include <limits>
#include <iostream>

int main()
{
	int numCount = 0;
	std::cin >> numCount;

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

	long long oddNum = 0;
	long long maxSum = std::numeric_limits<long long>().min();

	for (int i = 1; i < prefixSums.size(); i++)
	{
		const long long currMaxSum = std::max(prefixSums[i],
											  prefixSums[i] - oddNum);
		if (currMaxSum > maxSum)
		{
			maxSum = currMaxSum;
		}

		if (prefixSums[i] < 0 && prefixSums[i] < oddNum)
		{
			oddNum = prefixSums[i];
		}
	}

	std::cout << maxSum << "\n";
	
	return 0;
}