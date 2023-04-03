#include <iostream>
#include <string>

int main()
{
	std::string s;

	std::cin >> s;

	int f_count = -2;
	size_t s_size = s.size();

	for (size_t i = 0; i < s_size; ++i) {
		if (s.at(i) == 'f' || s.at(i) == 'F') {
			f_count += 1;
	
			if (f_count == 0) {
				std::cout << i;
				break;
			}
		}
	}
	
	if (f_count != 0) {
		std::cout << f_count;
	}

	return 0;
}
