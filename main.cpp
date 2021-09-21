#include <iostream>

int main() {
    //ofstream File;
    //File.open ("File" +n+".txt");
    //File << "Write in the file";
    //File.close();

    int choice;
    bool programOn = true;
    while(programOn){

        std::cout << "_______________________________________________ \n";
        std::cout << "                     MENU'                      \n\n";
        std::cout << "1) Add new event \n";
        std::cout << "2) Remove an event \n";
        std::cout << "3) Display all the events\n";
        std::cout << "4) Exit\n";
        std::cout << "   Enter your choice and press the enter key: ";

        std::cin >> choice;

        switch (choice){

            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                std::cout << "End of Program\n";
                programOn = false;
                break;
            default:
                std::cout << "Not a Valid Choice \n";
                std::cout << "Choose again\n";
                std::cin >> choice;
                break;
        }
    }
}