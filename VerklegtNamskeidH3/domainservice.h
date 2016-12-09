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
    //gets the type and returns it
    string getType(int list, int i);
    //gets built status and returns
    int getBuiltStatus(int list, int i);
    //gets the year when it was built and returns it
    int getYear(int list, int i);
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
    void search(vector<TempTolPers>& searchResult, vector<TempTolComp>& searchResultComputers, string keyword);
    //Function that sorts the list in different ways
    void whatToSort(int data, int col, int ord);
    //Function that edits a value of a person
    void editPerson(int list, int personID, int Selection, string s);
    //Function that adds a person to the list
    void addToList(vector<TempTolPers> input);
    //adds a computer to the list
    void addToComp(vector<TempTolComp> input);
    //function that gets the id of a computer  or person
    int getID(int list, int i);
    //Function that sends a person to the recycle bin
    void deleteFromList(int list, int id, int i);
    //Function that empties the recycle bin
    void emptyTrash(int list);
    //Function that recovers everything from the recycle bin
    void recoverFromTrash(int list, int id, int i);
    //Function that checks if string contains only digits
    bool checkIfLegitYear(string s);
    //links a person to a computer
    void linkPersonToComp(int persID, int compID);
    void displayLinks(vector<TempTolLinking> &results);
private:
    vector<TolPers> _personur;
    vector<TolComp> _computer;
    vector<TolPers> _deletedPersonur;
    vector<TolComp> _deletedComputer;
    vector<TolLinking> _linking;
    vector<TempTolComp> _tempComputer;
    vector<TempTolPers> _tempPersonur;
    vector<TempTolSearch> _tempSearch;
    vector<TempTolLinking> _tempLinking;
    DataAccess _data;
};

#endif // DOMAINSERVICE_H
