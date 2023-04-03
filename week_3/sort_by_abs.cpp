#include <algorithm>
#include <iostream>
#include <vector>

void print(const std::vector<int> &v)
{
	for (const auto &i : v) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

int main()
{
	int size;
	std::cin >> size;

	std::vector<int> numbers(size);

	for (auto &n : numbers) {
		std::cin >> n;
	}

	std::sort(begin(numbers), end(numbers), [](int first, int second) {
		return abs(first) < abs(second);
	});		

	print(numbers);

	return 0;
}
