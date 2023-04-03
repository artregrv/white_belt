#include <iostream>
#include <string>

bool IsPalindrom(std::string s)
{
	size_t size = s.size();

	if (size == 0) {
		return true;
	}
	
	for (size_t i = 0; i < size / 2; ++i) {
		if (s.at(i) != s.at(size - i - 1)) {
			return false;
		}
	}

	return true;
}

int main()
{
	std::string s;

	std::cin >> s;

	std::cout << IsPalindrom(s);

	return 0;
}
