#include "consoleui.h"
#include <iomanip>
#include <iostream>


ConsoleUI::ConsoleUI()
{

}

int ConsoleUI::selection()
{
    int selectNum;
    cout << "--------------------------------------------------" << endl;
    cout << "Hello! Plese select one of the following commands." << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1. Add to List." << endl
         << "2. Display List." << endl
         << "3. Search from list" << endl
         << "4. Order list." << endl
         << "5. Edit list." << endl
         << "0. Quit." << endl;
    cin >> selectNum;
    return selectNum;
}

int ConsoleUI::sortSelection()
{
    int selectNum;
    cout << "1. Order by first name." << endl
         << "2. Order by last name." << endl
         << "3. Order by year of birth." << endl
         << "4. Order by year of death." << endl;
    cin >> selectNum;
    return selectNum;
}

void ConsoleUI::run()
{

     _service.retriveList();

    int selected = 1000;
    while(selected != 0){
        selected = selection();
        switch (selected) {
        case 1:
             addToList();
            cout << endl;
            break;
        case 2:
             displayList();
            cout << endl;
        break;
        case 3:
            search();
            break;
        case 4:
            sortSelector();
            break;
        case 5:
            edit();
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }
    }
}

void ConsoleUI::sortSelector()
{
    int selected;
    selected = sortSelection();
    switch (selected) {
    case 1:
        _service.whatToSort(selected);
        displayList();
        break;
    case 2:
        _service.whatToSort(selected);
        displayList();
        break;
    case 3:
        _service.whatToSort(selected);
        displayList();
        break;
    case 4:
        _service.whatToSort(selected);
        displayList();
        break;
    default:
        cout << "Wrong input" << endl;
        break;
    }
}

void ConsoleUI::printPerson(int i)
{
    const char seperator = ' ';
    const int sexWidth = 8;
    const int yearWidth = 8;
    const int nameWidth = 40;
    string fullName =  _service.getName(i);
    string gender =  _service.getGender(i);
    int YoB =  _service.getYoB(i);
    int YoD =  _service.getYoD(i);

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

void ConsoleUI::displayList()
{
    int listSize =  _service.getListSize();
    bool empty =  _service.getEmptyStatus();
    if(!empty)
    {
        const char seperator = ' ';
        const int firstNameWidth = 40;
        const int sexWidth = 8;
        const int yearWidth = 8;
        cout << left << setw(firstNameWidth) << setfill(seperator) << "Name"
             << left << setw(sexWidth) << setfill(seperator) << "Gender"
             << left << setw(yearWidth) << setfill(seperator) << "Birth"
             << left << setw(yearWidth) << setfill(seperator) << "Death" << endl;
        for(int i = 0; i < listSize; i++)
        {
            printPerson(i);
        }
    }
    else
    {
        cout << "The list is empty!";
    }
}

void ConsoleUI::search()
{

    string keyword;
    cout << "What are you looking for?" << endl;
    cin.ignore();
    getline(cin,keyword);
     _service.search(keyword);
}

int ConsoleUI::editSelect()
{
    int editChoice;
    cout << "--------------------------------------------------" << endl
         << "What do you want to edit?" << endl
         << "1. First name" << endl
         << "2. Middle initial" << endl
         << "3. Last name" << endl
         << "4. Gender" << endl
         << "5. Year of birth" << endl
         << "6. Year of Death" << endl;
    cin >> editChoice;
    return editChoice;
}

void ConsoleUI::edit()
{
    unsigned int personToEdit = 0;
    bool validChoice = false;
    bool empty =  _service.getEmptyStatus();
    unsigned int size = _service.getListSize();
    int choice;

    if(!empty)
    {
        cout << "----------------------------------------------------------------" << endl;
        for(unsigned int i = 0; i < size; i++)
        {
            cout << (i + 1) << ". ";
            printPerson(i);
        }

        while(!validChoice)
        {
            cout << "----------------------------------------------------------------" << endl;
            cout << "Select one person from above: ";
            cin >> personToEdit;
            if(personToEdit > 0 && personToEdit <= size)
            {
                validChoice = true;
            }
        }

        personToEdit--;
        validChoice = false;

        while(!validChoice)
        {
            choice = editSelect();
            switch (choice) {
            case 1:
                validChoice = true;
                cout << "Current first name: " << _service.getFirstName(personToEdit) << endl << "New first name: ";
                break;
            case 2:
                validChoice = true;
                cout << "Current middle initial: " << _service.getMiddleInitial(personToEdit) << endl << "New middle initial, enter '0' for none: ";
                break;
            case 3:
                validChoice = true;
                cout << "Current last name: " << _service.getLastName(personToEdit) << endl << "New last name: ";
                break;
            case 4:
                validChoice = true;
                cout << "Current gender: " << _service.getGender(personToEdit) << endl << "New gender: ";
                break;
            case 5:
                validChoice = true;
                cout << "Current year of birth: " << _service.getYoB(personToEdit) << endl << "New year of birth: ";
                break;
            case 6:
                validChoice = true;
                cout << "Current year of death: " << _service.getYoD(personToEdit) << endl << "New year of death: ";
                break;
            default:
                cout << "Wrong input.";
                break;
            }
        }

        _service.edit(personToEdit, choice);
    }
    else
    {
        cout << "Woops! The list empty." << endl;
    }

}

void ConsoleUI::addToList(){
    int numOfPeople;
    cout << "\nSelect number of people: ";
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
        cout << "\nName: ";
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
        _tempInput.push_back(pers);
        _service.addToList(_tempInput);
    }
}
