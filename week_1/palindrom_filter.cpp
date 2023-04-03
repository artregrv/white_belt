#include <iostream>
#include <string>
#include <vector>

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

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength)
{
	std::vector<std::string> result;

	for (const auto w : words) {
		if (IsPalindrom(w) && (static_cast<int>(w.size()) >= minLength)) {
			result.push_back(w);
		}
	}

	return result;
}

int main()
{
	std::vector<std::string> v1 = { "abacaba", "aba" };
	std::vector<std::string> result1 = PalindromFilter(v1, 5);

	std::vector<std::string> v2 = { "abacaba", "aba" };
	std::vector<std::string> result2 = PalindromFilter(v2, 2);

	std::vector<std::string> v3 = { "weew", "dro", "code" };
	std::vector<std::string> result3 = PalindromFilter(v3, 4);

	for (const auto &s : result3) {
		std::cout << s << ' ';
	}

	return 0;
}
