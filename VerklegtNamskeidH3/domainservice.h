#ifndef DOMAINSERVICE_H
#define DOMAINSERVICE_H
#include "dataaccess.h"
#include <iomanip>
#include <stdio.h>
#include <cstring>

using namespace std;

class DomainService
{
public:
    DomainService();
    void retriveList();
    void updateFile();
    void updateTrash();
    void addToList();
    string getName(int list, int i);
    string getFirstName(int i);
    string getMiddleInitial(int i);
    string getLastName(int i);
    string getGender(int list, int i);
    int getYoB(int list, int i);
    int getYoD(int list, int i);
    int getListSize(int list);
    bool getEmptyStatus(int list);
    void printPerson(int list, int i);
    void displayList();
    string convertToLower(string unfilteredString);
    vector<int> search(string keyword);
    void whatToSort(int selector);
    void edit(int personID, int Selection);
    void addToList(vector<TolPers> input);
    void deletePerson(int i);
    void emptyTrash();
    void recoverFromTrash(int i);
private:
    vector<TolPers> _personur;
    vector<TolPers> _trashBin;
    DataAccess _data;
    int _count;
};

#endif // DOMAINSERVICE_H
