//
// Created by nicco on 20/09/2021.
//

#include "Date.h"
#include <stdexcept>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}


int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

