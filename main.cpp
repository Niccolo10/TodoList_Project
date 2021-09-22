#include <iostream>
#include <fstream>
#include <limits>
#include "List.h"


int main() {

    std::string listName;
    std::cout << "Write the name of your list\n";
    std::cin >> listName;
    List list;
    int choice;
    bool programOn = true;
    while (programOn) {

        std::cout << "_______________________________________________ \n";
        std::cout << "                     MENU'                      \n\n";
        std::cout << "1) Add new event \n";
        std::cout << "2) Remove an event \n";
        std::cout << "3) Display all the events\n";
        std::cout << "4) Modify an event\n";
        std::cout << "5) Exit and save\n";
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

                int maxDays = list.getMaxDays(year, month);

                day_selection:
                std::cout << "Day ->";
                std::cin >> day;
                if (day < 0 || day > maxDays) {
                    std::cout << "impossible day --- ";
                    goto day_selection;
                }

                Date d(day, month, year);

                Event newEvent(description, title, d);
                list.addEvent(newEvent);
            }
                break;
            case 2: {
                list.displayEvents();
                int del;
                std::cout << "\nWrite the number of the event you want to delete and press the enter key:\n";
                std::cin >> del;
                if (del <= 0 || del > list.getSize())
                    std::cout << "Incorrect selection\n";
                else {
                    list.deleteEvent(del);
                    std::cout << "Event " << del << " deleted\n";
                }
            }
                break;
            case 3:
                std::cin.clear();
                std::cout << "\n\n";
                list.displayEvents();
                break;
            case 4: {
                list.displayEvents();
                int mod;
                int selection;
                bool submenuOn = true;
                std::cout << "\nWrite the number of the event you want to modify and press the enter key\n";
                std::cin >> mod;
                if (mod <= 0 || mod > list.getSize())
                    std::cout << "Incorrect selection\n";
                else {

                    while (submenuOn) {

                        std::cout << "\n\nWhat you want to do ?\n";
                        std::cout << "1) Modify title\n";
                        std::cout << "2) Modify description\n";
                        std::cout << "3) Modify data\n";
                        std::cout << "4) Exit and back to menu\n";

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
                                list.setTitle(mod, newTitle);
                                break;
                            }
                            case 2: {
                                std::string newDescription;
                                std::cout << "\nWrite the new description of the event:  \n";
                                std::getline(std::cin, newDescription);
                                list.setDescription(mod, newDescription);
                                break;
                            }
                            case 3:{
                                list.setDate(mod);
                                break;
                            }
                            case 4:
                                submenuOn= false;
                                break;

                        }
                    }
                }
                break;
            }
            case 5: {
                list.writeEvents(listName);
                std::cout << "\n\nText file saved\n";
                std::cout << "End of Program\n";
                programOn = false;
                break;
            }
        }
    }
}