#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main()
{
	std::map<std::string, std::set<std::string>> synonyms;

	int operation_count;
	std::cin >> operation_count;

	for (int i = 0; i < operation_count; ++i) {
		std::string operation;
		std::cin >> operation;

		if (operation == "ADD") {
			std::string s1;
			std::string s2;
			std::cin >> s1 >> s2;

			synonyms[s1].insert(s2);
			synonyms[s2].insert(s1);
		} else if (operation == "COUNT") {
			std::string word;
			std::cin >> word;

			if (!synonyms.count(word)) {
				std::cout << 0 << '\n';
			} else {
				std::cout << synonyms[word].size() << '\n';
			}
		} else if (operation == "CHECK") {
			std::string w1;
			std::string w2;
			std::cin >> w1 >> w2;
			
			if (synonyms[w1].count(w2) || synonyms[w2].count(w1)) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
		}
	}
	return 0;
}
