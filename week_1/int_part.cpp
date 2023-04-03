#include <iostream>

int main()
{
	int a;
	int b;

	std::cin >> a >> b;

	if (a < 0 || b < 0) {
		return 0;
	}

	if (b == 0) {
		std::cout << "Impossible";
		return 0;
	}

	std::cout << a / b; 
	return 0;
}
