#include <map>
#include <iostream>

int main() {
	int currNumber = 0;
	std::map<int, int> numberCounters;

	while (true) {
		std::cin >> currNumber;
		if (currNumber == 0) {
			break;
		}

		numberCounters[currNumber]++;
	}

	std::cout << numberCounters.rbegin()->second;

	return 0;
}