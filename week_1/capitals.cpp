#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
	int operations_count;
	std::cin >> operations_count;

	std::map<std::string, std::string> countries;

	std::string operation;
	for (int i = 0; i < operations_count; ++i) {
		std::cin >> operation;
	
		if (operation == "CHANGE_CAPITAL") {
			std::string country;
			std::cin >> country; 

			std::string new_capital;
			std::cin >> new_capital;
			
			if (!countries.count(country)) {
				countries[country] = new_capital;
				std::cout << "Introduce new country " << country 
						  << " with capital " << new_capital << '\n';
			} else if (countries[country] == new_capital) {
				std::cout << "Country " << country << " hasn't changed its capital\n";
			} else {
				std::cout << "Country " << country 
						  << " has changed its capital from " 
						  << countries[country] << " to " << new_capital << '\n';
				countries[country] = new_capital;
			}
		} else if (operation == "RENAME") {
			std::string old_country_name;
			std::cin >> old_country_name;
	
			std::string new_country_name;
			std::cin >> new_country_name;
			
			if ((old_country_name == new_country_name)
				|| !countries.count(old_country_name)
				|| countries.count(new_country_name)) {
				std::cout << "Incorrect rename, skip\n";
			} else {
				std::cout << "Country " << old_country_name << " with capital "
						  << countries[old_country_name] << " has been renamed to "
						  << new_country_name << '\n';
				countries[new_country_name] = countries[old_country_name];
				countries.erase(old_country_name);	
			} 
			
		} else if (operation == "ABOUT") {
			std::string country;
			std::cin >> country;

			if (!countries.count(country)) {
				std::cout << "Country " << country << " doesn't exist\n";
			} else {
				std::cout << "Country " << country << " has capital " 
						  << countries[country] << '\n';
			}
		} else if (operation == "DUMP") {
			if (countries.empty()) {
				std::cout << "There are no countries in the world\n";
			} else {
				for (const auto &country : countries) {
					std::cout << country.first << '/' << country.second << '\n';
				} 	
			}
		}
	}

	return 0;
}
