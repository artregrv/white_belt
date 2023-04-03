#include <iostream>
#include <map>
#include <string>

std::map<char, int> BuildCharCounters(std::string s)
{
	std::map<char, int> result;

	for (const auto &c : s) {
		result[c] += 1;
	}
	
	return result;
}


int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::string first;
		std::string second;

		std::cin >> first >> second;

		if (BuildCharCounters(first) == BuildCharCounters(second)) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}	

	return 0;
}
