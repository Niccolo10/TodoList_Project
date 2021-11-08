//
// Created by nicco on 20/09/2021.
//

#include "Event.h"
#include <iostream>

Event::Event(const std::string &d,const std::string &t, const Date &dat, bool done) : eventDate(dat) {
    this->eventDescription = d;
    this->eventTitle = t;
    this->done = done;
}

bool Event::operator==(Event e) const {
    return eventTitle == e.eventTitle && eventDescription == e.eventDescription ;
}

const std::string &Event::getEventDescription() const {
    return eventDescription;
}

void Event::setEventDescription(const std::string &eventDescription) {
    Event::eventDescription = eventDescription;
}

const std::string &Event::getEventTitle() const {
    return eventTitle;
}

void Event::setEventTitle(const std::string &eventTitle) {
    Event::eventTitle = eventTitle;
}

const Date &Event::getEventDate() const {
    return eventDate;
}

void Event::setEventDate(const Date &eventDate) {
    Event::eventDate = eventDate;
}

bool Event::isDone() const {
    return done;
}

void Event::setDone(bool done) {
    Event::done = done;
}
void Event::display() const {
    std::cout<<"Title:        " << eventTitle << std::endl;
    std::cout<<"Description:  '" << eventDescription << " '" <<std::endl;
    std::cout<<"Date:         " << eventDate.getDay() << "/" << eventDate.getMonth() << "/" << eventDate.getYear() << std::endl;
}

