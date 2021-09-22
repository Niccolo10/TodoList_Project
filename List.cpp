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
    for(auto it : eventList){
        File << "Title:        "+ it.getEventTitle()+"\n";
        File << "Description:  "+it.getEventDescription()+"\n";
    }
    File.close();
}