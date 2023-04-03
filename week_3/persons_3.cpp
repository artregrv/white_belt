#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Person
{
public:
	Person(std::string first_name, std::string last_name, int year_of_birth) : 
		_year_of_birth(year_of_birth)
	{
		_first_names[year_of_birth] = first_name;
		_last_names[year_of_birth] = last_name;
	}

	void ChangeFirstName(int year, const std::string &first_name)
	{
		_first_names[year] = first_name;
	};

	void ChangeLastName(int year, const std::string &last_name)
	{
		_last_names[year] = last_name;
	};

	std::string GetFullName(int year) const
	{
		if (year < _year_of_birth) {
			return "No person";
		}

		std::string first_name_result = "";
		std::string last_name_result = "";

		for (const auto &first_name : _first_names) {
			if (first_name.first <= year) {
				first_name_result = first_name.second;
				break;
			}	
		}
		
		for (const auto &last_name : _last_names) {
			if (last_name.first <= year) {
				last_name_result = last_name.second;
				break;
			}
		} 

		return BuildFullName(first_name_result, last_name_result);
	};

	std::string GetFullNameWithHistory(int year) const 
	{
		if (year < _year_of_birth) {
			return "No person";
		}

		std::string first_name_history = GetNameHistoryByYear(year, _first_names);
		std::string last_name_history = GetNameHistoryByYear(year, _last_names);

		return BuildFullName(first_name_history, last_name_history);
	}

private:
	std::string GetNameHistoryByYear(int year, const std::map<int, 
									 std::string, std::greater<int>> &names) const 
	{
		std::vector<std::string> name_history;

		for (const auto &name : names) {
			if (name.first <= year) {
				name_history.push_back(name.second);
			}
		}
		
		name_history.erase(std::unique(name_history.begin(), name_history.end()), 
						   name_history.end());

		std::string result = "";

		if (name_history.empty()) {
			result = "";
		} else if (name_history.size() == 1) {
			result = name_history.at(0);
		} else {
			result = name_history.front();
			std::string previous_name = name_history.front();
			name_history.erase(name_history.begin());

			result += " (";

			std::string last_name = name_history.back();
			name_history.erase(name_history.end() - 1);

			for (const auto &name : name_history) {
				result += name + ", ";
				previous_name = name;
			}

			result += last_name + ')';
		}

		return result;
	}

	std::string BuildFullName(std::string &first_name, std::string &last_name) const
	{
		if ((first_name.empty()) && (last_name.empty())) {
			return "Incognito";
		} else if (first_name == "") {
			return last_name + " with unknown first name";
		} else if (last_name == "") {
			return first_name + " with unknown last name";
		} else {
			return first_name + ' ' + last_name;
		}
	}

	std::map<int, std::string, std::greater<int>> _first_names;
	std::map<int, std::string, std::greater<int>> _last_names;

	int _year_of_birth { 0 };
};

using namespace std;

int main()
{
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
