#include <iostream>
#include <set>
#include <string>
#include <vector>

int main()
{
	int string_count;
	std::cin >> string_count;

	std::vector<std::string> strings(string_count);

	for (auto &s : strings) {
		std::cin >> s;
	}

	std::set<std::string> unique_strings(begin(strings), end(strings));
	
	std::cout << unique_strings.size() << '\n';

	return 0;
}
