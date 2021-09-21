//
// Created by nicco on 20/09/2021.
//

#include "Event.h"
#include <iostream>

Event::Event(std::string description, std::string title, Date date) : eventDate(date) {
    this->eventDescription = description;
    this->eventTitle = title;
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

void Event::display() const {
    std::cout<<"Title:        " << eventTitle << std::endl;
    std::cout<<"Description:  '" << eventDescription << " '" <<std::endl;
    std::cout<<"Date:         " << eventDate.getDay() << "/" << eventDate.getMonth() << "/" << eventDate.getYear() << std::endl;
}
