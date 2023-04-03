#include <iostream>
#include <string>
#include <vector>

void MoveStrings(std::vector<std::string> &source,
				 std::vector<std::string> &destination)
{
	for (auto &s : source) {
		destination.push_back(s);
	}

	source.clear();
}

int main()
{
	std::vector<std::string> s = { "a", "b", "c" };
	std::vector<std::string> d = { "x" };

	MoveStrings(s, d);

	for (const auto &s : d) {
		std::cout << s << " ";
	}
	
	std::cout << '\n';

	return 0;
}
