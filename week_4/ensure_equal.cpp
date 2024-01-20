#include <exception>
#include <iostream>
#include <sstream>
#include <string>

void EnsureEqual(const std::string &left, const std::string &right)
{
	if (left != right) {
		std::stringstream ss;
		ss << left << " != " << right;
		throw std::runtime_error(ss.str());
	}
}

int main()
{
	try {
		EnsureEqual("C++", "C++");
		EnsureEqual("C++", "C");
	} catch (std::exception	&e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}
