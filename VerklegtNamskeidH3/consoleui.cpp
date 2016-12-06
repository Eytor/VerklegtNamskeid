#include "consoleui.h"
#include <iomanip>
#include <iostream>


ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
//    _service.retriveList();

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
        cout << "1. Add to List." << endl
             << "2. Display List." << endl
             << "3. Search from list" << endl
             << "4. Order list." << endl
             << "5. Edit list." << endl
             << "6. Delete person." << endl
             << "7. Recycle bin." << endl
             << "0. Quit." << endl;

        cin >> selected;

        switch (selected)
        {
        case 1:
            addToList();
            cout << endl;
            break;
        case 2:
            displayList(1);
            cout << endl;
            break;
        case 3:
            search();
            break;
        case 4:
            sortSelector();
            break;
        case 5:
            //edit();
            break;
        case 6:
            deletePerson();
            break;
        case 7:
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

void ConsoleUI::displayList(int list)
{
    int listSize =  _service.getListSize(list);
    bool empty =  _service.getEmptyStatus(list);
    if(!empty)
    {
        giveHead();
        for(int i = 0; i < listSize; i++)
        {
            printPerson(list, i);
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

/* void ConsoleUI::edit()
{
    unsigned int personToEdit = 0;
    bool validChoice = false;
    bool validYear = false;
    bool empty =  _service.getEmptyStatus(1);
    unsigned int size = _service.getListSize(1);
    int choice;
    string tempString;

    if(!empty)
    {
        cout << "----------------------------------------------------------------" << endl;
        for(unsigned int i = 0; i < size; i++)
        {
            cout << (i + 1) << ". ";
            printPerson(1, i);
        }

        while(!validChoice)
        {
            cout << "----------------------------------------------------------------" << endl;
            cout << "Select one person from above: ";
            cin >> personToEdit;

            while (cin.fail()||personToEdit<=0)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid command. Select the number of the person you want to edit." << endl;
                cin >> personToEdit;
            }

            if(personToEdit > 0 && personToEdit <= size)
            {
                validChoice = true;
            }
        }

        personToEdit--;
        validChoice = false;

        while(!validChoice)
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

            while (cin.fail()||editChoice<0)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid command." << endl
                << "1. First name" << endl
                << "2. Middle initial" << endl
                << "3. Last name" << endl
                << "4. Gender" << endl
                << "5. Year of birth" << endl
                << "6. Year of Death" << endl;
                cin >> editChoice;
            }


            choice = editChoice;
            switch (choice)
            {
            case 1:
                validChoice = true;
                cout << "Current first name: " << _service.getFirstName(personToEdit) << endl << "New first name: ";
                cin >> tempString;
                break;
            case 2:
                validChoice = true;
                cout << "Current middle initial: " << _service.getMiddleInitial(personToEdit) << endl << "New middle initial, enter '0' for none: ";
                cin >> tempString;
                break;
            case 3:
                validChoice = true;
                cout << "Current last name: " << _service.getLastName(personToEdit) << endl << "New last name: ";
                cin >> tempString;
                break;
            case 4:
                validChoice = true;
                cout << "Current gender: " << _service.getGender(1, personToEdit) << endl << "New gender: ";
                cin >> tempString;
                break;
            case 5:
                validChoice = true;
                cin >> tempString;
                while(!validYear)
                {
                    cout << "Current year of birth: " << _service.getYoB(1, personToEdit) << endl << "New year of birth: ";
                    cin >> tempString;
                    if(_service.checkIfLegitYear(tempString) == true)
                    {
                        int tempYear = stoi(tempString);
                        if(tempYear > _service.getYoD(1, personToEdit) && _service.getYoD(1, personToEdit != 0))
                        {
                            cout << "Year of birth Cannot be larger than year of death." << endl;
                        }
                        else
                        {
                            validYear = true;
                        }
                    }
                    else
                    {
                        cout << "Year must only contain digits!" << endl;
                    }
                }
                break;
            case 6:
                validChoice = true;
                while(!validYear)
                {
                    cout << "Current year of death: " << _service.getYoD(1, personToEdit) << endl << "New year of death: ";
                    cin >> tempString;
                    if(_service.checkIfLegitYear(tempString) == true)
                    {
                        int tempYear = stoi(tempString);
                        if(tempYear < _service.getYoB(1, personToEdit) && tempYear != 0)
                        {
                            cout << "Year of death Cannot be less than year of birth." << endl;
                        }
                        else
                        {
                            validYear = true;
                        }
                    }
                    else
                    {
                        cout << "Invalid year!" << endl;
                    }
                }
                break;
            default:
                validChoice = true;
                break;
            }
        }

        _service.edit(personToEdit, choice, tempString);
    }
    else
    {
        cout << "Woops! The list empty." << endl;
    }

}
*/
void ConsoleUI::addToList()
{
    int numOfPeople;
    cout << "\nSelect number of people: ";
    cin >> numOfPeople;
    string temp;
    while (cin.fail()||numOfPeople<0)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid size. Enter number from 1-100, '0' for main menu" << endl;
        cin >> numOfPeople;
    }

    TolPers pers;
    for(int i = 0; i < numOfPeople; i++)
    {
        cout << "\nFull name: ";
        cin >> pers.fullName;
        cout << "Gender: ";
        cin >> pers.gender;
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
            cout << (i + 1) << ". ";
            printPerson(1, i);
        }

        while(!validChoice)
        {
            cout << line << endl;
            cout << "Select one person from above: ";
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
        personToDelete--;
        cout << endl << "The person was deleted successfully!" << endl << endl;
        _service.deletePerson(personToDelete);
    }
    else
    {
        cout << "The list is empty!" << endl;
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

