#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::ifstream input("input.txt");

	int n;
	int m;

	std::vector<std::vector<int>> table;

	if (input.is_open()) {
		input >> n;
		input.ignore(1);
		input >> m;

		int value;

		for (int i = 0; i < n; ++i) {
			table.push_back({});

			for (int j = 0; j < m; j++) {
				input >> value;
				input.ignore(1);
				table[i].push_back(value);
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cout << std::setw(10) << table[i][j];

				if (j != m - 1) {
					std::cout << ' ';
				}
			}

			if (i != n - 1) {	
				std::cout << '\n';
			}
		}
	}

	return 0;
}
