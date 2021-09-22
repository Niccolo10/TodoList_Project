//
// Created by nicco on 20/09/2021.
//

#include <iostream>
#include <fstream>
#include "List.h"

void List::addEvent(Event e) {
    eventList.push_back(e);
}

void List::deleteEvent(Event e) {
    eventList.remove(e);
}

void List::deleteEvent(int pos) {
    auto i = eventList.begin();
    for (int i=1;i<pos;i++)
        i++;
    eventList.remove(*i);
}

void List::displayEvents() {

    int eventNumber = 1;
    for(auto i : eventList){
        std::cout << eventNumber++ << ")\n";
        i.display();
        std::cout << "\n";
    }
}

int List::getMaxDays(int year, int month) {
    short unsigned int maxDay = 31;
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

int List::getSize() {
    return eventList.size();
}

void List::writeEvents(std::string listName) {
    ofstream File;
    File.open("File_"+listName+".txt");
    int day,month,year;
    for(auto it : eventList){
        day = it.getEventDate().getDay();
        month=it.getEventDate().getMonth();
        year=it.getEventDate().getYear();
        File << "Title:        "+ it.getEventTitle()+"\n";
        File << "Description:  "+it.getEventDescription()+"\n";
        File << "Data:         "+std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year)+"\n\n";
    }
    File.close();
}

void List::setTitle(int pos, std::string newTitle) {
    auto i = eventList.begin();
    std::advance(i,pos-1);
    i->setEventTitle(newTitle);
    std::cout << "Title changed \n";
}

void List::setDescription(int pos, std::string newDescription) {
    auto i = eventList.begin();
    std::advance(i,pos-1);
    i->setEventDescription(newDescription);
    std::cout << "Description changed \n";
}

void List::setDate(int pos) {

    int day;
    int month;
    int year;

    std::cout << "Enter the new year, month and day in numbers\n";
    year_selection:
    std::cout << "Year->";
    std::cin >> year;
    if (year < 0) {
        std::cout << "impossible year";
        goto year_selection;
    }

    month_selection:
    std::cout << "Month->";
    std::cin >> month;
    if (month < 0 || month > 12) {
        std::cout << "impossible month";
        goto month_selection;
    }

    int maxDays = getMaxDays(year, month);

    day_selection:
    std::cout << "Day ->";
    std::cin >> day;
    if (day < 0 || day > maxDays) {
        std::cout << "impossible day";
        goto day_selection;
    }

    Date newDate(day, month, year);
    auto i = eventList.begin();
    std::advance(i,pos-1);
    i->setEventDate(newDate);
    std::cout << "Data changed \n";


}