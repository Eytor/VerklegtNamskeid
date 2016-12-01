#include "domainservice.h"


DomainService::DomainService()
{

}

void DomainService::retriveList()
{
    _data.retriveInfo(_personur, _trashBin);
}

void DomainService::updateFile()
{
    _data.updateFile(_personur);
}

void DomainService::addToList(vector<TolPers> input)
{

    for(unsigned int i = 0; i < input.size(); i++)
    {


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

string DomainService::getFirstName(int i)
{
    return _personur[i].name;
}

string DomainService::getMiddleInitial(int i)
{
    return _personur[i].middleInitial;
}

string DomainService::getLastName(int i)
{
    return _personur[i].lastName;
}

string DomainService::getGender(int i)
{
    return _personur[i].sex;
}

int DomainService::getYoB(int i)
{
    return _personur[i].yearOfBirth;
}

int DomainService::getYoD(int i)
{
    return _personur[i].yearOfDeath;
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

void DomainService::whatToSort(int selector)
{
    if(selector == 1)
    {
        for(int i = 0; i < getListSize(); i++)
        {
            for(int j = 0; j < getListSize(); j++)
            {
                if(_personur[i].name < _personur[j].name)
                {
                    swap(_personur[i], _personur[j]);
                }
            }
        }
    }
    else if(selector == 2)
    {
        for(int i = 0; i < getListSize(); i++)
        {
            for(int j = 0; j < getListSize(); j++)
            {
                if(_personur[i].lastName < _personur[j].lastName)
                {
                    swap(_personur[i], _personur[j]);
                }
            }
        }
    }
    else if(selector == 3)
    {
        for(int i = 0; i < getListSize(); i++)
        {
            for(int j = 0; j < getListSize(); j++)
            {
                if(_personur[i].yearOfBirth < _personur[j].yearOfBirth)
                {
                    swap(_personur[i], _personur[j]);
                }
            }
        }
    }
    else if(selector == 4)
    {
        for(int i = 0; i < getListSize(); i++)
        {
            for(int j = 0; j < getListSize(); j++)
            {
                if(_personur[i].yearOfDeath < _personur[j].yearOfDeath)
                {
                    swap(_personur[i], _personur[j]);
                }
            }
        }
    }
}
void DomainService::edit(int personID, int Selection)
{
    bool valid = true;
    string tempString;
    int tempYear;
    switch (Selection) {
        case 1:
        cin >> tempString;
        _personur[personID].name = tempString;
            break;
        case 2 :
        cin >> tempString;
        _personur[personID].middleInitial = tempString;
            break;
        case 3:
        cin >> tempString;
        _personur[personID].lastName = tempString;
            break;
        case 4:
        cin >> tempString;
        _personur[personID].sex = tempString;
            break;
        case 5:
        do
        {
            cin >> tempYear;
            if(tempYear > _personur[personID].yearOfDeath)
            {
                valid = false;
                cout << "Year of birth Cannot be larger than year of death." << endl
                     << "Year of death is: " << _personur[personID].yearOfDeath << endl
                     << "New year of death: ";
            }
            else
            {
                valid = true;
            }
        }while(!valid);
        _personur[personID].yearOfBirth = tempYear;
            break;
        case 6:
        do
        {
            cin >> tempYear;
            if(tempYear < _personur[personID].yearOfBirth && tempYear != 0)
            {
                valid = false;
                cout << "Year of death Cannot be less than year of birth." << endl
                     << "Year of birth is: " << _personur[personID].yearOfBirth << endl
                     << "New year of death: ";
            }
            else
            {
                valid = true;
            }
        }while(!valid);
        _personur[personID].yearOfDeath = tempYear;
            break;
    }
    updateFile();
}
