#include "domainservice.h"


DomainService::DomainService()
{

}

void DomainService::retriveList()
{
    _data.getFromDB(_computer, _personur);
}

void DomainService::addToList(vector<TempTolPers> input)
{
    TempTolPers pers;
    for(unsigned int i = 0; i < input.size(); i++)
    {
        pers.fullName = input[i].fullName;
        pers.gender = input[i].gender;
        pers.yearOfBirth = input[i].yearOfBirth;
        pers.yearOfDeath = input[i].yearOfDeath;
        _tempPersonur.push_back(pers);
    }
    _data.addToPeople(_tempPersonur);
    _tempPersonur.clear();
    _personur.clear();
    _computer.clear();
    retriveList();
}

void DomainService::addToComp(vector<TempTolComp> input)
{
    TempTolComp comp;
    for(unsigned int i = 0; i < input.size(); i++)
    {
        comp.name = input[i].name;
        comp.type = input[i].type;
        comp.built = input[i].built;
        comp.year = input[i].year;
        _tempComputer.push_back(comp);
    }
    _data.addToComputers(_tempComputer);
    _tempComputer.clear();
    _personur.clear();
    _computer.clear();
    retriveList();
}

int DomainService::getID(int list, int i)
{
    if(list == 1)
    {
        return _personur[i].ID;
    }
    else if(list == 3)
    {
        return _computer[i].ID;
    }
    else
    {
        //TODO
    }
}

string DomainService::getName(int list, int i)
{
    if(list == 1)
    {
        return _personur[i].fullName;
    }
    if(list == 3)
    {
        return _computer[i].name;
    }
    else
    {
        return _trashBin[i].fullName;
    }

}

string DomainService::getType(int list, int i)
{
    return _computer[i].type;
}

int DomainService::getBuiltStatus(int list, int i)
{
    return _computer[i].built;
}

int DomainService::getYear(int list, int i)
{
    return _computer[i].year;
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
    else if(list == 3)
    {
        return _computer.size();
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
    else if(list == 3)
    {
        return _computer.empty();
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
        _personur[personID].fullName = tempString;
            break;
        case 2 :
        _personur[personID].gender = tempString;
            break;
        case 3:
        _personur[personID].yearOfBirth = tempYear;
            break;
        case 4:
        _personur[personID].yearOfDeath = tempYear;
            break;
    }
}

void DomainService::deleteFromList(int list, int i)
{
    if(list == 1)
    {
        _data.deletePerson(i);
    }
    else
    {
        _data.deleteComputer(i);
    }
    _personur.clear();
    _computer.clear();
    retriveList();

}

void DomainService::emptyTrash()
{
    _trashBin.clear();
}

void DomainService::recoverFromTrash(int i)
{
    TolPers pers;
    pers.fullName = _trashBin[i].fullName;
    pers.gender = _trashBin[i].gender;
    pers.yearOfBirth = _trashBin[i].yearOfBirth;
    pers.yearOfDeath = _trashBin[i].yearOfDeath;
    _personur.push_back(pers);
    _trashBin.erase(_trashBin.begin()+i);
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
