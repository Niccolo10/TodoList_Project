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

    explicit List(const std::string &n);

    void addEvent(const Event &e);
    void deleteEvent(const Event &e);
    void deleteEvent(int pos);
    void setEventDone(const Event &e);
    void setEventDone(int position);
    const void displayEvents() const ;
    void displayEvent_notDone() const ;
    void displayEvent_Done() const ;
    int getSize();
    Event getEvent(int position) const ;
    const std::string &getName() const;

    void writeEvents(std::string listName, std::ofstream& File);

    void setTitle(int pos, std::string newTitle);
    void setDescription(int pos, std::string newDescription);
    void setDate(int pos);

private:

    std::list<Event> eventList;
    std::string listName;

};


#endif //TODOLIST_PROJECT_LIST_H
