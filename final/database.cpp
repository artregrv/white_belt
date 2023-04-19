#include <iostream>
#include <map>
#include <string>
#include <vector>

class Date 
{
public:
	explicit Date(int year, int month, int day) :
		_year(year),
		_month(month),
		_day(day)
	{}

	int GetYear() const
	{
		return _year;
	}

	int GetMonth() const
	{
		return _month;
	}

	int GetDay() const
	{
		return _day;
	}

private:
	int _year { 0 };
	int _month { 0 };
	int _day { 0 };	
};

bool operator<(const Date& lhs, const Date& rhs);

class Database 
{
public:
	void AddEvent(const Date& date, const std::string& event)
	{
	}

	bool DeleteEvent(const Date& date, const std::string& event)
	{
	}

	int  DeleteDate(const Date& date)
	{
	}

	// NOTE: wrong return type
	void Find(const Date& date) const;
  
	void Print() const;

private:
	
};

int main() {
	Database db;
    
	std::string command;
	while (std::getline(std::cin, command)) {
 		// Считайте команды с потока ввода и обработайте каждую
	}

	return 0;
}
