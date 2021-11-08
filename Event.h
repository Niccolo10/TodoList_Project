//
// Created by nicco on 20/09/2021.
//

#ifndef TODOLIST_PROJECT_EVENT_H
#define TODOLIST_PROJECT_EVENT_H


#include <string>
#include "Date.h"

class Event {
public:
    Event (const std::string &d, const std::string &t, const Date &dat , bool done );

    bool operator==(Event e) const ;

    const std::string &getEventDescription() const;

    void setEventDescription(const std::string &eventDescription);

    const std::string &getEventTitle() const;

    void setEventTitle(const std::string &eventTitle);

    const Date &getEventDate() const;

    void setEventDate(const Date &eventDate);

    void display()const;

    bool isDone() const;

    void setDone(bool done);

private:
    std::string eventDescription;
    std::string eventTitle;
    Date eventDate;
    bool done;

};


#endif //TODOLIST_PROJECT_EVENT_H
