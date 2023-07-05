#TodoApp

This is a simple command-line application that allows you to create and manage todo lists. It provides various features to add, remove, modify, and display events in different lists. The application uses C++ programming language and provides a text-based interface for interaction.
Prerequisites

Before running the application, make sure you have the following:

    C++ compiler installed
    Required header files: iostream, fstream, limits
    Custom header files: List.h, ListOfLists.h (provided with the project)

Getting Started

To use the TodoApp, follow these steps:

    Download the source code and save it to your local machine.
    Open the terminal or command prompt and navigate to the directory where you saved the source code.
    Compile the source code using the C++ compiler. For example:

    mathematica

g++ -o todoapp todoapp.cpp List.cpp ListOfLists.cpp

Run the compiled executable. For example:

bash

    ./todoapp

Usage

Upon running the application, you will be presented with a menu to interact with the TodoApp. Here are the available options:

    Add new event: Allows you to add a new event to the current list. You will be prompted to enter the title, description, and date of the event.
    Remove an event: Displays all the events in the current list and allows you to remove a specific event by entering its number.
    Display all the events: Shows all the events in the current list.
    Modify an event: Displays all the events in the current list and allows you to modify a specific event by entering its number. You can change the title, description, date, mark it as done, or move it to another list.
    Move to another List or create a new list: Displays the available lists and allows you to switch to another list or create a new one.
    Display event Done: Shows only the events marked as done in the current list.
    Display event Not done: Shows only the events not marked as done in the current list.
    Exit and save: Exits the application and saves the lists to a text file. You will be prompted to enter the name of the file.

Customization

You can customize the application by modifying the source code according to your requirements. You can add more features, change the user interface, or extend the functionality of the TodoApp.
Author

This TodoApp was developed by [Your Name]. Feel free to reach out to [your email] for any questions or feedback.
