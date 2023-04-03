#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	int size;
	std::cin >> size;

	std::vector<std::string> strings(size);
	for (auto &s : strings) {
		std::cin >> s;
	}

	std::sort(begin(strings), end(strings), [](std::string &first, std::string &second) {
		std::string first_lower = first;

		for (auto &c : first_lower) {
			c = tolower(c);
		}	
		
		std::string second_lower = second;

		for (auto &c : second_lower) {
			c = tolower(c);
		}

		return first_lower < second_lower;
	});


	for (const auto &s : strings) {
		std::cout << s << ' ';
	}
	std::cout << '\n'; 
	
	return 0;
}
