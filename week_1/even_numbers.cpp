#include <iostream>

int main()
{
	int a;
	int b;
	
	std::cin >> a >> b;

	for (int i = a; i < b + 1; ++i) {
		if ((i % 2) == 0) {
			std::cout << i << ' ';
		}
	}

	return 0;
}
