#ifndef DOMAINSERVICE_H
#define DOMAINSERVICE_H
#include "dataaccess.h"
#include <iomanip>
#include <stdio.h>
#include <cstring>

using namespace std;

class DomainService
{
public:
    DomainService();
    //Function that retrives the list
    void retriveList();
    //Function that returns the current list of scientists
    vector<TolPers> getList(int list);
    //Function that returns the current list of computers
    vector<TolComp> getCompList(int list);
    //Function that updates the list.txt file
    void updateFile();
    //Function that updates the bin.txt file
    void updateTrash();
    //Function that searches the database for scientist using keyword and adds them to vector
    void searchScientists(vector<TolPers> &searchResult, string keyword);
    //Function that searches the database for computers using keyword and adds them to vector
    void searchComputers(vector<TolComp> &searchResultComputers, string keyword);
    //Function that sorts the list in different ways
    void whatToSort(int data, int col, int ord);
    //Function that edits all values of a person
    void editPerson(int id, QString name, QString gender, QString yearOfBirth, QString yearOfDeath);
    //Function that edits all values of a computer
    void editComputer(int id, QString name, QString type, QString built, QString year);
    //Function that adds a person to the list
    void addToList(vector<TolPers> input);
    //adds a computer to the list
    void addToComp(vector<TolComp> input);
    //Function that sends a person to the recycle bin
    void deleteFromList(int list, int id, vector<TolPers> backup);
    //Function that sends a computer to the recycle bin
    void deleteFromComp(int list, int id, vector<TolComp> backup);
    //Function that empties the recycle bin
    void emptyTrash(int list);
    //Function that recovers everything from the recycle bin
    void recoverFromTrash(int list, int id, int i);
    //links a person to a computer
    void linkPersonToComp(int persID, int compID);
    //Displays links between persons and computers
    void displayLinks(vector<TempTolLinking> &results);
    //Deletes links between persons and computers
    void deleteLink(int id);
    //Displays scientist links
    void displayScientistLink(vector<TolPersLink>& results);
    //Displays computers linked to scientists
    void displayCompsLink(vector<TolCompLink>& results, int id);
    //Checks if a link exists
    bool checkTheLinkExists(int pID, int cID);
private:
    vector<TolPers> _personur;
    vector<TolComp> _computer;
    vector<TolPers> _deletedPersonur;
    vector<TolComp> _deletedComputer;
    vector<TolLinking> _linking;
    vector<TolComp> _tempComputer;
    vector<TolPers> _tempPersonur;
    vector<TempTolLinking> _tempLinking;
    vector<TolPersLink> _tempPersLink;
    vector<TolCompLink> _compLink;
    DataAccess _data;
};

#endif // DOMAINSERVICE_H
