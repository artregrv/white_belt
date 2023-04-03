#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ifstream input("test.txt");

	std::string line;

	if (input.is_open()) {
		while (std::getline(input, line)) {
			std::cout << line << '\n';
		}

		std::cout << "End of file!\n"; 
	} else {
		std::cout << "File doesn't open!\n";
	}
	
	return 0;
}
