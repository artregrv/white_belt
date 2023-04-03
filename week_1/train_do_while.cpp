#include <iostream>

int main(int argc, char *argv[])
{
	int num = 3;
	int user_num;

	do {
		std::cout << "Guess the number: ";
		std::cin >> user_num;
	} while (user_num != num);

	std::cout << "Done!\n";

	return 0;
}
