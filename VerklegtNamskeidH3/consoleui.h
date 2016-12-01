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
private:
    DomainService _service;
};

#endif // CONSOLEUI_H
