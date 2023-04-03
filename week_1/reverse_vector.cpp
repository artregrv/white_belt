#include <iostream>
#include <vector>

void Reverse(std::vector<int> &v)
{
	size_t size = v.size();

	for (size_t i = 0; i < size / 2; ++i) {
		int tmp = v.at(i);
		v[i] = v.at(size - i - 1);
		v[size - i - 1] = tmp;
	}
}	

int main()

	std::vector<int> v = { 1, 2, 3, 4, 5 };
	
	Reverse(v);

	for (const auto &item : v) {
		std::cout << item << " ";
	}

	return 0;
}
