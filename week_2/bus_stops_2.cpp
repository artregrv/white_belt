#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
	std::map<std::vector<std::string>, int> routes;

	int operation_count;
	std::cin >> operation_count;

	int route_number = 1; 

	for (int i = 0; i < operation_count; ++i) {
		int stop_count;
		std::cin >> stop_count;

		std::vector<std::string> stops(stop_count);

		for (auto &stop : stops) {
			std::cin >> stop;
		}

		if (routes.count(stops)) {
			std::cout << "Already exists for " << routes[stops] << '\n';
		} else {
			routes[stops] = route_number;
			std::cout << "New bus " << route_number << '\n';
			route_number += 1;
		}
	}

	return 0;
}
