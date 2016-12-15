#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <QtSql>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
// Struct declared for the vectors we use.
struct TolPers
{
    int ID;
    string fullName;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

struct TolComp
{
    int ID;
    string name;
    string type;
    int built;
    int year;
};


struct TolLinking
{
    int ID;
    int computerID;
    int peopleID;
};


struct TempTolLinking
{
    string personName;
    string computerName;
    int linkID;
};

struct TolPersLink
{
    int ID;
    string  personName;
};

struct TolCompLink
{
    int linkID;
    int compID;
    string compName;
};

class DataAccess
{
public:
    DataAccess();
    // Function that gets the info from the database
    void getFromDB(vector<TolComp>& computer, vector<TolPers>& person, vector<TolComp> &deletedComputer, vector<TolPers> &deletedPerson, vector<TolLinking> &linking);
    // Function that allows the user to add to the computer database
    void addToComputers(vector<TolComp> computer);
    // Function that allows the user to add to the people database
    void addToPeople(vector<TolPers> people);
    // Function that allows the user to add to delete a person
    void deletePerson(int i);
    //delets a person from the trashbin
    void deleteDeletedPerson(int i);
    //deletes a compputer
    void deleteComputer(int i);
    //delets a computer from the trashbin
    void deleteDeletedComputer(int i);
    // Function to retrive all info from both files that contain the list and the trash.
    void retriveInfo(vector<TolPers> &person, vector<TolPers> &tBin);
    // Function that updates the file that contains the list.
    void updateFile(vector<TolPers> person);
    // Function that updates the trash file.
    void updateTrash(vector<TolPers> trash);
    // Function that deletes the trash file.
    void addToDeletedPeople(vector<TolPers> people);
    // Adds a deleted computer to a recycle bin
    void addToDeletedComputers(vector<TolComp> computer);
    // empties recycle bin for peopl
    void emptyDeletedPeople();
    //empties recycle bin for computers
    void emptyDeletedComputers();
    //Function that allows the user to search the database
    void searchScientists(vector<TolPers> &persOutput, string s);


    void searchComputers(vector<TolComp>& compOutput, string s);
    //Function that allows the user to edit the database
    void editPerson(int theId, string name, string theGender, string yearOfBirth, string yearOfDeath);
    void editComputer(int theId, string theName, string theType, bool isBuilt, string theYear);

    //Function that allows the user to sort the database
    void sort(vector<TolPers> &persVector, vector<TolComp> &compVector, int datab, int col, int ord);
    //Function that allows the user to link a person to a computer
    void linkPersonToComputer(int persID, int compID);
    //Displays the links
    void displayLinks(vector<TempTolLinking>& results);
    void displayScientistsWithLinks(vector<TolPersLink>& results);
    //Deletes the links
    void deleteLinks(int peopleOrComps, int i);
    void displayCompsFromLink(int personID, vector<TolCompLink> &results);
private:
    int _previousCompSize;
    int _previousPeopleSize;
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
