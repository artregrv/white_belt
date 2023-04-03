#include <iostream>

int main()
{
	double price;
	double a;
	double b;
	double x;
	double y;

	std::cin >> price >> a >> b >> x >> y;

	if (price > b) {
		std::cout << price * (1 - (y / 100));
	} else if (price > a) {
		std::cout << price * (1 - (x / 100));
	} else {
		std::cout << price;
	}
		
	return 0;
}
