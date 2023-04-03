#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Name
{
	int year;
	std::string first_name { "" };
	std::string last_name { "" };
};

class Person
{
public:
	void ChangeFirstName(int year, const std::string &first_name)
	{
		Name new_name;
		new_name.year = year;
		new_name.first_name = first_name;
		
		InsertName(new_name);
	}

	void ChangeLastName(int year, const std::string &last_name)
	{
		Name new_name;
		new_name.year = year;
		new_name.last_name = last_name;
		
		InsertName(new_name);
	}

	std::string GetFullName(int year)
	{
		if (name_history.size() > 0) {
			size_t history_size = name_history.size();

			if (year < name_history.at(0).year) {
				return "Incognito";
			}

			std::string result;

			size_t i = 0;
			while (i < (history_size - 1)) {
				//std::cout << name_history.at(i).year << " - year\n";
				//std::cout << name_history.at(i).first_name << " - first name\n";
				//std::cout << name_history.at(i).last_name << " - last name\n";
				if (name_history.at(i).year <= year && name_history.at(i + 1).year > year) {
					Name current_name = name_history.at(i);
	
					if (current_name.first_name == "") {
						result = current_name.last_name + " with unknown first name";
					} else if (current_name.last_name == "") {
						result = current_name.first_name + " with unknown last name";
					} else {
						result = current_name.first_name + " " + current_name.last_name;
					}
					
					return result;
				}
			
				i += 1;
			}

			if (name_history.at(history_size - 1).year <= year) {
				Name current_name = name_history.at(history_size - 1);
	
				if (current_name.first_name == "") {
					result = current_name.last_name + " with unknown first name";
				} else if (current_name.last_name == "") {
					result = current_name.first_name + " with unknown last name";
				} else {
					result = current_name.first_name + " " + current_name.last_name;
				}
					
				return result;
			}

		} else {
			return "";
		}
	}

private:
	void InsertName(Name &name)
	{
		name_history.push_back(name);

		std::sort(begin(name_history), end(name_history), [](Name &n1, Name &n2) {
			return n1.year < n2.year;
		});

		size_t history_size = name_history.size();

		if (history_size > 1) {
			for (size_t i = 0; i < history_size; ++i) {
				std::cout << name_history.at(i).year << " - year\n";
				std::cout << name_history.at(i).first_name << " - first name\n";
				std::cout << name_history.at(i).last_name << " - last name\n";
				if (name_history.at(i).year == name.year) {
					if (name_history.at(i).first_name == "") {
						name_history[i].first_name = name_history.at(i - 1).first_name;
					}
					if (name_history.at(i).last_name == "") {
						name_history[i].last_name = name_history.at(i - 1).last_name;
					}
				}
			}
		}			 
	}	
	
	std::vector<Name> name_history;
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
