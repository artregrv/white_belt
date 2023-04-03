#include <iostream>
#include <vector>

void printVector(const std::vector<int> &v)
{
	for (const auto &item : v) {
		std::cout << item << " ";
	}
}

int main()
{
	int size;

	std::cin >> size;
	
	std::vector<int> temp(size);

	int sum = 0;

	for (int &day_temp : temp) {
		std::cin >> day_temp;
		sum += day_temp;
	}

	int average = sum / size;

	int result_count = 0;

	for (const int &day_temp : temp) {
		if (day_temp > average) {
			result_count += 1;
		}
	}

	std::cout << result_count << '\n';

	for (int i = 0; i < size; ++i) {
		if (temp.at(i) > average) {
			std::cout << i << ' ';
		}
	}

	return 0;
}
	
