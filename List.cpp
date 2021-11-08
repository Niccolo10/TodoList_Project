//
// Created by nicco on 20/09/2021.
//

#include <iostream>
#include <fstream>
#include "List.h"

List::List(const std::string &n) {
    this->listName = n;
}

void List::addEvent(const Event &e) {
    eventList.push_back(e);
}

void List::deleteEvent(const Event &e) {
    eventList.remove(e);
}

void List::deleteEvent(int pos) {
    auto i = eventList.begin();
    for (int i=1;i<pos;i++)
        i++;
    eventList.remove(*i);
}

void List::setEventDone(const Event &e){
    for (auto it : eventList){
        if (it==e)
            it.setDone(true);
    }
}

void List::setEventDone(int pos){
    auto it=eventList.begin();
    for (int i=1;i<pos;i++)
        it++;
    (*it).setDone(true);
}


const void List::displayEvents() const {

    int eventNumber = 1;
    if (eventList.size()) {
        for (auto it : eventList) {
            std::cout << eventNumber++ << ")";
            if (it.isDone())
                std::cout << "DONE";
            std::cout << "\n";
            it.display();
            std::cout << "\n";
        }
    }
    else {
        std::cout<<"List is empty"<<std::endl;
    }
}

void List::displayEvent_notDone() const {
    for (auto it : eventList){
        if (!it.isDone()) {
            it.display();
            std::cout<<std::endl;
        }
    }
}

void List::displayEvent_Done() const {
    for (auto it : eventList) {
        if (it.isDone())
            it.display();
    }
}

int List::getSize() {
    return eventList.size();
}

Event List::getEvent(int position) const {
    auto it=eventList.begin();
    for (int i=1;i<position;i++)
        it++;
    return *it;
}

const std::string &List::getName() const {
    return listName;
}


void List::writeEvents(std::string listName, std::ofstream& File) {

    int day,month,year;
    for(auto it : eventList){
        day = it.getEventDate().getDay();
        month=it.getEventDate().getMonth();
        year=it.getEventDate().getYear();
        File << "Title:        "+ it.getEventTitle()+"\n";
        File << "Description:  "+it.getEventDescription()+"\n";
        File << "Data:         "+std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year)+"\n\n";
        if (it.isDone())
            File << " -- DONE -- \n\n";
    }
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
    std::cout << "Year->";
    std::cin >> year;
    year_selection:
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

    day_selection:
    std::cout << "Day ->";
    std::cin >> day;
    if (day < 0 || day > 31) {
        std::cout << "impossible day";
        goto day_selection;
    }

    Date newDate(day, month, year);
    auto i = eventList.begin();
    std::advance(i,pos-1);
    i->setEventDate(newDate);
    std::cout << "Data changed \n";

}
