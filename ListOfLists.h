//
// Created by nicco on 08/10/2021.
//

#ifndef TODOLIST_PROJECT_LISTOFLISTS_H
#define TODOLIST_PROJECT_LISTOFLISTS_H

#include <iostream>
#include "List.h"

class ListOfLists {
public:
    void addList (const List &l);
    void addEventToList (const std::string &name, const Event &e);
    void removeEventFromList (const std::string &name,const Event &e);
    void removeEventFromList (const std::string &name, int activityPos);
    void setEventDone (const std::string &name, int pos);
    void setEventTitle(const std::string &name, std::string &newTitle, int pos);
    void setEventDescription(const std::string &name,std::string &newDescription , int pos);
    void setEventDate (const std::string &name, int pos);
    void moveList (const std::string &source,const std::string &destination, const Event &e );
    void printLists () const;
    List getList (const std::string &n) const;
    int getSize() const;
    bool findList(const std::string &n) const;

    void writeListsTxt (std::string &listName) ;

private:
    std::list<List> lists;
};


#endif //TODOLIST_PROJECT_LISTOFLISTS_H
