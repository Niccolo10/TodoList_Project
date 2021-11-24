#include <iostream>
#include <fstream>
#include <limits>
#include "List.h"
#include "ListOfLists.h"

int getMaxDays(int year, int month);

int main() {

    ListOfLists LoL;
    bool programOn = true;

    newList:
    std::string listselected;
    std::cout << "Write the name of your list\n";
    std::getline(std::cin, listselected);
    List list(listselected);
    LoL.addList(list);
    int choice = 0;
    while (programOn) {

        std::cout << "_______________________________________________ \n";
        std::cout << "                     MENU'                      \n\n";
        std::cout << "\n list selected: "+ listselected+"\n";
        std::cout << "1) Add new event \n";
        std::cout << "2) Remove an event \n";
        std::cout << "3) Display all the events\n";
        std::cout << "4) Modify an event\n";
        std::cout << "5) Move to another List or create a new list\n";
        std::cout << "6) Display event Done\n";
        std::cout << "7) Display event Not done\n";
        std::cout << "8) Exit and save\n";
        std::cout << "Enter your choice and press the enter key: \n\n\n";

        std::cin >> choice;
        if (cin.fail()) {
            std::cout << "Not a number \n";
            std::cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Choose again\n";
            std::cin >> choice;
        }
        std::cin.ignore();

        switch (choice) {
            default:
                std::cout << "\nNot a Valid Choice \n";
                std::cout << "Choose again\n";
                std::cin >> choice;
                std::cin.ignore();
                break;
            case 1: {
                std::string title;
                std::string description;
                int day;
                int month;
                int year;

                std::cout << "\nWrite the title of the event:  \n";
                std::getline(std::cin, title);

                std::cout << "Write the description of the event: \n";
                std::getline(std::cin, description);

                std::cout << "Enter the year, month and day in numbers\n";
                year_selection:
                std::cout << "Year->";
                std::cin >> year;
                if (year < 0) {
                    std::cout << "impossible year --- ";
                    goto year_selection;
                }

                month_selection:
                std::cout << "Month->";
                std::cin >> month;
                if (month < 0 || month > 12) {
                    std::cout << "impossible month --- ";
                    goto month_selection;
                }

                int maxDays = getMaxDays(year, month);

                day_selection:
                std::cout << "Day ->";
                std::cin >> day;
                if (day < 0 || day > maxDays) {
                    std::cout << "impossible day --- ";
                    goto day_selection;
                }

                Date d(day, month, year);

                Event newEvent(description, title, d, false);
                LoL.addEventToList(listselected, newEvent);
            }
                break;
            case 2: {
                LoL.getList(listselected).displayEvents();
                int del;
                std::cout << "\nWrite the number of the event you want to delete and press the enter key:\n";
                std::cin >> del;
                if (del <= 0 || del > list.getSize())
                    std::cout << "Incorrect selection\n";
                else {
                    LoL.removeEventFromList(listselected, del);
                    std::cout << "Event " << del << " deleted\n";
                }
            }
                break;
            case 3:
                std::cin.clear();
                std::cout << "\n\n";
                LoL.getList(listselected).displayEvents();
                break;
            case 4: {
                LoL.getList(listselected).displayEvents();
                int mod;
                int selection;
                bool submenuOn = true;
                std::cout << "\nWrite the number of the event you want to modify and press the enter key\n";
                std::cin >> mod;
                if (mod <= 0 || mod > LoL.getList(listselected).getSize())
                    std::cout << "Incorrect selection\n";
                else {

                    while (submenuOn) {

                        std::cout << "\n\nWhat you want to do ?\n";
                        std::cout << "1) Modify title\n";
                        std::cout << "2) Modify description\n";
                        std::cout << "3) Modify data\n";
                        std::cout << "4) Mark as done\n";
                        std::cout << "5) Move it to another List\n";
                        std::cout << "6) Exit and back to menu\n";

                        std::cin >> selection;
                        if (cin.fail()) {
                            std::cout << "\nNot a number \n";
                            std::cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                            std::cout << "Choose again\n";
                            std::cin >> choice;
                        }
                        std::cin.ignore();

                        switch (selection) {
                            default:
                                std::cout << "\nNot a Valid Choice \n";
                                std::cout << "Choose again\n";
                                std::cin >> choice;
                                std::cin.ignore();
                                break;
                            case 1: {
                                std::string newTitle;
                                std::cout << "\nWrite the new title of the event:  \n";
                                std::getline(std::cin, newTitle);
                                LoL.setEventTitle(listselected, newTitle, mod);
                                break;
                            }
                            case 2: {
                                std::string newDescription;
                                std::cout << "\nWrite the new description of the event:  \n";
                                std::getline(std::cin, newDescription);
                                LoL.setEventDescription(listselected, newDescription, mod);
                                break;
                            }
                            case 3:{
                                LoL.setEventDate(listselected, mod);
                                std::cout << "Data changed \n";
                                break;
                            }
                            case 4:{
                                LoL.setEventDone(listselected, mod);
                                std::cout << "Event mark as done\n";
                                break;
                            }
                            case 5:{
                                if (LoL.getSize()<2){
                                    cout << "Not enought lists to move an item" << endl;
                                    break;
                                }
                                else {
                                    string move;
                                    cout << "To which other list you want to move the activity? Choose between.." << endl;
                                    LoL.printLists();
                                    cin.clear();
                                    getline(cin,move);
                                    if(LoL.findList(move)) {
                                        LoL.moveList(listselected, move, mod);
                                    } else
                                        std::cout << "Invalid list" << std::endl;
                                    break;
                                    }
                            }
                            case 6:
                                submenuOn= false;
                                break;

                        }
                    }
                }
                break;
            }
            case 5:{
                cout<<"Lists : "<<endl;
                LoL.printLists();
                std::string listChoice;
                while (true) {
                    cout<<"Select a list typing its name (type '0' to create a new list): ";
                    getline (cin, listChoice);
                    if (listChoice == "0")
                        goto newList;
                    else if (LoL.findList(listChoice)){
                        listselected=LoL.getList(listChoice).getName();
                        break;
                    }
                    else
                        cout << "Nome non presente in lista" << endl;
                }
                break;
            }
            case 6:{
                std::cin.clear();
                std::cout << "\n\n";
                LoL.getList(listselected).displayEvent_Done();
                break;

            }
            case 7:{
                std::cin.clear();
                std::cout << "\n\n";
                LoL.getList(listselected).displayEvent_notDone();
                break;

            }
            case 8: {
                std::string listname;
                cout << "Insert the name of the file: \n";
                std::getline(std::cin, listname);
                LoL.writeListsTxt(listname);

                std::cout << "\n\nText file saved\n";
                std::cout << "End of Program\n";
                programOn = false;
                break;
            }
        }
    }
}

int getMaxDays(int year, int month) {
    short unsigned int maxDay = 31;
    switch (month) {
        case 4: //April
        case 6: //June
        case 8: //September
        case 11: //November
            maxDay = 30;
            break;
        case 2: {

            if (year % 4 == 0) {
                if (year % 100 == 0) {
                    if (year % 400 == 0) {
                        maxDay = 29;
                    } else {
                        maxDay = 28;
                    }
                } else {
                    maxDay = 29;
                }
            } else {
                maxDay = 28;
            }
        }
    }
    return maxDay;
}