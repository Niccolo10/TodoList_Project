//
// Created by nicco on 20/09/2021.
//

#ifndef TODOLIST_PROJECT_LIST_H
#define TODOLIST_PROJECT_LIST_H


#include <fstream>
#include <iostream>

using namespace std;

class List{
public:
    List (string n): name (n){
        ofstream File;
        File.open ("File" +n+".txt");
        File << "Write in the file";
        File.close();

    }

private:
    string name;

};


#endif //TODOLIST_PROJECT_LIST_H
