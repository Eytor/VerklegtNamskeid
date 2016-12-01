#ifndef DOMAINSERVICE_H
#define DOMAINSERVICE_H
#include "dataaccess.h"
#include <iomanip>

using namespace std;

class DomainService
{
public:
    DomainService();
    void retriveList();
    void updateFile();
    void addToList();
    string getName(int i);
    string getGender(int i);
    int getYoB(int i);
    int getYoD(int i);
    int getListSize();
    bool getEmptyStatus();
    void printPerson(int i);
    void displayList();
    string convertToLower(string unfilteredString);
    void search(string keyword);
private:
    vector<TolPers> _personur;
    int _count;
};

#endif // DOMAINSERVICE_H
