//
// Created by nicco on 08/10/2021.
//

#include "ListOfLists.h"
#include <iostream>
#include <fstream>

void ListOfLists::addList(const List &l) {
    lists.push_back(l);
}


void ListOfLists::addEventToList(const std::string &name, const Event &e) {
    auto it = lists.begin();
    while (it != lists.end()) {
        if ((*it).getName() == name) {
            (*it).addEvent(e);
        }
        it++;
    }
}

void ListOfLists::removeEventFromList(const std::string &name, const Event &a) {
    auto it = lists.begin();
    while (it != lists.end()) {
        if ((*it).getName() == name) {
            (*it).deleteEvent(a);
        }
        it++;
    }
}

void ListOfLists::removeEventFromList(const std::string &name, int pos) {
    auto it = lists.begin();
    while (it != lists.end()) {
        if ((*it).getName() == name) {
            (*it).deleteEvent(pos);
        }
        it++;
    }
}

void ListOfLists::setEventDone(const std::string &name, int pos) {
    auto it = lists.begin();
    while (it != lists.end()) {
        if ((*it).getName() == name) {
            (*it).setEventDone(pos);
        }
        it++;
    }
}

void ListOfLists::setEventTitle(const std::string &name, std::string &newTitle, int pos) {
    auto it = lists.begin();
    while (it != lists.end()) {
        if ((*it).getName() == name) {
            (*it).setTitle(pos, newTitle);
        }
        it++;
    }
}

void ListOfLists::setEventDescription(const std::string &name, std::string &newDescription, int pos) {
    auto it = lists.begin();
    while (it != lists.end()) {
        if ((*it).getName() == name) {
            (*it).setDescription(pos, newDescription);
        }
        it++;
    }
}

void ListOfLists::setEventDate(const std::string &name, int pos) {
    auto it = lists.begin();
    while (it != lists.end()) {
        if ((*it).getName() == name) {
            (*it).setDate(pos);
        }
        it++;
    }
}


void ListOfLists::moveList(const std::string &source, const std::string &destination, const Event &a) {
    addEventToList(destination, a);
    removeEventFromList(source, a);
}

void ListOfLists::printLists() const {
    for (const auto it : lists)
        std::cout << it.getName() << std::endl;
}

List ListOfLists::getList(const std::string &n) const {
    auto it = lists.begin();
    while (it != lists.end()) {
        if ((*it).getName() == n) {
            return (*it);
        }
        it++;
    }
}

int ListOfLists::getSize() const {
    return lists.size();
}

bool ListOfLists::findList(const std::string &n) const {
    for (const auto it : lists) {
        if (it.getName() == n)
            return true;
    }
    return false;
}

void ListOfLists::writeListsTxt(std::string &listName) {
    ofstream File;
    File.open("File_" + listName + ".txt");
    for (auto it : lists) {
        File << "Nome della lista: " + it.getName() + "\n\n";
        (it).writeEvents(listName, File);
    }
    File.close();

}