#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "domainservice.h"
using namespace std;

class ConsoleUI
{
public:
    ConsoleUI();
    //Runs the main program, where the user can select what he can do
    void run();
    //Outputs the sort menu and lets the user pick what way to sort the list
    void sortSelector();
    //Prints out information about one person
    void printPerson(int list, int i);
    // --------------------------------------> ADD COMMENT HERE <--------------------------------------
    void printComputer(int list, int i);
    //Displays a list of all the person
    void displayList(int list);
    //Takes in input from user and searches for it
    void search();
    //Outputs the header for displayList()
    void giveHead();
    //Outputs a list of all people and gives the user an option to edit one of them
    void edit();
    //Gives the user an option to add one or more people to the list
    void addToList();
    //Adds a computer to the database
    void addToComp();
    //Sends a person to the recycle bin
    void deleteFromList(int list);
    // --------------------------------------> ADD COMMENT HERE <--------------------------------------
    void deleteComputer();
    // --------------------------------------> ADD COMMENT HERE <--------------------------------------
    void deleteSelect();
    /*Gives the user options to display the recycle bin,
    recover a person from the recycle or empty the recycle bin*/
    void trashSelector();
    //Recovers a person from the recycle bin
    void recoverFromTrash(int list);
private:
    DomainService _service;
    vector<TempTolPers> _tempInput;
    vector<TempTolComp> _tempCompInput;
};

#endif // CONSOLEUI_H
