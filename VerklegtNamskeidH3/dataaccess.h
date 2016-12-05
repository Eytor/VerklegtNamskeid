#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <QtSql>

using namespace std;
// Struct declared for the vectors we use.
struct TolPers
{
    string name;
    string middleInitial;
    string lastName;
    string sex;
    int yearOfBirth;
    int yearOfDeath;
};

class DataAccess
{
public:
    DataAccess();
    // Function to retrive all info from both files that contain the list and the trash.
    void retriveInfo(vector<TolPers> &person, vector<TolPers> &tBin);
    // Function that updates the file that contains the list.
    void updateFile(vector<TolPers> person);
    // Function that updates the trash file.
    void updateTrash(vector<TolPers> trash);
    // Function that deletes the trash file.
    void emptyTrash();
};

#endif // DATAACCESS_H
