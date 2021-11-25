#include <string>
#include <iostream>

int main() {
	std::string strToFix;
	std::cin >> strToFix;

	int leftPos = 0;
	int moneyCounter = 0;
	int rightPos = strToFix.size() - 1;

	while (leftPos < rightPos) {
		if (strToFix[leftPos] != strToFix[rightPos]) {
			moneyCounter++;
		}

		leftPos++;
		rightPos--;
	}

	std::cout << moneyCounter;

	return 0;
}