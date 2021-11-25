#include <vector>
#include <limits>
#include <iostream>

int main() {
	int currBuilding = 0;
	std::vector<int> buildings;

	for (int i = 0; i < 10; i++) {
		std::cin >> currBuilding;
		buildings.emplace_back(std::move(currBuilding));
	}

	int maxDistance = 0;
	for (int i = 0; i < buildings.size(); i++) {
		if (buildings[i] == 1) {
			int minDistance = INT32_MAX;
			for (int j = 0; j < buildings.size(); j++) {
				if (buildings[j] == 2) {
					const auto currDistance = std::abs(i - j);
					if (currDistance < minDistance) {
						minDistance = currDistance;
					}
				}
			}

			if (minDistance > maxDistance) {
				maxDistance = minDistance;
			}
		}
	}

	std::cout << maxDistance;

	return 0;
}

