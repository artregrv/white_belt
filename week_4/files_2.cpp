#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void WriteToFile(const std::vector<std::string> &lines)
{
	std::ofstream output("output.txt");

	if (output.is_open()) { 
		for (const auto &line : lines) {
			output << line << '\n';
		}
	}
}
	
std::vector<std::string>  ReadFromFile(const std::string &path)
{
	std::ifstream input(path);

	std::vector<std::string> lines;
	std::string line;

	if (input.is_open()) {
		while (getline(input, line)) {
			lines.push_back(line);
		}
	}
	
	return lines;
}

int main()
{
	std::string path = "input.txt";

	WriteToFile(ReadFromFile(path));

	return 0;
}
