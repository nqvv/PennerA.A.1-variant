#pragma once

#include <string>

#include "date.h"

struct Income {
    Date date;
    std::string source;
    int summ;

    void print(std::ostream& ost = std::cout) const;
    static Income read(std::istream& ist);
};

