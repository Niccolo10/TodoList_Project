//
// Created by nicco on 20/09/2021.
//

#ifndef TODOLIST_PROJECT_LIST_H
#define TODOLIST_PROJECT_LIST_H


#include <list>
#include "Event.h" //Cambiamento nel commit precedente

using namespace std;

class List{
public:

    void addEvent(Event e);
    void deleteEvent(Event e);
    void displayEvents();


private:

    std::list<Event> eventList;

};


#endif //TODOLIST_PROJECT_LIST_H
