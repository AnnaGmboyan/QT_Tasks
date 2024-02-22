/*
Define an enum for days of the week and a struct representing a Date with day, month, and year as fields. Write a function that prints the day of the week and the date in a readable format. This task introduces structured data types and enumerations for more organized code.
*/
#include <iostream>
#include <string>
enum  Week_day
{
		Monday = 1,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday,
		Sunday
};

struct Date
{
		int day;
		int month;
		int year;
};
void foo(std::string day, Date curr_date);


int main()
{
		int week_day = 0;
		do {
			std::cout << "Enter a weekday with number from 1 to 7: ";
			std::cin >> week_day;
		} while (week_day < 1 || week_day > 7);
		
		Date date; 

		do {
			std::cout << "Enter the day of the month: ";
			std::cin >> date.day;
		} while (date.day < 1 || date.day > 31);

		do {
			std::cout << "Enter the month of the year: ";
			std::cin >> date.month;
		} while (date.month < 1 || date.month > 12);
	
		do {
			std::cout << "Enter the year: ";
			std::cin >> date.year;
		} while (date.year < 0);
		
		std::string str;
		switch(week_day)
		{
				case Week_day::Monday:
					str = "Monday";
					break;
				case Week_day::Tuesday:
					str = "Tuesday";
					break;
				case Week_day::Wednesday:
					str = "Wednesday";
					break;
				case Week_day::Thursday:
					str = "Thursday";
					break;
				case Week_day::Friday:
					str = "Friday";
					break;
				case Week_day::Saturday:
					str = "Saturday";
					break;
				case Week_day::Sunday: 
					str = "Sunday";

		}
		foo(str, date);
		return 0;
}

void foo(std::string day, Date curr_date)
{
	std::cout << curr_date.day <<"."<< curr_date.month << "." << curr_date.year << " " << day << std::endl;
}
