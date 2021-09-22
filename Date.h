//
// Created by nicco on 20/09/2021.
//

#ifndef TODOLIST_PROJECT_DATE_H
#define TODOLIST_PROJECT_DATE_H


class Date {
public:
    explicit Date(int day,int month, int year);

    int getDay() const;

    int getMonth() const;

    int getYear() const;


private:
    int day,month,year;


};


#endif //TODOLIST_PROJECT_DATE_H
