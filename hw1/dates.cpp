#include <iostream>

int main() {
	int date  = 0;
	int month = 0;
	int year  = 0;

	std::cin >> date >> month >> year;

	if ((date <= 12 && month >  12)
	||  (date >  12 && month <= 12)) {
		std::cout << 1;

		return 0;
	}

	if ((date  == month)
	&&  (date  <=    12)
	&&  (month <=    12)) {
		std::cout << 1;

		return 0;
	}

	std::cout << 0;

	return 0;
}