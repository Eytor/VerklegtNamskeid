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

struct TolSearch
{
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

struct TolLinking
{
    int ID;
    int computerID;
    int peopleID;
};

struct TempTolPers
{
    string fullName;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

struct TempTolComp
{
    string name;
    string type;
    int built;
    int year;
};

struct TempTolSearch
{
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

struct TempTolLinking
{
    string personName;
    string computerName;
    int linkID;
};

class DataAccess
{
public:
    DataAccess();
    // Function that gets the info from the database
    void getFromDB(vector<TolComp>& computer, vector<TolPers>& person, vector<TolComp> &deletedComputer, vector<TolPers> &deletedPerson, vector<TolLinking> &linking);
    // Function that allows the user to add to the computer database
    void addToComputers(vector<TempTolComp> computer);
    // Function that allows the user to add to the people database
    void addToPeople(vector<TempTolPers> people);
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
    void addToDeletedPeople(vector<TempTolPers> people);
    // Adds a deleted computer to a recycle bin
    void addToDeletedComputers(vector<TempTolComp> computer);
    // empties recycle bin for peopl
    void emptyDeletedPeople();
    //empties recycle bin for computers
    void emptyDeletedComputers();
    //Function that allows the user to search the database
    void search(vector<TempTolPers>& persOutput,vector<TempTolComp>& compOutput, string s);
    //Function that allows the user to edit the database
    void editPerson(int list, int, int col, string);
    //Function that allows the user to sort the database
    void sort(vector<TolPers> &persVector, vector<TolComp> &compVector, int datab, int col, int ord);
    //Function that allows the user to link a person to a computer
    void linkPersonToComputer(int persID, int compID);
    void displayLinks(vector<TempTolLinking>& results);
    void deleteLinks(int peopleOrComps, int i);
private:
    int _previousCompSize;
    int _previousPeopleSize;
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
