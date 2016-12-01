#include "dataaccess.h"

DataAccess::DataAccess()
{

}

void DataAccess::retriveInfo(vector<TolPers>& person)
{
    ifstream file;
    file.open ("list.txt");
    string name, middleInitial, lastName, sex;
    int birth, death;
    TolPers pers;
    while(file >> name >> middleInitial >> lastName >> sex >> birth >> death)
    {
        pers.name = name;
        pers.middleInitial = middleInitial;
        pers.lastName = lastName;
        pers.sex = sex;
        pers.yearOfBirth = birth;
        pers.yearOfDeath = death;
        person.push_back(pers);
    }
    file.close();
}
void DataAccess::updateFile(vector<TolPers> person)
{
    ofstream file;
    file.open("list.txt");
    if(file.is_open())
    {
        for(unsigned int i = 0; i < person.size(); i++)
        {
            file << person[i].name << '\t' ;
            file << person[i].middleInitial << '\t';
            file << person[i].lastName << '\t';
            file << person[i].sex << '\t';
            file << person[i].yearOfBirth << '\t';
            file << person[i].yearOfDeath << endl ;
        }
        file.close();
    }
    else{
        cout << "Error: Could not open file!";
    }
}
