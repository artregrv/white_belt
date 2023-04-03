#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> days_in_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	std::vector<std::vector<std::string>> month;	

	int current_month = 0;
	month.resize(days_in_month.at(current_month));

	int operations_count;
	std::cin >> operations_count;
	
	std::string operation;

	for (int i = 0; i < operations_count; ++i) {
		std::cin >> operation;
		
		if (operation == "ADD") {
			int day;
			std::cin >> day;

			std::string task;
			std::cin >> task;

			month[day - 1].push_back(task);
		} else if (operation == "DUMP") {
			int day;
			std::cin >> day;
			
			const auto tasks = month.at(day - 1);

			std::cout << tasks.size() << ' ';

			for (const auto &task : tasks) {
				std::cout << task << ' ';
			}			
			
			std::cout << '\n';
		} else if (operation == "NEXT") {
			int new_month = (current_month + 1) % 12;
			int days_in_current_month = days_in_month.at(current_month);
			int days_in_new_month = days_in_month.at(new_month);
			
			if (days_in_new_month < days_in_current_month) {
				for (int d = days_in_new_month; d < days_in_current_month; ++d) {
					month[days_in_new_month - 1].insert(month[days_in_new_month - 1].end(), 
														month.at(d).begin(),
														month.at(d).end());
				}
			}				

			month.resize(days_in_new_month, {});
	
			current_month = new_month;
		} 			
	}
	return 0;
}
