#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class Date 
{
public:
	explicit Date() = default;

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

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() < rhs.GetYear()) {
		return true;
	} else if (lhs.GetYear() > rhs.GetYear()) {
		return false;
	}

	if (lhs.GetMonth() < rhs.GetMonth()) {
		return true;
	} else if (lhs.GetMonth() > rhs.GetMonth()) {
		return false;
	}

	if (lhs.GetDay() < rhs.GetDay()) {
		return true;
	}

	return false;
}

class Database 
{
public:
	void AddEvent(const Date& date, const std::string& event)
	{
		if (std::find(_datesAndEvents[date].begin(), _datesAndEvents[date].end(), event) 
			   == _datesAndEvents[date].end()) {
			_datesAndEvents[date].push_back(event);	

			std::sort(_datesAndEvents[date].begin(), _datesAndEvents[date].end());
		}
	}

	bool DeleteEvent(const Date& date, const std::string& event)
	{
		if (_datesAndEvents.count(date) == 0) {
			return false;
		}

		const auto eventPosition = std::find(_datesAndEvents[date].begin(),
											 _datesAndEvents[date].end(),
											 event);
		if (eventPosition == _datesAndEvents[date].end()) {
			return false;
		} else { 
			_datesAndEvents[date].erase(eventPosition);
		}

		return true;
	}

	int  DeleteDate(const Date& date)
	{
		int numberOfDeletedEvents = _datesAndEvents.count(date) == 0
									? 0 
									: _datesAndEvents.at(date).size();

		_datesAndEvents.erase(date);

		return numberOfDeletedEvents;
	}

	std::vector<std::string> Find(const Date& date) const
	{		
		return _datesAndEvents.count(date) == 0
			   ? std::vector<std::string>()
			   : _datesAndEvents.at(date); 
	}
  
	void Print() const
	{
		for (const auto &date : _datesAndEvents) {
			for (const auto &event : date.second) {
				Date currentDate = date.first;
				std::cout << std::setfill('0') 
					<< std::setw(4) << currentDate.GetYear() << '-'
					<< std::setw(2) << currentDate.GetMonth() << '-'
					<< std::setw(2) << currentDate.GetDay() << ' '
					<< event << '\n'; 
			}
		}
	}

private:
	std::map<Date, std::vector<std::string>> _datesAndEvents;
};

Date getDateFromStream(std::istream &stream)
{
	std::string dateString;
	std::getline(stream, dateString, ' ');

	std::stringstream dateStream(dateString);

	int year;
	int month;
	int day;

	int numberOfHyphens = 0;
	int numberOfPluses = 0;
	char symbolBeforeNumber;
	while (!std::isdigit(dateStream.peek())) {
		if (dateStream.peek() != '-' && dateStream.peek() != '+') {
			throw std::invalid_argument("Wrong date format: " + dateString);
		}

		symbolBeforeNumber = dateStream.get();

		if (symbolBeforeNumber == '-') {
			numberOfHyphens += 1;
		}
		if (symbolBeforeNumber == '+') {
			numberOfPluses += 1;
		}
	}

	if (numberOfHyphens > 1) {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}

	if (numberOfPluses > 1) {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}

	if (numberOfPluses > 0 && symbolBeforeNumber != '+') {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}

	dateStream >> year;

	if (symbolBeforeNumber == '-' && numberOfHyphens == 2){
		year *= -1;
	}

	if (dateStream.peek() != '-') {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}

	numberOfHyphens = 0;
	numberOfPluses = 0;
	while (!std::isdigit(dateStream.peek())) {
		if (dateStream.peek() != '-' && dateStream.peek() != '+') {
			throw std::invalid_argument("Wrong date format: " + dateString);
		}

		symbolBeforeNumber = dateStream.get();
		
		if (symbolBeforeNumber == '-') {
			numberOfHyphens += 1;
		}
		if (symbolBeforeNumber == '+') {
			numberOfPluses += 1;
		}
	}

	if (numberOfHyphens > 2) {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}	

	if (numberOfPluses > 1) {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}

	if (numberOfPluses > 0 && symbolBeforeNumber != '+') {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}

	dateStream >> month;
		
	if (symbolBeforeNumber == '-' && numberOfHyphens == 2){
		month *= -1;
	}

	if (dateStream.peek() != '-') {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}

	numberOfHyphens = 0;
	numberOfPluses = 0;
	while (!std::isdigit(dateStream.peek())) {
		if (dateStream.peek() != '-' && dateStream.peek() != '+') {
			throw std::invalid_argument("Wrong date format: " + dateString);
		}

		symbolBeforeNumber = dateStream.get();
	
		if (symbolBeforeNumber == '-') {
			numberOfHyphens += 1;
		}
		if (symbolBeforeNumber == '+') {
			numberOfPluses += 1;
		}	
	}

	if (numberOfHyphens > 2) {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}	

	if (numberOfPluses > 1) {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}

	if (numberOfPluses > 0 && symbolBeforeNumber != '+') {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}

	dateStream >> day;
		
	if (symbolBeforeNumber == '-' && numberOfHyphens == 2) {
		day *= -1;
	}

	if (dateStream.peek() != EOF) {
		throw std::invalid_argument("Wrong date format: " + dateString);
	}

	if (month < 1 || month > 12) {
		throw std::invalid_argument("Month value is invalid: " + std::to_string(month));
	}

	if (day < 1 || day > 31) {
		throw std::invalid_argument("Day value is invalid: " + std::to_string(day));
	}

	Date date(year, month, day);

	return date;
}

void printEvents(const std::vector<std::string> &events)
{
	for (const auto &event : events) {
		std::cout << event << '\n';
	}
}
 
int main() {
	Database db;
    
	std::string command;
	while (std::getline(std::cin, command)) {

		if (command.empty()) {
			continue;
		}

		std::stringstream input(command);

		std::string type;
		std::getline(input, type, ' '); 	

		Date date;

		if (type == "Add" || type == "Del" || type == "Find") {
			try {
				date = getDateFromStream(input);
			} catch (std::exception &e) {
				std::cout << e.what() << '\n';
				return 1;
			}
		}

		if (type == "Add") {
			std::string event;
			std::getline(input, event, ' ');

			db.AddEvent(date, event);
		} else if (type == "Del") {
			std::string event;
			std::getline(input, event, ' ');
						
			if (event.empty()) {
				int numberOfDeletedEvents = db.DeleteDate(date);

				std::cout << "Deleted " << numberOfDeletedEvents << " events\n";
			} else {
				if (db.DeleteEvent(date, event)) {
					std::cout << "Deleted successfully\n";
				} else {
					std::cout << "Event not found\n";
				}	
			}
		} else if (type == "Find") {
			printEvents(db.Find(date));	
		} else if (type == "Print") {
			db.Print();
		} else {
			std::cout << "Unknown command: " << type << '\n';
			return 1;
		}
	}

	return 0;
}