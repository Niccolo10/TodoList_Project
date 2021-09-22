//
// Created by nicco on 20/09/2021.
//

#ifndef TODOLIST_PROJECT_LIST_H
#define TODOLIST_PROJECT_LIST_H


#include <list>
#include "Event.h"

using namespace std;

class List{
public:

    void addEvent(Event e);
    void deleteEvent(Event e);
    void deleteEvent(int pos);
    void displayEvents();
    void writeEvents(std::string listName);
    int getMaxDays (int year, int month);
    int getSize();

private:

    std::list<Event> eventList;

};


#endif //TODOLIST_PROJECT_LIST_H
