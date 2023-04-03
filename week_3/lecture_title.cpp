#include <string>

struct Specialization
{
	explicit Specialization(std::string new_specialization) :
		specialization(new_specialization)
	{};

	std::string specialization;
};

struct Course
{
	explicit Course(std::string new_course) :
		course(new_course)
	{};

	std::string course;
};

struct Week
{
	explicit Week(std::string new_week) :
		week(new_week)
	{};

	std::string week;
}; 

struct LectureTitle
{
	LectureTitle(Specialization new_specialization, Course new_course, Week new_week)
	{
		specialization = new_specialization.specialization;
		course = new_course.course;
		week = new_week.week;
	};

	std::string specialization;
	std::string course;
	std::string week;
};

int main()
{
	LectureTitle title(
    	Specialization("C++"),
    	Course("White belt"),
    	Week("4th")
	);

	return 0;
}
