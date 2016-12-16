#include "domainservice.h"


DomainService::DomainService()
{

}

void DomainService::retriveList()
{
    _data.getFromDB(_computer, _personur, _deletedComputer, _deletedPersonur, _linking);
}

vector<TolPers> DomainService::getList(int list)
{
    if(list == 1)
    {
        return _personur;
    }
    else
    {
        return _deletedPersonur;
    }

}

vector<TolComp> DomainService::getCompList(int list)
{
    if(list == 1)
    {
        return _computer;
    }
    else
    {
        return _deletedComputer;
    }
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
        _tempPersonur.push_back(pers);
    }
    _data.addToPeople(_tempPersonur);
    _tempPersonur.clear();
    _personur.clear();
    _computer.clear();
    retriveList();
}

void DomainService::addToComp(vector<TolComp> input)
{
    TolComp comp;
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

void DomainService::searchScientists(vector<TolPers>& searchResultPeople,  string keyword)
{
    _data.searchScientists(searchResultPeople, keyword);
}

void DomainService::searchComputers(vector<TolComp>& searchResultComputers, string keyword)
{
    _data.searchComputers(searchResultComputers, keyword);
}

void DomainService::whatToSort(int data, int col, int ord)
{
    if(data == 1)
    {
        _personur.clear();
    }
    else
    {
        _computer.clear();
    }
    _data.sort(_personur, _computer, data, col, ord);
}

void DomainService::deleteFromList(int list, int id, vector<TolPers> backup)
{
    if(list == 1)
    {
        _data.addToDeletedPeople(backup);
        _data.deletePerson(id);
        _tempPersonur.clear();
    }
    else
    {
        _data.addToPeople(backup);
        _data.deleteDeletedPerson(id);
        _tempPersonur.clear();
    }

    _deletedComputer.clear();
    _deletedPersonur.clear();
    _personur.clear();
    _computer.clear();
    _linking.clear();
    _tempLinking.clear();
    retriveList();

}

void DomainService::deleteFromComp(int list, int id, vector<TolComp> backup)
{
    if(list == 1)
    {
        _data.addToDeletedComputers(backup);
        _data.deleteComputer(id);
        _tempComputer.clear();
    }
    else
    {
        _data.addToComputers(backup);
        _data.deleteDeletedComputer(id);
        _tempComputer.clear();
    }
    _deletedComputer.clear();
    _deletedPersonur.clear();
    _personur.clear();
    _computer.clear();
    _linking.clear();
    _tempLinking.clear();
    retriveList();

}

void DomainService::emptyTrash(int list)
{
    if(list == 1)
    {
        _deletedPersonur.clear();
        _data.emptyDeletedPeople();
    }
    else if(list == 2)
    {
        _deletedComputer.clear();
        _data.emptyDeletedComputers();
    }
    else
    {
        _deletedPersonur.clear();
        _deletedComputer.clear();
        _data.emptyDeletedPeople();
        _data.emptyDeletedComputers();
    }
}

void DomainService::editPerson(int id,QString name,QString gender, QString yearOfBirth, QString yearOfDeath)
{
    _data.editPerson(id, name, gender, yearOfBirth, yearOfDeath);
    _personur.clear();
    _computer.clear();
    _deletedComputer.clear();
    _deletedPersonur.clear();
    retriveList();
}

void DomainService::editComputer(int id, QString name, QString type, QString built, QString year)
{
    _data.editComputer(id, name, type, built, year);
    _personur.clear();
    _computer.clear();
    _deletedComputer.clear();
    _deletedPersonur.clear();
    retriveList();
}

void DomainService::linkPersonToComp(int persID, int compID)
{
    _data.linkPersonToComputer(persID, compID);
    _deletedComputer.clear();
    _deletedPersonur.clear();
    _personur.clear();
    _computer.clear();
    _linking.clear();
    _tempLinking.clear();
    retriveList();
}

void DomainService::displayLinks(vector<TempTolLinking>& results)
{
    _deletedComputer.clear();
    _deletedPersonur.clear();
    _personur.clear();
    _computer.clear();
    _linking.clear();
    _tempLinking.clear();
    retriveList();
    _data.displayLinks(results);
}

void DomainService::displayScientistLink(vector<TolPersLink>& results)
{
    _deletedComputer.clear();
    _deletedPersonur.clear();
    _personur.clear();
    _computer.clear();
    _linking.clear();
    _tempLinking.clear();
    retriveList();
    _data.displayScientistsWithLinks(results);
}

void DomainService::displayCompsLink(vector<TolCompLink>& results, int id)
{
    _deletedComputer.clear();
    _deletedPersonur.clear();
    _personur.clear();
    _computer.clear();
    _linking.clear();
    _tempLinking.clear();
    retriveList();
    _data.displayCompsFromLink(id, results);
}

void DomainService::deleteLink(int id)
{
    _data.deleteLinks(3, id);
    _deletedComputer.clear();
    _deletedPersonur.clear();
    _personur.clear();
    _computer.clear();
    _linking.clear();
    _tempLinking.clear();
    retriveList();
}

bool DomainService::checkTheLinkExists(int pID, int cID)
{
    int size = _data.checkIfLinkExists(pID, cID);
    if(size > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
