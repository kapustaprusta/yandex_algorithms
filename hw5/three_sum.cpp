#include <list>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

struct Val
{
	long num;
	long idx;
};
int main()
{
	std::ifstream inputFile("/home/vniksihov/003.txt");
	if (!inputFile.is_open())
	{
		return 0;
	}

	/* */
	long arrSize = 0;
	long sumOfThree = 0;
	inputFile >> sumOfThree;
	
	std::vector<std::vector<Val>> arrays;
	arrays.resize(3);

	for (long i = 0; i < 3; i++)
	{
		inputFile >> arrSize;
		arrays[i].resize(arrSize);

		long tmpNum;
		for (long j = 0; j < arrSize; j++)
		{
			inputFile >> tmpNum;
			arrays[i][j] = Val{tmpNum, j};
		}
	}

	/* */
	std::vector<long> resIdxs;
	for (auto &array : arrays)
	{
		std::sort(array.begin(), array.end(), [](const Val &lhs, const Val &rhs)
		{
			if (lhs.num == rhs.num)
			{
				return lhs.idx > rhs.idx;
			}

			return lhs.num < rhs.num;
		});
	}

	for (long i = 0; i < arrays[0].size(); i++)
	{
		long k = arrays[2].size() - 1;
		for (long j = 0; j < arrays[1].size(); j++)
		{
			while ((k > 0)
			&&    ((arrays[0][i].num +
				   arrays[1][j].num +
				   arrays[2][k].num) > sumOfThree))
			{
				k--;
			}

			if (arrays[0][i].num +
				arrays[1][j].num +
				arrays[2][k].num == sumOfThree)
			{
				std::vector<long> tmpIdxs = {arrays[0][i].idx,
											 arrays[1][j].idx,
											 arrays[2][k].idx};
				if (resIdxs.empty())
				{
					resIdxs = std::move(tmpIdxs);
				}
				else
				{
					if ((tmpIdxs[0] < resIdxs[0])
					||  (tmpIdxs[0] == resIdxs[0] && tmpIdxs[1] < resIdxs[1])
					||  (tmpIdxs[0] == resIdxs[0] && tmpIdxs[1] == resIdxs[1] && tmpIdxs[2] < resIdxs[2]))
					{
						resIdxs = std::move(tmpIdxs);
					}
				}
			}
		}
	}

	if (resIdxs.empty())
	{
		std::cout << -1 << "\n";

		return 0;
	}

	for (const auto &idx : resIdxs)
	{
		std::cout << idx << " ";
	}
	std::cout << "\n";

	return 0;
}
