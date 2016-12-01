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
    void printPerson(int i);
    void displayList();
    void search();
    int editSelect();
    void edit();
private:
    DomainService _service;
};

#endif // CONSOLEUI_H
