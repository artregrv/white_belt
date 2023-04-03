#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool compare(std::string s1, std::string s2)
{
	return s1 < s2;
}

int main(int argc, char *argv[])
{
	std::vector<std::string> ss(3);
	
	std::cin >> ss[0] >> ss[1] >> ss[2];

	std::cout << std::min(std::min(ss[0], ss[1]), ss[2]);
 
	return 0;
}

