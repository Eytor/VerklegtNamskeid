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
    int sortSelector(int list);
    //Prints out information about one person
    void printPerson(int list, int i);
    //prints out information about a computer
    void printComputer(int list, int i);
    //Displays a list of all the person
    void displayList(int list);
    //Takes in input from user and searches for it
    void search();
    //Outputs the header for displayList()
    void giveHead(int i);
    //Outputs a list of all people and gives the user an option to edit one of them
    void edit();
    //Gives the user an option to add one or more people to the list
    void addToList();
    //Adds a computer to the database
    void addToComp();
    //Sends a person to the recycle bin
    void deleteFromList(int list);
    //deletes a person from the list
    void deleteComputer();
    //deletes a computer from the list
    void deleteSelect();
    /*Gives the user options to display the recycle bin,
     recover a person from the recycle or empty the recycle bin*/
    void trashSelector();
    //Recovers a person from the recycle bin
    void recoverFromTrash(int list);
    //Selects a list to order
    void selectListToOrder();
    //links a scientist to a computer
    void linkPeopleToComps();
    //Displays links between computers and persons
    void displayLinks();
    //these following functions allow the user to play tic tac toe
    void epic();
    void printGrid (char grid[3][3]);
    void insertPosition(char grid[3][3], char player);
    void XorY(char& player);
    char didIWin(char grid[3][3]);

private:
    DomainService _service;
    vector<TempTolPers> _tempInput;
    vector<TempTolComp> _tempCompInput;
};

#endif // CONSOLEUI_H
