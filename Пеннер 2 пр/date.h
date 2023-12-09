#pragma once

#include <iostream>

struct Date {
    int year;
    int month;
    int day;
        
    void print(std::ostream& ost = std::cout) const;
    static Date read(std::istream& ist);
};

