#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{	
	std::map<std::string, std::vector<std::string>> buses;
	std::vector<std::pair<std::string, std::vector<std::string>>> unsorted_buses;
	
	int operations_count;
	std::cin >> operations_count;

	for (int i = 0; i < operations_count; ++i) {
		std::string operation;
		std::cin >> operation;

		if (operation == "NEW_BUS") {
			std::string bus;
			std::cin >> bus;
			
			int stop_count;
			std::cin >> stop_count;
			
			std::vector<std::string> stops(stop_count);
			for (int j = 0; j < stop_count; ++j) {
				std::cin >> stops[j];
			}
			
			buses[bus] = stops;
			std::pair<std::string, std::vector<std::string>> new_bus
				= { bus, stops };
			unsorted_buses.push_back(new_bus);
		} else if (operation == "BUSES_FOR_STOP") {
			std::string stop;
			std::cin >> stop;

			bool stop_exist = false;

			for (const auto &bus : unsorted_buses) {
				const auto bus_stops = bus.second;

				if (std::find(begin(bus_stops), end(bus_stops), stop) != end(bus_stops)) {
					stop_exist = true;
					std::cout << bus.first << ' ';
				} 
			}

			if (!stop_exist) {
				std::cout << "No stop";
			}

			std::cout << '\n';
		} else if (operation == "STOPS_FOR_BUS") {
			std::string bus;
			std::cin >> bus;

			if (!buses.count(bus)) {
				std::cout << "No bus\n";
			} else {
				const auto stops = buses[bus];

				for (const auto &stop : stops) {
					std::cout << "Stop " << stop << ": ";	
					
					bool has_interchange = false;					

					for (const auto &unsorted_bus : unsorted_buses) {
						if (unsorted_bus.first != bus) {
							const auto unsorted_bus_stops = unsorted_bus.second;
	
		
							if (std::find(begin(unsorted_bus_stops), 
										  end(unsorted_bus_stops), stop)
										  != end(unsorted_bus_stops)) {
								has_interchange = true;
	
								std::cout << unsorted_bus.first << ' ';
							}
						} 
					}

					if (!has_interchange) {
						std::cout << "no interchange"; 
					}

					std::cout << '\n';
				}
			}	
		} else if (operation == "ALL_BUSES") {
			if (buses.empty()) {
				std::cout << "No buses\n";
			} else {

				for (const auto &bus : buses) {
					std::cout << "Bus " << bus.first << ": ";

					const auto stops = bus.second;
					for (const auto &stop : stops) {
						std::cout << stop << ' ';
					} 
	
					std::cout << '\n';
				}
			}	
		}
	}

	return 0;
}
