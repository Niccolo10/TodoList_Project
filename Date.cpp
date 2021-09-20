//
// Created by nicco on 20/09/2021.
//

#include "Date.h"
#include <stdexcept>

Date::Date(int day_, int month_, int year_) {
    if(year_ < 0)
        throw std::runtime_error("impossible year");
    if(month_ < 0)
        throw std::runtime_error("impossible month");
    if(day_<0)
        throw std::runtime_error("impossible day (<0) ");

    this->year = year_;
    this->month = month_;

    if (day_ > getMaxDays(this->year))
        throw std::runtime_error("impossible day");
    this->day=day_;

}

int Date::getMaxDays(int year) {
    short unsigned int maxDay = 31;
    switch (this->month) {
        case 4: //April
        case 6: //June
        case 8: //September
        case 11: //November
            maxDay = 30;
            break;
        case 2: {

            if (year % 4 == 0) {
                if (year % 100 == 0) {
                    if (year % 400 == 0) {
                        maxDay = 29;
                    } else {
                        maxDay = 28;
                    }
                } else {
                    maxDay = 29;
                }
            } else {
                maxDay = 28;
            }
        }
    }
    return maxDay;
}


int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}