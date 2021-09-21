//
// Created by nicco on 20/09/2021.
//

#ifndef TODOLIST_PROJECT_EVENT_H
#define TODOLIST_PROJECT_EVENT_H


#include <string>
#include "Date.h"

class Event {
public:
    Event (std::string description, std::string title, Date date);

    const std::string &getEventDescription() const;

    void setEventDescription(const std::string &eventDescription);

    const std::string &getEventTitle() const;

    void setEventTitle(const std::string &eventTitle);

    const Date &getEventDate() const;

    void setEventDate(const Date &eventDate);

    void display()const;

private:
    std::string eventDescription;
    std::string eventTitle;
    Date eventDate;

};


#endif //TODOLIST_PROJECT_EVENT_H
