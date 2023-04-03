#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Person
{
public:
	void ChangeFirstName(int year, const std::string &first_name)
	{
		_first_names[year] = first_name;
	};

	void ChangeLastName(int year, const std::string &last_name)
	{
		_last_names[year] = last_name;
	};

	std::string GetFullName(int year)
	{
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

		if ((first_name_result.empty()) && (last_name_result.empty())) {
			return "Incognito";
		} else if (first_name_result == "") {
			return last_name_result + " with unknown first name";
		} else if (last_name_result == "") {
			return first_name_result + " with unknown last name";
		} else {
			return first_name_result + ' ' +  last_name_result;
		}
	};

	std::string GetFullNameWithHistory(int year) {
		std::string first_name_history = GetNameHistoryByYear(year, _first_names);
		std::string last_name_history = GetNameHistoryByYear(year, _last_names);

		if ((first_name_history.empty()) && (last_name_history.empty())) {
			return "Incognito";
		} else if (first_name_history == "") {
			return last_name_history + " with unknown first name";
		} else if (last_name_history == "") {
			return first_name_history + " with unknown last name";
		} else {
			return first_name_history + ' ' +  last_name_history;
		}
	}

private:
	std::string GetNameHistoryByYear(int year, const std::map<int, 
									 std::string, std::greater<int>> &names) 
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

	std::map<int, std::string, std::greater<int>> _first_names;
	std::map<int, std::string, std::greater<int>> _last_names;
};

using namespace std;

int main()
{
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}
