#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

void PrintNumbers(const std::string &path)
{
	std::ifstream input(path);

	std::string line;

	std::cout << std::fixed << std::setprecision(3);
	
	if (input.is_open()) {
		while (std::getline(input, line)) {
			std::cout << std::stod(line) << '\n';
		}
	}
}
	

int main()
{
	std::string path = "input.txt";
	
	PrintNumbers(path);

	return 0;
}
