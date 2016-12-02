#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "domainservice.h"
using namespace std;

class ConsoleUI
{
public:
    ConsoleUI();
    int selection();
    int sortSelection();
    void run();
    void sortSelector();
    void printPerson(int list, int i);
    void displayList(int list);
    void search();
    void giveHead();
    int editSelect();
    void edit();
    void addToList();
    void deletePerson();
    void displayTrash();
    int trashSelection();
    void trashSelector();
    void recoverFromTrash();
private:
    DomainService _service;
    vector<TolPers> _tempInput;
};

#endif // CONSOLEUI_H
