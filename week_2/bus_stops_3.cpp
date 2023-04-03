#include <iostream>
#include <map>
#include <set>
#include <string>

int main()
{
	std::map<std::set<std::string>, int> routes;

	int route_count = 0;

	int operation_count;
	std::cin >> operation_count;

	for (int i = 0; i < operation_count; ++i) {
		int stop_count;
		std::cin >> stop_count;

		std::set<std::string> stops;		
		
		for (int j = 0; j < stop_count; ++j) {
			std::string stop;
			std::cin >> stop;
			
			stops.insert(stop);
		}
		
		if (routes.count(stops)) {
			std::cout << "Already exists for " << routes[stops];
		} else {
			route_count += 1;
			routes[stops] = route_count;
			std::cout <<  "New bus " << route_count;
		}
		
		std::cout << '\n';
	}
	
	return 0;
}
