#include <iostream>

int main() {
	int exitCode       = 0;
	int interactorCode = 0;
	int checkerCode    = 0;

	std::cin >> exitCode >> interactorCode >> checkerCode;
	
	if (interactorCode == 0) {
		if (exitCode != 0) {
			std::cout << 3;
		}
		else {
			std::cout << checkerCode;
		}
	}
	else if (interactorCode == 1) {
		std::cout << checkerCode;
	}
	else if (interactorCode == 4) {
		if (exitCode != 0) {
			std::cout << 3;
		}
		else {
			std::cout << 4;
		}
	}
	else if (interactorCode == 6) {
		std::cout << 0;
	}
	else if (interactorCode == 7) {
		std::cout << 1;
	}
	else {
		std::cout << interactorCode;
	}
}