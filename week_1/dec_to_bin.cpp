#include <iostream>
#include <vector>

int main()
{
	int n;

	std::cin >> n;

	std::vector<int> result;

	while (n > 0) {
		result.push_back(n % 2);
		n /= 2;
	}

	size_t result_size = result.size();

	for (int i = result_size - 1; i >= 0; --i) {
		std::cout << result.at(i);
	}
			
	return 0;
}
