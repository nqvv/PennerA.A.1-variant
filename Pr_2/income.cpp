#pragma once

#include <string>
#include "income.h"

using namespace std;

void Income::SetSource(const std::string source)
{
    this->source = source;
}

std::string Income::GetSource() const
{
    return source;
}

void Income::SetDate(const Date date)
{
    this->date = date;
}

Date Income::GetDate() const
{
    return date;
}

void Income::SetSumm(const int summ)
{
    this->summ = summ;
}

int Income::GetSumm() const
{
    return summ;
}

void Income::print(std::ostream& ost) const
{
    ost << "Date: ";
	Date date = this->GetDate();
    date.print(ost);
    ost << "Source: " << this->GetSource() << endl;
    ost << "Sum: " << this->GetSumm() << " rubles" << endl;
    ost << endl;
}

void Income::read(std::istream& ist)
{
	Date date;
	date.read(ist);
	this->SetDate(date);
	std::string source;
	if (std::getline(ist, source, ' '))
	{
		this->SetSource(source);
		int summ;
		if (ist >> summ)
		{
			this->SetSumm(summ);
		}
		ist.ignore();
	};
}

bool Income::ValidateSource(const std::string& source) {
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&()_+-={[]};',.";
    for (char ch : source) {
        if (alphabet.find(ch) == std::string::npos) {
            return false;
        }
    }
    return true;
}

void Income::InvalidSource(const std::string& source)
{
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&()_+-={[]};',.";

    if (source.empty() || !ValidateSource(source) || source.find_first_not_of(alphabet) != std::string::npos) {
        throw std::runtime_error("Invalid name!");
    }
    ValidateSource(source);
}

bool Income::ValidateSumm(const int& summ)
{
    if (summ < 0) {
        return false;
    }
    return true;
}

void Income::InvalidSumm(const int& summ)
{
    if (summ < 0)
    {
        throw std::runtime_error("Invalid summ!");
    }
    ValidateSumm(summ);
}