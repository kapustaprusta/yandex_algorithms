#include <cmath>
#include <iostream>

struct Point {
	int x;
	int y;

	float Distance(const Point &crPoint) {
		return std::sqrt(((std::pow(x - crPoint.x, 2) + std::pow(y - crPoint.y, 2))));
	}
};

int main() {
	Point pointX;
	int legLength = 0;

	std::cin >> legLength >> pointX.x >> pointX.y;

	Point pointA{0, 0};
	Point pointB{legLength, 0};
	Point pointC{0, legLength};

	if ((pointX.x >= 0 && pointX.y >= 0)
	&&  (pointX.x + pointX.y <= legLength)) {
		std::cout << 0;

		return 0;
	}
	else {
		const auto distanceToA = pointX.Distance(pointA);
		const auto distanceToB = pointX.Distance(pointB);
		const auto distanceToC = pointX.Distance(pointC);

		std::cout << distanceToA << " " << distanceToB << " " << distanceToC << "\n";

		if (distanceToA <= distanceToB && distanceToA <= distanceToC) {
			std::cout << 1;

			return 0;
		}
		else if (distanceToB <= distanceToA && distanceToB <= distanceToC) {
			std::cout << 2;

			return 0;
		}
		else {
			std::cout << 3;

			return 0;
		}
	}

	return 0;
}