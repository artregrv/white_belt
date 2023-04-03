#include <iostream>
#include <map>
#include <string>

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

		if ((first_name_result == "") && (last_name_result == "")) {
			return "Incognito";
		} else if (first_name_result == "") {
			return last_name_result + " with unknown first name";
		} else if (last_name_result == "") {
			return first_name_result + " with unknown last name";
		} else {
			return first_name_result + ' ' +  last_name_result;
		}
	};

private:
	std::map<int, std::string, std::greater<int>> _first_names;
	std::map<int, std::string, std::greater<int>> _last_names;
};

int main()
{
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }
    return 0;
}
