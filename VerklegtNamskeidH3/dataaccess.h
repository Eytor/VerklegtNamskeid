#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <QtSql>
#include <string>
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

class DataAccess
{
public:
    DataAccess();
    // Function that gets the info from the database
    void getFromDB(vector<TolComp>& computer, vector<TolPers>& person, vector<TolComp> &deletedComputer, vector<TolPers> &deletedPerson);
    // --------------------------------------> ADD COMMENT HERE <--------------------------------------
    void addToComputers(vector<TempTolComp> computer);
    // --------------------------------------> ADD COMMENT HERE <--------------------------------------
    void addToPeople(vector<TempTolPers> people);
    // --------------------------------------> ADD COMMENT HERE <--------------------------------------
    void deletePerson(int i);

    void deleteDeletedPerson(int i);

    void deleteComputer(int i);

    void deleteDeletedComputer(int i);
    // Function to retrive all info from both files that contain the list and the trash.
    void retriveInfo(vector<TolPers> &person, vector<TolPers> &tBin);
    // Function that updates the file that contains the list.
    void updateFile(vector<TolPers> person);
    // Function that updates the trash file.
    void updateTrash(vector<TolPers> trash);
    // Function that deletes the trash file.
    void addToDeletedPeople(vector<TempTolPers> people);
    void addToDeletedComputers(vector<TempTolComp> computer);
    void emptyDeletedPeople();
    void emptyDeletedComputers();
    void search(vector<TempTolSearch>& something, string s);

    void sort(vector<TolPers> &persVector, vector<TolComp> &compVector, int datab, int col, int ord);
private:
    int _previousCompSize;
    int _previousPeopleSize;
    QSqlDatabase _db;
};

#endif // DATAACCESS_H
