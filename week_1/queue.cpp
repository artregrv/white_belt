#include <iostream>
#include <string>
#include <vector>

void printVector(const std::vector<bool> &v)
{
	for (const auto &item : v) {
		std::cout << item << ' ';
	}
	std::cout << '\n';
}

int main()
{
	std::vector<bool> queue; // true - worry, false - quite

	long long int operations_count;
	std::cin >> operations_count; 

	for (long long int j = 0; j < operations_count; ++j) {
		std::string operation;
		std::cin >> operation;

		if (operation == "WORRY") {
			long long int i;
			std::cin >> i;

			queue[i] = true; 
//			printVector(queue);
		} 
		if (operation == "QUITE") { 
			long long int i;
			std::cin >> i;
		
			queue[i] = false;
//			printVector(queue);
		}
		if (operation == "COME") {
			long long int k;
			std::cin >> k;

			if (k > 0) {
				for (long long int i = 0; i < k; ++i) {
					queue.push_back(false);
				}
			} else {
				//for (long long int i = k; i < 0; ++i) {
				//	queue.pop_back();
				//}
				queue.resize(queue.size() + k);
			}
//			printVector(queue);
		}
		if (operation == "WORRY_COUNT") {
			long long int count = 0;
			for (const bool worry : queue) {
				if (worry) {
					count += 1;
				}
			}
			
			std::cout << count << '\n';
		}
	}

	return 0;

}
