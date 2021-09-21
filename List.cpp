//
// Created by nicco on 20/09/2021.
//

#include "List.h" //Cambiamento nel commit precedente

void List::addEvent(Event e) {
    eventList.push_back(e);
}

void List::deleteEvent(Event e) {
    eventList.remove(e);
}

void List::displayEvents() {
    for(auto i : eventList)
        i.display();
}