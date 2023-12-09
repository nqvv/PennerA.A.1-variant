#include "income.h"

using namespace std;

void Income::print(std::ostream& ost) const
{
    ost << "Date: ";
    date.print();

    ost << "Source: " << source << endl;
    ost << "Sum: " << summ << " rubles" << endl;
    ost << endl;
}

Income Income::read(std::istream& ist)
{
    Income obj;
    obj.date = Date::read(ist);
    ist >> obj.source >> obj.summ;

    return obj;
}