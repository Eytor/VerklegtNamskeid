#include "consoleui.h"
#include <iomanip>
#include <iostream>


ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    _service.retriveList();

    int selected = 1000;
    while(selected != 0)
    {
        static bool helloCounter = true;
        cout << "---------------------------------------------------" << endl;

        if(helloCounter)
        {
            cout << "Hello! Please select one of the following commands." << endl;
            helloCounter = false;
        }
        else
        {
            cout << "   Please select one of the following commands." << endl;
        }
        cout << "---------------------------------------------------" << endl;
        cout << "1. Add to Computer Scientists." << endl
             << "2. Add to Computers." << endl
             << "3. Display Computer Scientists." << endl
             << "4. Display Computers." << endl
             << "5. Search from list" << endl
             << "6. Order list." << endl
             << "7. Edit list." << endl
             << "8. Delete." << endl
             << "9. Recycle bin." << endl
             << "0. Quit." << endl;

        cin >> selected;




        switch (selected)
        {
        case 1:
            addToList();
            cout << endl;
            break;
        case 2:
            addToComp();
            cout << endl;
            break;
        case 3:
            displayList(1);
            break;
        case 4:
            displayList(3);
            break;
        case 5:
            search();
            break;
        case 6:
            sortSelector();
            break;
        case 7:
            //edit();
            break;
        case 8:
            deleteSelect();
            break;
        case 9:
            trashSelector();
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
    cout << "1. Order by first name." << endl
         << "2. Order by last name." << endl
         << "3. Order by year of birth." << endl
         << "4. Order by year of death." << endl;
    cin >> selected;

    while (cin.fail()||selected<0)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Select number from 1-4, '0' for main menu" << endl
             << "1. Order by first name." << endl
             << "2. Order by last name." << endl
             << "3. Order by year of birth." << endl
             << "4. Order by year of death." << endl;
        cin >> selected;
    }

    switch (selected)
    {
    case 1:
        _service.whatToSort(selected);
        displayList(1);
        break;
    case 2:
        _service.whatToSort(selected);
        displayList(1);
        break;
    case 3:
        _service.whatToSort(selected);
        displayList(1);
        break;
    case 4:
        _service.whatToSort(selected);
        displayList(1);
        break;
    default:
        cout << "Wrong input" << endl;
        break;
    }
}

void ConsoleUI::printPerson(int list, int i)
{
    const char seperator = ' ';
    const int sexWidth = 8;
    const int yearWidth = 8;
    const int nameWidth = 40;
    string fullName =  _service.getName(list, i);
    string gender =  _service.getGender(list, i);
    int YoB =  _service.getYoB(list, i);
    int YoD =  _service.getYoD(list, i);

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

void ConsoleUI::printComputer(int list, int i)
{
    const char seperator = ' ';
    const int sexWidth = 8;
    const int yearWidth = 8;
    const int nameWidth = 40;
    string name =  _service.getName(list, i);
    string type =  _service.getType(list, i);
    int built =  _service.getBuiltStatus(list, i);
    int year =  _service.getYear(list, i);

    cout << left << setw(nameWidth) << setfill(seperator) << name;
    cout << left << setw(sexWidth) << setfill(seperator) << type;
    if(built != 0)
    {
        cout << left << setw(yearWidth) << setfill(seperator) << built
             << left << setw(yearWidth) << setfill(seperator) << year << endl;
    }
    else
    {
        cout << left << setw(yearWidth) << setfill(seperator) << built << endl;
    }
}

void ConsoleUI::displayList(int list)
{
    int listSize =  _service.getListSize(list);
    bool empty =  _service.getEmptyStatus(list);
    if(!empty)
    {
        giveHead();
        for(int i = 0; i < listSize; i++)
        {
            if(list == 3)
            {
                printComputer(list, i);
            }
            else
            {
                printPerson(list, i);
            }
        }
    }
    else
    {
        cout << "The list is empty!" << endl;
    }
}

void ConsoleUI::giveHead()
{
    const char seperator = ' ';
    const int firstNameWidth = 40;
    const int sexWidth = 8;
    const int yearWidth = 8;


    cout << left << setw(firstNameWidth) << setfill(seperator) << "Name"
         << left << setw(sexWidth) << setfill(seperator) << "Gender"
         << left << setw(yearWidth) << setfill(seperator) << "Birth"
         << left << setw(yearWidth) << setfill(seperator) << "Death" << endl;

}

void ConsoleUI::search()
{

    string keyword;
    cout << "What are you looking for?" << endl;
    cin.ignore();
    getline(cin,keyword);

    vector<int> searchResult =  _service.search(keyword);
    if(searchResult.size() == 1)
    {
        cout <<"Found 1 result." << endl;
    }
    else if(searchResult.size() == 0)
    {
        cout <<"No match found. ";
    }
    else
    {
        cout <<"Found " << searchResult.size()  << " results." << endl;
    }
    giveHead();
    for (unsigned int i = 0; i<searchResult.size(); i++)
    {
        int count = searchResult[i];
        printPerson(1, count);
    }
    cout << endl;

}



void ConsoleUI::addToList()
{
    int numOfPeople;
    cout << "\nSelect number of people: ";
    cin >> numOfPeople;
    while (cin.fail()||numOfPeople<0)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid size. Enter number from 1-100, '0' for main menu" << endl;
        cin >> numOfPeople;
    }

    TempTolPers pers;
    for(int i = 0; i < numOfPeople; i++)
    {
        cout << "\nFull name: ";
        cin.ignore();
        getline(cin,pers.fullName);
       // cin >> pers.fullName;
        cout << "Gender: ";
      //  cin >> pers.gender;
        cin.ignore();
        getline(cin,pers.gender);
        cout << "Year of birth: ";
        cin >> pers.yearOfBirth;

        while (cin.fail()||pers.yearOfBirth <= 0 || pers.yearOfBirth > 2251)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid size. Enter year from 1-2250: ";
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
    }
    _service.addToList(_tempInput);
    _tempInput.clear();
}

