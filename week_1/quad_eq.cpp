#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
	double a;
	double b;
	double c;

	std::cin >> a >> b >> c;

	if (a == 0) {
		if (b != 0) {
			std::cout << -c / b;
		} else {
			std::cout << " ";
		}
		return 0;
	}

	double d = b * b - 4 * a *  c;

	if (d < 0) {
		std::cout << " ";
		return 0;
	}

	if (d == 0) { // d == 0 is bad, I know
		std::cout << (-b + std::sqrt(d)) / (2 * a);
		return 0;
	}

	double x1 = (-b + std::sqrt(d)) / (2 * a);
	double x2 = (-b - std::sqrt(d)) / (2 * a);

	std::cout << x1 << " " << x2;

	return 0;
}	
