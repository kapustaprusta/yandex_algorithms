#include <iostream>

int main() {
	int stationsNum      = 0;
	int startStationNum  = 0;
	int finishStationNum = 0;

	std::cin >> stationsNum >> startStationNum >> finishStationNum;

	if (startStationNum == finishStationNum) {
		std::cout << 0;
		return 0;
	}

	int rightTurn = std::abs(finishStationNum - startStationNum ) - 1;
	int leftTurn  = std::abs(stationsNum - rightTurn) - 2;

	std::cout << std::min(rightTurn, leftTurn);
}