#include <map>
#include <list>
#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>

int main()
{
	/* */
	int groupNum = 0;
	int classNum = 0;

	std::cin >> groupNum >> classNum;

	/* */
	int groupSize = 0;
	std::vector<int> groupsSizes;
	std::map<int, std::list<int>> groupSizesAndIdx;

	for (int i = 0; i < groupNum; i++)
	{
		std::cin >> groupSize;
		groupsSizes.push_back(groupSize);

		if (groupSizesAndIdx.count(groupSize) == 0)
		{
			groupSizesAndIdx[groupSize] = std::list<int>{};
		}
		groupSizesAndIdx[groupSize].push_back(i);
	}

	/* */
	int classSize = 0;
	std::vector<int> classesSizes;
	std::map<int, std::list<int>> classSizesAndIdx;

	for (int i = 0; i < classNum; i++)
	{
		std::cin >> classSize;
		classesSizes.push_back(classSize);
		
		if (classSizesAndIdx.count(classSize) == 0)
		{
			classSizesAndIdx[classSize] = std::list<int>{};
		}
		classSizesAndIdx[classSize].push_back(i);
	}

	/* */
	std::sort(groupsSizes.begin(), groupsSizes.end());
	std::sort(classesSizes.begin(), classesSizes.end());

	int groupIdx = 0;
	int classIdx = 0;
	int distGroupsNum = 0;
	std::vector<int> groupsDist;
	groupsDist.resize(groupsSizes.size());

	while(groupIdx < groupsSizes.size()
	   && classIdx < classesSizes.size())
	{
		if (groupsSizes[groupIdx] + 1 <= classesSizes[classIdx])
		{
			groupsDist[groupSizesAndIdx.at(groupsSizes[groupIdx]).back()]
										= classSizesAndIdx.at(classesSizes[classIdx]).back() + 1;
		
			groupSizesAndIdx.at(groupsSizes[groupIdx]).pop_back();
			classSizesAndIdx.at(classesSizes[classIdx]).pop_back();
			
			groupIdx++;
			distGroupsNum++;
		}

		classIdx++;
	}

	std::cout << distGroupsNum << "\n";
	for (const auto &crClassNum : groupsDist)
	{
		std::cout << crClassNum << " ";
	}
	std::cout << "\n";
	
	return 0;
}