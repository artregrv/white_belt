#include <iostream>
#include <string>
#include <vector>

struct Student
{
	std::string first_name;
	std::string last_name;
	int day;
	int month;
	int year;
};

int main()
{
	std::vector<Student> students;

	int students_count;
	std::cin >> students_count;

	for (int i = 0; i < students_count; ++i) {
		Student s;
		std::cin >> s.first_name;
		std::cin >> s.last_name;
		std::cin >> s.day;
		std::cin >> s.month;
		std::cin >> s.year;

		students.push_back(s);
	} 

	int requests_count;
	std::cin >> requests_count;

	for (int i = 0; i < requests_count; ++i) {
		std::string request;
		std::cin >> request;

		size_t student_number;
		std::cin >> student_number;
		student_number -= 1;

		if (student_number < students.size()) {
			if (request == "name") {
				std::cout << students[student_number].first_name << ' '
						  << students[student_number].last_name << '\n';
			} else if (request == "date") {
				std::cout << students[student_number].day << '.'
						  << students[student_number].month << '.'
						  << students[student_number].year << '\n';
		
			} else {
				std::cout << "bad request\n";
			}
		} else {
			std::cout << "bad request\n";
		}
	}

	return 0;
}
