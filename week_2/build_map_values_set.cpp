#include <iostream>
#include <map>
#include <set>
#include <string>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string> &m)
{
	std::set<std::string> result;

	for (const auto &item : m) {
		result.insert(item.second);
	}

	return result;	
}

int main()
{
	return 0;
}
