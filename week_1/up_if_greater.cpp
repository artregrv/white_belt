#include <iostream>

void UpdateIfGreater(const int &first, int &second)
{
	if (first > second) {
		second = first;
	}
}

int main()
{
	int a;
	int b;

	std::cin >> a >> b;

	UpdateIfGreater(a, b);

	std::cout << "first = " << a << " second = " << b << '\n';
	return 0;
}
