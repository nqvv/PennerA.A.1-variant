#include <iostream>

#include "date.h"

void Date::print(std::ostream& ost) const
{
	ost << day << "." << month << "." << year << std::endl;
}

Date Date::read(std::istream& ist)
{
	Date date;
	char dot;
	ist >> date.year >> dot >> date.month >> dot >> date.day;
	return date;
}
