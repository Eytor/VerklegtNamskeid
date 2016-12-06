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

void DomainService::updateTrash()
{
    _data.updateTrash(_trashBin);
}

void DomainService::addToList(vector<TolPers> input)
{
    TolPers pers;
    for(unsigned int i = 0; i < input.size(); i++)
    {
        pers.fullName = input[i].fullName;
        pers.gender = input[i].gender;
        pers.yearOfBirth = input[i].yearOfBirth;
        pers.yearOfDeath = input[i].yearOfDeath;
        _personur.push_back(pers);
    }
    updateFile();
}

string DomainService::getName(int list, int i)
{
    string fullName;
    if(list == 1)
    {
        return _personur[i].fullName;
    }
    else
    {
        return _trashBin[i].fullName;
    }

}
string DomainService::getGender(int list, int i)
{
    if(list == 1)
    {
        return _personur[i].gender;
    }
    else
    {
        return _trashBin[i].gender;
    }

}

int DomainService::getYoB(int list, int i)
{
    if(list == 1)
    {
        return _personur[i].yearOfBirth;
    }
    else
    {
        return _trashBin[i].yearOfBirth;
    }
}

int DomainService::getYoD(int list, int i)
{
    if(list == 1)
    {
        return _personur[i].yearOfDeath;
    }
    else
    {
        return _trashBin[i].yearOfDeath;
    }
}

int DomainService::getListSize(int list)
{
    if(list == 1)
    {
        return _personur.size();
    }
    else
    {
        return _trashBin.size();
    }
}

bool DomainService::getEmptyStatus(int list)
{
    bool empty;
    if(list == 1)
    {
        empty = _personur.empty();
    }
    else
    {
        empty = _trashBin.empty();
    }
    return empty;
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

vector <int> DomainService::search(string keyword)
{
    vector <int> searchResult;
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
            if((convertToLower(_personur[i].fullName) == convertToLower(keyword))||
               (convertToLower(_personur[i].gender) == convertToLower(keyword)))
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
                    searchResult.push_back(i);
                    found = false;

                }
            }
    return searchResult;
}

void DomainService::whatToSort(int selector)
{
    if(selector == 1)
    {
        for(int i = 0; i < getListSize(1); i++)
        {
            for(int j = 0; j < getListSize(1); j++)
            {
                if(_personur[i].fullName < _personur[j].fullName)
                {
                    swap(_personur[i], _personur[j]);
                }
            }
        }
    }
    else if(selector == 3)
    {
        for(int i = 0; i < getListSize(1); i++)
        {
            for(int j = 0; j < getListSize(1); j++)
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
        for(int i = 0; i < getListSize(1); i++)
        {
            for(int j = 0; j < getListSize(1); j++)
            {
                if(_personur[i].yearOfDeath < _personur[j].yearOfDeath)
                {
                    swap(_personur[i], _personur[j]);
                }
            }
        }
    }
    updateFile();
}

void DomainService::edit(int personID, int Selection, string s)
{
    string tempString = s;
    int tempYear;
    if(Selection == 5 || Selection == 6)
    {
        tempYear = stoi(s);
    }
    switch (Selection) {
        case 1:
        _personur[personID].name = tempString;
            break;
        case 2 :
        _personur[personID].middleInitial = tempString[0];
            break;
        case 3:
        _personur[personID].lastName = tempString;
            break;
        case 4:
        _personur[personID].sex = tempString;
            break;
        case 5:
        _personur[personID].yearOfBirth = tempYear;
            break;
        case 6:
        _personur[personID].yearOfDeath = tempYear;
            break;
    }
    updateFile();
}

void DomainService::deletePerson(int i)
{
    TolPers pers;
    pers.name = _personur[i].name;
    pers.middleInitial = _personur[i].middleInitial;
    pers.lastName = _personur[i].lastName;
    pers.sex = _personur[i].sex;
    pers.yearOfBirth = _personur[i].yearOfBirth;
    pers.yearOfDeath = _personur[i].yearOfDeath;
    _trashBin.push_back(pers);
    _personur.erase(_personur.begin()+i);
    updateFile();
    updateTrash();
}

void DomainService::emptyTrash()
{
    _trashBin.clear();
    _data.emptyTrash();
}

void DomainService::recoverFromTrash(int i)
{
    TolPers pers;
    pers.name = _trashBin[i].name;
    pers.middleInitial = _trashBin[i].middleInitial;
    pers.lastName = _trashBin[i].lastName;
    pers.sex = _trashBin[i].sex;
    pers.yearOfBirth = _trashBin[i].yearOfBirth;
    pers.yearOfDeath = _trashBin[i].yearOfDeath;
    _personur.push_back(pers);
    _trashBin.erase(_trashBin.begin()+i);
    updateFile();
    updateTrash();
}

bool DomainService::checkIfLegitYear(string s)
{
    bool containsLetter;
    for(unsigned int i = 0; i < s.length(); i++)
    {
        if(isalpha(s[i]))
        {
            containsLetter = true;
        }
    }
    if(!containsLetter)
    {
        return true;
    }
    else
    {
        return false;
    }
}
