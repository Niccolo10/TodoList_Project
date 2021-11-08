//
// Created by nicco on 20/09/2021.
//

#include "Date.h"
#include <stdexcept>

Date::Date(int aDay, int aMonth, int aYear) {
    if (aYear < 0 or aDay < 1 or aMonth < 1 or aMonth > 12 or aDay > getMaxDays(aYear, aMonth)){
        throw std::runtime_error ("Date not valid");
    }
    this->day = aDay;
    this->month = aMonth;
    this->year = aYear;
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

int Date::getMaxDays(int year, int month) const  {
    int maxDay = 31;
    switch (month) {
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
