#include <fstream>
#include <iostream>
#include <string>

void PrintFromFile(const std::string &path)
{
	std::ifstream input(path);

	std::string line;

	if (input.is_open()) {
		while (getline(input, line)) {
			std::cout << line << '\n';
		}
	}
}

int main()
{
	std::string path = "input.txt";
	PrintFromFile(path);

	return 0;
}
