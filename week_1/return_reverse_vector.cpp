#include <iostream>
#include <vector>

std::vector<int> Reversed(const std::vector<int> &v)
{
	std::vector<int> reverse;

	int size = v.size();

	for (int i = size - 1; i >= 0; --i) {
		reverse.push_back(v.at(i));
	}

	return reverse;
}	

int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	
	std::vector<int> reverse = Reversed(v);

	for (const auto &item : reverse) {
		std::cout << item << " ";
	}

	return 0;
}
