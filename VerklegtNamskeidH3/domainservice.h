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
    //Function that retrives the list
    void retriveList();
    //Function that updates the list.txt file
    void updateFile();
    //Function that updates the bin.txt file
    void updateTrash();
    //Function that takes first name, middle initial and last name
    //and combines them into one string and returns it
    string getName(int list, int i);
    //Gets the first name and returns it
    string getFirstName(int i);
    //Gets the middle initial and returns it
    string getMiddleInitial(int i);
    //Gets the last name and returns it
    string getLastName(int i);
    //Gets the gender and returns it
    string getGender(int list, int i);
    //Gets the year of birth
    int getYoB(int list, int i);
    //Gets the year of death
    int getYoD(int list, int i);
    //Gets the size of the list
    int getListSize(int list);
    //Checks if the list is empty
    bool getEmptyStatus(int list);
    //Converts a string to lower
    string convertToLower(string unfilteredString);
    //Function that recives a string and searches for it on the list
    vector<int> search(string keyword);
    //Function that sorts the list in different ways
    void whatToSort(int selector);
    //Function that edits a value of a person
    void edit(int personID, int Selection, string s);
    //Function that adds a person to the list
    void addToList(vector<TempTolPers> input);

    void addToComp(vector<TempTolComp> input);
    //Function that sends a person to the recycle bin
    void deletePerson(int i);
    //Function that empties the recycle bin
    void emptyTrash();
    //Function that recovers everything from the recycle bin
    void recoverFromTrash(int i);
    //Function that checks if string contains only digits
    bool checkIfLegitYear(string s);
private:
    vector<TolPers> _personur;
    vector<TolComp> _computer;
    vector<TempTolComp> _tempComputer;
    vector<TempTolPers> _tempPersonur;
    vector<TolPers> _trashBin;
    DataAccess _data;
    int _count;
};

#endif // DOMAINSERVICE_H
