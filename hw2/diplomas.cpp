#include <set>
#include <iostream>

int main() {
	int foldersNum = 0;
	std::cin >> foldersNum;

	std::multiset<int> folders;
	for (int i = 0; i < foldersNum; i++) {
		int diplomasNum = 0;
		std::cin >> diplomasNum;
		folders.emplace(std::move(diplomasNum));
	}

	int secondsCount = 0;
	int foldersCount = 0;
	auto itFirstFolder = folders.begin();
	
	while (foldersCount < foldersNum - 1) {
		secondsCount += *itFirstFolder;
		itFirstFolder++;
		foldersCount++;
	}

	std::cout << secondsCount;

	return 0;
}