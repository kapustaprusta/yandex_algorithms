#include <map>
#include <limits>
#include <vector>
#include <iostream>

int main() {
	int studentCoord = 0;
	int studentsNumber = 0;
	std::vector<int> studentsCoords;
	std::cin >> studentsNumber;

	for (int i = 0; i < studentsNumber; i++) {
		std::cin >> studentCoord;
		studentsCoords.emplace_back(std::move(studentCoord));
	}

	std::cout << studentsCoords[studentsNumber/2];

	return 0;
}