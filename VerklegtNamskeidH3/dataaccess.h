#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

struct TolPers{
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
    void test();
    void retriveInfo(vector<TolPers> &person);
    void updateFile(vector<TolPers> person);
private:

};

#endif // DATAACCESS_H