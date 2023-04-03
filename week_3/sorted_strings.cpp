#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class SortedStrings
{
public:
	void AddString(const std::string &s)
	{
		_strings.push_back(s);
		std::sort(begin(_strings), end(_strings));
	}

	std::vector<std::string> GetSortedStrings()
	{
		return _strings;
	}

private:
	std::vector<std::string> _strings;
};

void PrintSortedStrings(SortedStrings &strings)
{
	for (const std::string &s : strings.GetSortedStrings()) {
		std::cout << s << ' ';
	}
	std::cout << '\n';
}

int main()
{
	return 0;
}
