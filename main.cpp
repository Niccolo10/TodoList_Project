#include <iostream>
#include <fstream>
#include <limits>
#include "List.h"


int main() {

    std::string listName;
    std::cout << "Write the name of your list\n";
    std::cin >>listName;
    List list;
    int choice;
    bool programOn = true;
    while(programOn){

        std::cout << "_______________________________________________ \n";
        std::cout << "                     MENU'                      \n\n";
        std::cout << "1) Add new event \n";
        std::cout << "2) Remove an event \n";
        std::cout << "3) Display all the events\n";
        std::cout << "4) Exit and save\n";
        std::cout << "Enter your choice and press the enter key: \n";

        std::cin >> choice;
        if(cin.fail()){
            std::cout <<"Not a number \n";
            std::cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Choose again\n";
            std::cin >> choice;
        }
        std::cin.ignore();

        switch (choice){
            default:
                std::cout << "Not a Valid Choice \n";
                std::cout << "Choose again\n";
                std::cin >> choice;
                std::cin.ignore();
                break;
            case 1:{
                std::string title;
                std::string description;
                int day;
                int month;
                int year;

                std::cout << "Write the title of the event:  \n";
                std::getline(std::cin,title);

                std::cout << "Write the description of the event: \n";
                std::getline(std::cin, description);

                std::cout << "Enter the year, day, month in numbers\n";
                year_selection:
                std::cout << "Year->";
                std::cin >> year;
                if(year < 0){
                    std::cout << "impossible year";
                    goto year_selection;
                }

                month_selection:
                std::cout << "Month->";
                std::cin >> month;
                if(month < 0 || month > 12){
                    std::cout << "impossible month";
                    goto month_selection;
                }

                int maxDays = list.getMaxDays(year,month);

                day_selection:
                std::cout << "Day ->";
                std::cin >> day;
                if(day < 0 || day > maxDays){
                    std::cout << "impossible day";
                    goto day_selection;
                }

                Date d(day,month,year);

                Event newEvent(description,title,d);
                list.addEvent(newEvent);
            }
                break;
            case 2:{
                list.displayEvents();
                int del ;
                std::cout << "Write the number of the event you want to delete and press the enter key:\n";
                std::cin >> del;
                if(del <=0 || del > list.getSize())
                    std::cout << "Incorrect selection\n";
                else{
                    list.deleteEvent(del);
                    std::cout << "Event " << del << " deleted\n";
                }
            }
                break;
            case 3:
                std::cin.clear();
                list.displayEvents();
                break;
            case 4: {
                list.writeEvents(listName);
                std::cout << "Text file saved\n";
                std::cout << "End of Program\n";
                programOn = false;
                break;
            }
        }
    }
}