#include "domainservice.h"


DomainService::DomainService()
{

}

void DomainService::retriveList()
{
    DataAccess data;
    data.retriveInfo(_personur);
}

void DomainService::updateFile()
{
    DataAccess data;
    data.updateFile(_personur);
}

void DomainService::addToList()
{
    int numOfPeople;
        cout << "Select number of people: ";
        cin >> numOfPeople;
        while (cin.fail()||numOfPeople<0)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid size. Select number from 1-100 ";
            cin >> numOfPeople;
        }

        TolPers pers;
        for(int i = 0; i < numOfPeople; i++)
        {

            cout << "Name: ";
            cin >> pers.name;
            cout << "Middle initial, enter '0' if empty: ";
            cin >> pers.middleInitial;
            cout << "Last name: ";
            cin >> pers.lastName;
            cout << "Gender: ";
            cin >> pers.sex;

            cout << "Year of birth: ";
            cin >> pers.yearOfBirth;
            while (cin.fail()||pers.yearOfBirth <= 0 || pers.yearOfBirth > 2251)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid size. Enter year from 1-2250 ";
                cin >> pers.yearOfBirth;
            }

            cout << "Year of Death, enter '0' if alive: ";
            cin >> pers.yearOfDeath;
           while (cin.fail() || pers.yearOfDeath < 0 || pers.yearOfDeath > 2251 ||
                 ((pers.yearOfDeath < pers.yearOfBirth) && pers.yearOfDeath !=0))
           {
               cin.clear();
               cin.ignore(100, '\n');
               cout << "Invalid size. Enter year from 0-2250 ";
               cin >> pers.yearOfDeath;
           }


            _personur.push_back(pers);
        }
        updateFile();
}

string DomainService::getName(int i)
{
    string fullName;
    if(_personur[i].middleInitial != "0")
    {
        fullName = _personur[i].name + " " + _personur[i].middleInitial + " " + _personur[i].lastName;
    }
    else
    {
        fullName = _personur[i].name + " " + _personur[i].lastName;
    }
    return fullName;
}

string DomainService::getGender(int i)
{
    string gender = _personur[i].sex;
    return gender;
}

int DomainService::getYoB(int i)
{
    int YoD = _personur[i].yearOfBirth;
    return YoD;
}

int DomainService::getYoD(int i)
{
    int YoD =_personur[i].yearOfDeath;
    return YoD;
}

int DomainService::getListSize()
{
    int size = _personur.size();
    return size;
}
bool DomainService::getEmptyStatus()
{
    bool empty = _personur.empty();
    return empty;
}

void DomainService::printPerson(int i)
{
    const char seperator = ' ';
    const int sexWidth = 5;
    const int yearWidth = 6;
    const int nameWidth = 25;
    string fullName = getName(i);
    string gender = getGender(i);
    int YoB = getYoB(i);
    int YoD = getYoD(i);

    cout << left << setw(nameWidth) << setfill(seperator) << fullName;
    cout << left << setw(sexWidth) << setfill(seperator) << gender;
    if(YoD != 0)
    {
        cout << left << setw(yearWidth) << setfill(seperator) << YoB
             << left << setw(yearWidth) << setfill(seperator) << YoD << endl;
    }
    else
    {
        cout << left << setw(yearWidth) << setfill(seperator) << YoB << endl;
    }
}

string DomainService::convertToLower(string unfilteredString)
{
    locale loc;
    string lowerCaseString;
    for(unsigned int i = 0; i < unfilteredString.length(); i++)
    {
        lowerCaseString += tolower(unfilteredString[i],loc);
    }
    return lowerCaseString;
}

void DomainService::search(string keyword)
{
    bool found = false;
    bool containsLetter = false;
    for(unsigned int i = 0; i < keyword.length(); i++)
    {
        if(isalpha(keyword[i]))
        {
            containsLetter = true;
        }
    }
    for(unsigned int i = 0; i < _personur.size(); i++)
    {
        if(containsLetter)
        {
            if((convertToLower(_personur[i].name) == convertToLower(keyword))||
               (convertToLower(_personur[i].middleInitial) == convertToLower(keyword))||
               (convertToLower(_personur[i].lastName) == convertToLower(keyword))||
               (convertToLower(_personur[i].sex) == convertToLower(keyword)))
            {
                found = true;
            }
            else if((convertToLower(_personur[i].name + " " + _personur[i].middleInitial + " " + _personur[i].lastName) == convertToLower(keyword))||
                    (convertToLower(_personur[i].name + " " + _personur[i].lastName) == convertToLower(keyword))||
                    (convertToLower(_personur[i].name + " " + _personur[i].middleInitial) == convertToLower(keyword))||
                    (convertToLower(_personur[i].middleInitial + " " + _personur[i].lastName) == convertToLower(keyword)))
            {
                found = true;
            }
        }
        else if((_personur[i].yearOfBirth == stoi(keyword, 0, 10)) || ((_personur[i].yearOfDeath == stoi(keyword, 0, 10)) && stoi(keyword, 0, 10) != 0))
        {
            found = true;
        }

        if(found)
        {
            printPerson(i);
            found = false;
        }
    }
}
