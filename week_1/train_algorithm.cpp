#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<int> v1 = { -10, 5, 4, -10, 3, 34, 2, -10 };

	std::cout << std::count(begin(v1), end(v1), -10) << '\n';	

	std::sort(begin(v1), end(v1));

	for (const auto &item : v1) {
		std::cout << item << " ";
	}
	
	std::cout << '\n';

	return 0;
}