void ConsoleUI::addToComp()
{
    int numOfComputers;
    cout << "Select number of computers to insert: ";
    cin >> numOfComputers;
    while(cin.fail()||numOfComputers<0)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Invalid size. Enter number from 1-100, '0' for main menu" << endl;
    }

    TempTolComp comps;
    for(int i = 0; i < numOfComputers; i++)
    {
        cout << "\nName: ";
        cin >> comps.name;
        cout << "Type: ";
        cin >> comps.type;
        cout << "Built: ";
        cin >> comps.built;
        cout << "Year: ";
        cin >> comps.year;

        _tempCompInput.push_back(comps);
    }
    _service.addToComp(_tempCompInput);
    _tempCompInput.clear();
}

void ConsoleUI::deletePerson()
{
    unsigned int personToDelete = 0;
    bool validChoice = false;
    bool empty =  _service.getEmptyStatus(1);
    unsigned int size = _service.getListSize(1);
    string line = "----------------------------------------------------------------";

    if(!empty)
    {
        cout << line << endl;
        for(unsigned int i = 0; i < size; i++)
        {
            cout << _service.getID(1, i) << ". ";
            printPerson(1, i);
        }

        while(!validChoice)
        {
            cout << line << endl;
            cout << "Select the ID number of one person from above: ";
            cin >> personToDelete;

            while (cin.fail()||personToDelete<=0)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid command. Select the number of the person you want to delete." << endl;

                cin >> personToDelete;
            }

            if(personToDelete > 0 && personToDelete <= size)
            {
                validChoice = true;
            }
        }
        cout << endl << "The person was deleted successfully!" << endl << endl;
        _service.deletePerson(personToDelete);
    }
    else
    {
        cout << "The list is empty!" << endl;
    }

}

void ConsoleUI::deleteComputer()
{
    /* TODO!!!!*/

}

void ConsoleUI::deleteSelect()
{
    int selected;
    cout << "Select one of the options below:" << endl <<
            "1. Delete from Computer Scientists." << endl <<
            "2. Delete from Computers." << endl;
    cin >> selected;
    switch(selected)
    {
    case 1:
        deletePerson();
        break;
    case 2:
        deleteComputer();
        break;
    default:
        cout << "Wrong input";
        break;
    }

}

void ConsoleUI::trashSelector()
{
    int selected;
    cout << "1. View recycle bin." << endl
         << "2. Recover from recycle bin." << endl
         << "3. Empty recycle bin." << endl;
    cin >> selected;

    while (cin.fail()||selected<0)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid command. Select '0' for main menu" << endl
             << "1. View recycle bin." << endl
             << "2. Recover from recycle bin." << endl
             << "3. Empty recycle bin." << endl;

        cin >> selected;
    }

    switch (selected)
    {
    case 1:
        displayList(2);
        break;
    case 2:
        recoverFromTrash();
        break;
    case 3:
        _service.emptyTrash();
        break;
    default:
        break;
    }
}

void ConsoleUI::recoverFromTrash()
{
    unsigned int personToRecover = 0;
    bool validChoice = false;
    bool empty =  _service.getEmptyStatus(2);
    unsigned int size = _service.getListSize(2);
    string line = "----------------------------------------------------------------";

    if(!empty)
    {
        cout << line << endl;
        for(unsigned int i = 0; i < size; i++)
        {
            cout << (i + 1) << ". ";
            printPerson(2, i);
        }

        while(!validChoice)
        {
            cout << line << endl;
            cout << "Select one person from above: ";
            cin >> personToRecover;

            while (cin.fail()||personToRecover <= 0)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid command. Select '0' for main menu" << endl
                     << "Select the number of the person you want to recover: ";

                cin >> personToRecover;
            }

            if(personToRecover > 0 && personToRecover <= size)
            {
                validChoice = true;
            }
        }
        personToRecover--;
        cout << endl << "The person was recovered successfully!" << endl << endl;
        _service.recoverFromTrash(personToRecover);
    }
    else
    {
        cout << "The trash bin is empty." << endl;
    }
}
