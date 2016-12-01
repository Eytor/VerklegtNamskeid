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
    void printPerson(int i);
    void displayList();
    void search();
    int editSelect();
    void edit();
    void addToList();
private:
    DomainService _service;
    vector<TolPers> _tempInput;
};

#endif // CONSOLEUI_H
