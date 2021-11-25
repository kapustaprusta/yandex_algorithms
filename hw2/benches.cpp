#include <set>
#include <iostream>

int main() {
	int benchLength = 0;
	int legsNumber  = 0;

	std::cin >> benchLength >> legsNumber;

	int currLegPos = 0;
	std::set<int> legsPos;
	for (int i = 0; i < legsNumber; i++) {
		std::cin >> currLegPos;
		legsPos.emplace(std::move(currLegPos));
	}

	int leftPos = 0;
	int rightPos = 0;
	if (benchLength % 2 == 0) {
		leftPos = benchLength / 2 - 1;
		rightPos = benchLength / 2;
	}
	else {
		leftPos = benchLength / 2;
		rightPos = leftPos;
	}

	bool hasLegOnLeftSide = false;
	bool hasLegOnRightSide = false;

	while (leftPos >= 0 && rightPos < benchLength) {
		if (legsPos.count(leftPos) != 0) {
			if (!hasLegOnLeftSide) {
				hasLegOnLeftSide = true;
			}
			else {
				legsPos.erase(leftPos);
			}
		}

		if (legsPos.count(rightPos) != 0) {
			if (!hasLegOnRightSide) {
				hasLegOnRightSide = true;
			}
			else {
				legsPos.erase(rightPos);
			}
		}

		leftPos--;
		rightPos++;
	}

	for (const auto &crLeg : legsPos) {
		std::cout << crLeg << " ";
	}

	return 0;
}