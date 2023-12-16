#pragma once

#include <iostream>
#include <sstream>
#include "date.h"

void Date::SetYear(const int year)
{
	this->year = year;
}

int Date::GetYear() const
{
	return year;
}

void Date::SetMonth(const int month)
{
	this->month = month;
}

int Date::GetMonth() const
{
	return month;
}

void Date::SetDay(const int day)
{
	this->day = day;
}

int Date::GetDay() const
{
	return day;
}

void Date::print(std::ostream& ost) const
{
	ost << this->GetYear() << "." << this->GetMonth() << "." << this->GetDay() << std::endl;
}

void Date::read(std::istream& ist)
{
	int yyyy, mm, dd;
	char point = '.';
	if (ist >> yyyy >> point >> mm >> point >> dd)
	{
		this->SetYear(yyyy);
		this->SetMonth(mm);
		this->SetDay(dd);
	}
	ist.ignore();
}

bool Date::ValidateDate(const std::string& date) {
	std::istringstream in(date);
	int year, month, day;
	char point = '.';
	in >> year >> point >> month >> point >> day;
	if (in.fail() || year < 2000 || year > 9999 || month > 12 || month < 1 || day > 31 || day < 1) {
		return false;
	}
	return true;
}

void Date::InvalidDate(const std::string& date)
{
	if (date.empty() || !ValidateDate(date)) {
		throw std::runtime_error("Invalid time!");
	}
	ValidateDate(date);
}
