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
             << "10. Link Scientists to Computers." << endl
             << "11. Display links between Scientists and Computers" << endl
             << "69. Do you want to play a game?" << endl
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
            selectListToOrder();
            break;
        case 7:
            edit();
            break;
        case 8:
            deleteSelect();
            break;
        case 9:
            trashSelector();
            break;
        case 10:
            linkPeopleToComps();
            break;
        case 11:
            displayLinks();
            break;
        case 69:
            epic();
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

int ConsoleUI::sortSelector(int list)
{
    int selected;
    if (list == 1)
    {
        cout << "1. Order by name." << endl
             << "2. Order by gender." << endl
             << "3. Order by year of birth." << endl
             << "4. Order by year of death." << endl;
        cin >> selected;

        while (cin.fail()||selected<0||selected>4)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Select number from 1-4, '0' for main menu" << endl
                 << "1. Order by name." << endl
                 << "2. Order by gender." << endl
                 << "3. Order by year of birth." << endl
                 << "4. Order by year of death." << endl;
            cin >> selected;
        }
    }
    else
    {
        cout << "1. Order by name." << endl
             << "2. Order by type." << endl
             << "3. Order by built." << endl
             << "4. Order by year." << endl;
        cin >> selected;

        while (cin.fail()||selected<0||selected>4)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Select number from 1-4, '0' for main menu" << endl
                 << "1. Order by name." << endl
                 << "2. Order by type." << endl
                 << "3. Order by built." << endl
                 << "4. Order by year." << endl;
            cin >> selected;
        }
    }
    return selected;
}

void ConsoleUI::printPerson(int list, int i)
{
    const char seperator = ' ';
    const int sexWidth = 14;
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
    const int sexWidth = 14;
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
        giveHead(list);
        for(int i = 0; i < listSize; i++)
        {
            if(list <= 2)
            {
                printPerson(list, i);
            }
            else
            {
                printComputer(list, i);
            }
        }
    }
    else
    {
        cout << "The list is empty!" << endl;
    }
}

void ConsoleUI::giveHead(int i)
{
    const char seperator = ' ';
    const int firstNameWidth = 40;
    const int sexWidth = 14;
    const int yearWidth = 8;

    if (i == 1)
    {
        cout << left << setw(firstNameWidth) << setfill(seperator) << "Name"
             << left << setw(sexWidth) << setfill(seperator) << "Gender"
             << left << setw(yearWidth) << setfill(seperator) << "Birth"
             << left << setw(yearWidth) << setfill(seperator) << "Death" << endl;
    }
    else
    {
        cout << left << setw(firstNameWidth) << setfill(seperator) << "Name"
             << left << setw(sexWidth) << setfill(seperator) << "Type"
             << left << setw(yearWidth) << setfill(seperator) << "Built"
             << left << setw(yearWidth) << setfill(seperator) << "Year" << endl;
    }

}

void ConsoleUI::search()
{

    const char seperator = ' ';
    const int sexWidth = 14;
    const int yearWidth = 8;
    const int nameWidth = 40;

    string keyword;
    cout << "What are you looking for?" << endl;
    cin.ignore();
    getline(cin,keyword);

    _service.search(_tempInput, _tempCompInput, keyword);
    if((_tempInput.size() + _tempCompInput.size()) > 0)
    {
        cout <<"Found " << (_tempInput.size() + _tempCompInput.size())  << " results." << endl << endl;
        if(_tempInput.size() > 0)
        {
            cout << "Found " << _tempInput.size()  << " results in computer scientists. " << endl;
            giveHead(1);
            for (unsigned int i = 0; i < _tempInput.size(); i++)
            {
                cout << left << setw(nameWidth) << setfill(seperator) << _tempInput[i].fullName;
                cout << left << setw(sexWidth) << setfill(seperator) << _tempInput[i].gender;
                if(_tempInput[i].yearOfDeath != 0)
                {
                    cout << left << setw(yearWidth) << setfill(seperator) << _tempInput[i].yearOfBirth
                         << left << setw(yearWidth) << setfill(seperator) << _tempInput[i].yearOfDeath << endl;
                }
                else
                {
                    cout << left << setw(yearWidth) << setfill(seperator) << _tempInput[i].yearOfBirth << endl;
                }
            }
            cout << endl;
        }
        else
        {
            cout << "Zero results found in computer scientist.";
        }

        if(_tempCompInput.size() > 0)
        {
            cout << "Found " << _tempCompInput.size()  << " results in computers. " << endl;
            giveHead(3);
            for(unsigned int i = 0; i < _tempCompInput.size(); i++)
            {
                cout << left << setw(nameWidth) << setfill(seperator) << _tempCompInput[i].name;
                cout << left << setw(sexWidth) << setfill(seperator) << _tempCompInput[i].type;
                if(_tempCompInput[i].built != 0)
                {
                    cout << left << setw(yearWidth) << setfill(seperator) << _tempCompInput[i].built
                         << left << setw(yearWidth) << setfill(seperator) << _tempCompInput[i].year << endl;
                }
                else
                {
                    cout << left << setw(yearWidth) << setfill(seperator) << _tempCompInput[i].built << endl;
                }
            }
        }
        else
        {
            cout << "Zero results found in computers. ";
        }

    }
    else
    {
        cout <<"No match found. ";
    }
    _tempCompInput.clear();
    _tempInput.clear();
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
        cout << "Gender: ";
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
        cin >> numOfComputers;
    }

    TempTolComp comps;
    for(int i = 0; i < numOfComputers; i++)
    {
        cout << "\nName: ";
        cin.ignore();
        getline(cin,comps.name);
        cout << "Type: ";
        getline(cin,comps.type);
        cout << "Built? '1' for true, '0' for false : ";
        cin >> comps.built;

        while(cin.fail() || comps.built > 1 || comps.built < 0)
        {

            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid command. Enter '1' if the computer was built, enter '0' if not." << endl;
            cin >> comps.built;
        }

        if(comps.built == 1)
        {
            cout << "Year: ";
            cin >> comps.year;

            while(cin.fail() || comps.year > 2250  || comps.year < 1500)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid size. Enter year from 1500-2250 ";
                cin >> comps.year;
            }
        }

        _tempCompInput.push_back(comps);
    }
    _service.addToComp(_tempCompInput);
    _tempCompInput.clear();
}

void ConsoleUI::deleteFromList(int list)
{
    unsigned int selectDelete = 0;
    unsigned int toDelete = 0;
    bool validChoice = false;
    bool empty =  _service.getEmptyStatus(list);
    unsigned int size = _service.getListSize(list);
    string line = "----------------------------------------------------------------";

    if(!empty)
    {
        cout << line << endl;
        for(unsigned int i = 0; i < size; i++)
        {
            cout << (i+1) << ". ";
            if(list < 3)
            {
                printPerson(list, i);
            }
            else
            {
                printComputer(list, i);
            }
        }

        while(!validChoice)
        {
            cout << line << endl;
            cout << "Select the number of one person from above: ";
            cin >> selectDelete;

            while (cin.fail()||selectDelete<=0)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nInvalid command. Select the number of the person you want to delete." << endl;

                cin >> selectDelete;
            }

            if(selectDelete > 0 && selectDelete <= size)
            {
                validChoice = true;
            }
        }
        selectDelete--;
        toDelete =_service.getID(list, selectDelete);
        cout << endl << "The delete was successful!" << endl << endl;
        _service.deleteFromList(list, toDelete, selectDelete);
    }
    else
    {
        cout << "The list is empty!" << endl;
    }

}

void ConsoleUI::deleteSelect()
{
    int selected;
    cout << "Select one of the options below:" << endl <<
         "1. Delete from Computer Scientists." << endl <<
         "2. Delete from Computers." << endl;
    cin >> selected;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid selection select '0' for main menu or try again: " << endl <<
             "1. Delete from Computer Scientists." << endl <<
             "2. Delete from Computers." << endl;
        cin >> selected;
    }
    if(selected > 0 && selected < 3)
    {
        if(selected == 1)
        {
            deleteFromList(selected);
        }
        else
        {
            deleteFromList(3);
        }
    }
    else
    {
        cout << "FATAL ERROR: USER TO STUPID TO SELECT NUMBER FROM LIST ABOVE!" << endl;
    }

}

void ConsoleUI::trashSelector()
{
    int selected;
    cout << "1. View recycle bin." << endl
         << "2. Recover from recycle bin." << endl
         << "3. Empty recycle bin." << endl;
    cin >> selected;

    while (cin.fail()||selected<0|| selected > 3)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid command. Select '0' for main menu or try again " << endl
             << "1. View recycle bin." << endl
             << "2. Recover from recycle bin." << endl
             << "3. Empty recycle bin." << endl;

        cin >> selected;
    }


    switch (selected)
    {
    case 1:
        cout << "1. Deleted People." << endl
             << "2. Deleted Computers." << endl;
        cin >> selected;
        while (cin.fail()||selected<0|| selected > 2)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid command. Select '0' for main menu or try again" << endl
                 << "1. Deleted People." << endl
                 << "2. Deleted Computers." << endl;
            cin >> selected;
        }
        switch (selected)
        {
        case 1:
            displayList(2);
            break;
        case 2:
            displayList(4);
        case 0:
            break;
        }
        break;
    case 2:
        cout << "1. Recover People." << endl
             << "2. Recover Computers." << endl;
        cin >> selected;
        while (cin.fail()||selected<0|| selected >2)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid command. Select '0' for main menu or try again" << endl
                 << "1. Recover People." << endl
                 << "2. Recover Computers." << endl;
            cin >> selected;
        }
        switch (selected)
        {
        case 1:
            recoverFromTrash(2);
            break;
        case 2:
            recoverFromTrash(4);
        case 0:
            break;
        }
        break;
    case 3:
        cout << "1. Empty Deleted People." << endl
             << "2. Empty Deleted Computers." << endl
             << "3. Empty All." << endl;
        cin >> selected;
        while (cin.fail()||selected<0|| selected>3)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid command. Select '0' for main menu or try again" << endl
                 << "1. Empty Deleted People." << endl
                 << "2. Empty Deleted Computers." << endl
                 << "3. Empty All." << endl;
            cin >> selected;
        }
        if(selected > 0 && selected <= 3)
        {
            cout << "The trash was emptied successfully!" << endl;
            _service.emptyTrash(selected);
        }

        break;
    case 0:
        break;
    }
}

void ConsoleUI::recoverFromTrash(int list)
{
    unsigned int toRecover = 0;
    unsigned int personToRecover = 0;
    bool validChoice = false;
    bool empty =  _service.getEmptyStatus(list);
    unsigned int size = _service.getListSize(list);
    string line = "----------------------------------------------------------------";

    if(!empty)
    {
        cout << line << endl;
        for(unsigned int i = 0; i < size; i++)
        {
            cout << (i + 1) << ". ";
            if(list < 3)
            {
                printPerson(list, i);
            }
            else
            {
                printComputer(list, i);
            }
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
        toRecover =_service.getID(list, personToRecover);
        cout << endl << "The recovery was successful!" << endl << endl;
        _service.deleteFromList(list, toRecover, personToRecover);
    }
    else
    {
        cout << "The trash bin is empty." << endl;
    }
}

void ConsoleUI::selectListToOrder()
{
    int selectedList;
    int colSelect;
    int orderSelect;
    cout << "Select one of the options below:" << endl <<
         "1. Order the list of scientists." << endl <<
         "2. Order the list of computers." << endl;
    cin >> selectedList;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error select '1' to order scientists or '2' to order computers. " << endl;
        cin >> selectedList;
    }
    if( (selectedList > 0 && selectedList < 3))
    {
        colSelect = sortSelector(selectedList);
        cout << "Select one of the options below:" << endl <<
             "1. Order in ascending order." << endl <<
             "2. Order in descending order." << endl;
        cin >> orderSelect;
        while (cin.fail()||orderSelect>2||orderSelect<1)
        {

            cout << "Invalid input. \nSelect one of the options below:" << endl <<
                 "1. Order in ascending order." << endl <<
                 "2. Order in descending order." << endl;
            cin >> orderSelect;
        }
        _service.whatToSort(selectedList, colSelect, orderSelect);
    }
    else
    {
        cout << "FATAL ERROR: USER TO STUPID TO SELECT NUMBER FROM LIST ABOVE!" << endl;
    }

}

void ConsoleUI::edit()
{
    int list = 0;
    int listSelect = 0;
    unsigned int selectEdit = 0;
    unsigned int toEdit = 0;
    unsigned int whatToEdit = 0;
    bool validChoice = false;
    string edited;


    cout << "Select from wich list you would like to edit" << endl <<
         "1. Computer scientists." << endl <<
         "2. Computers." << endl;
    cin >> listSelect;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error select '1' to edit scientists or '2' to edit computers. " << endl;
        cin >> listSelect;
    }

    if(listSelect == 2)
    {
        list = 3;
    }
    else
    {
        list = listSelect;
    }

    bool empty =  _service.getEmptyStatus(list);
    unsigned int size = _service.getListSize(list);
    string line = "----------------------------------------------------------------";

    if(!empty)
    {
        cout << line << endl;
        for(unsigned int i = 0; i < size; i++)
        {
            cout << (i+1) << ". ";
            if(list < 3)
            {
                printPerson(list, i);
            }
            else
            {
                printComputer(list, i);
            }
        }

        while(!validChoice)
        {
            cout << line << endl;
            if(list == 1)
            {
                cout << "Select the number of the person you want to edit: ";
            }
            else
            {
                cout << "Select the number of the computer you want to edit: ";
            }
            cin >> selectEdit;

            while (cin.fail()||selectEdit <= 0)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid command. Select the number of the person you want to edit:" << endl;

                cin >> selectEdit;
            }

            if(selectEdit > 0 && selectEdit <= size)
            {
                validChoice = true;
            }

            cout << "Select what to edit: " << endl;
            if(list == 1)
            {
                cout << "\n1. Name  \n2. Gender  \n3. Year of birth  \n4. Year of death\n";
                cin >> whatToEdit;
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid input. Select '1' to edit Name, '2' to edit Gender, '3' to edit Year of birth or '4' to edit Year of death " << endl;
                    cin >> whatToEdit;
                }

                if(whatToEdit == 1)
                {
                    cout << "New name: ";
                    cin.ignore();
                    getline(cin,edited);

                }
                else if(whatToEdit == 2)
                {
                    cout << "New gender: ";
                    cin >> edited;
                }
                else if(whatToEdit == 3)
                {
                    cout << "New year of birth: ";
                    cin >> edited;

                }
                else
                {
                    cout << "New year of death: ";
                    cin >> edited;
                }
            }
            else
            {
                cout << "\n1. Name  \n2. Type  \n3. Built  \n4. Year \n";
                cin >> whatToEdit;
                if(whatToEdit == 1)
                {
                    cout << "New name: ";
                    cin >> edited;
                }
                else if(whatToEdit == 2)
                {
                    cout << "New Type: ";
                    cin >> edited;
                }
                else if(whatToEdit == 3)
                {
                    cout << "New built: ";
                    cin >> edited;
                }
                else
                {
                    cout << "New Year: ";
                    cin >> edited;
                }
            }\

        }
        selectEdit--;
        toEdit =_service.getID(list, selectEdit);
        _service.editPerson(list, toEdit, whatToEdit, edited);
    }
    else
    {
        cout << "The list is empty!" << endl;
    }


}

void ConsoleUI::linkPeopleToComps()
{
    int scientistSelected;
    int computerSelected;
    int persToEdit;
    int compToEdit;
    bool peopleEmpty =  _service.getEmptyStatus(1);
    bool compsEmpty = _service.getEmptyStatus(3);
    int peopleSize = _service.getListSize(1);
    int compSize = _service.getListSize(3);
    if(peopleEmpty)
    {
        cout << "\nThere are no scientists in the database, please insert a scientist before linking to a computer" << endl;
    }
    else if(compsEmpty)
    {
        cout << "\nThere are no computers in the database, please insert a computer before linking to a scientist" << endl;
    }
    else
    {
        for(int i = 0; i < peopleSize; i++)
        {
            cout << (i+1) << ". ";
            printPerson(1, i);
        }
        cout << "Please select a scientist to link: " << endl;
        cin >> scientistSelected;
        while(cin.fail() || scientistSelected > peopleSize)
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Invalid input. Select a scientist from above" << endl;
            cin >> scientistSelected;
        }

        cout << endl;
        for(int i = 0; i < compSize; i++)
        {
            cout << (i+1) << ". ";
            printPerson(3, i);
        }
        cout << "Please select a computer to link: " << endl;
        cin >> computerSelected;
        while(cin.fail() || computerSelected > compSize)
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Invalid input. Select a computer from above" << endl;
            cin >> computerSelected;
        }

        persToEdit = _service.getID(1, scientistSelected-1);
        compToEdit = _service.getID(3, computerSelected-1);

        _service.linkPersonToComp(persToEdit, compToEdit);
        //toEdit =_service.getID(list, selectEdit);
    }

}

void ConsoleUI::displayLinks()
{
    const char seperator = ' ';
    const int nameWidth = 40;
    cout << left << setw(nameWidth) << setfill(seperator) << "Computer Scientist:"
         << left << setw(nameWidth) << setfill(seperator) << "Computers:" << endl;
    int size = _service.getListSize(5);
    bool empty = _service.getEmptyStatus(5);
    if(empty)
    {
        cout << "No links exist" << endl;
    }


}

void ConsoleUI::epic()
{

    char grid[3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
    char player = 'X';
    int umferdir = 0;
    int skosveinn;

    cout << "Hello! Set to fullscreen to get the best experience" << endl;
    cout << "Enter '1' if you are Skosveinn 1 or enter '2' if you are Skosveinn 2" << endl;
    cin >> skosveinn;
    if(skosveinn == 1)
    {

        cout << " ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;':;;;;;;;;::;;:::::;:::::::;;;;;;;;;;;;;;;;;;;\n ;''''''';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;';;''+';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n ;''''';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;''+#;''+'+;+;'+;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n ;'''';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;'++;+'#+;+'';++++++;:;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n ;'';';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;';++'';:+##;';#''+++;;';;;;;:;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n ;';';';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;++#';''+;++#++++;,+#;;:;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n ;';';';;;;;;;;;;;;;;;;;;;;;;;;;;;;;+#+#+++#;+''+++##+#::+#;:';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n ;'';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;####++'#+':',#:+++#+#+:;#:;';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n ;'''';;;;;;;;;;;;;;;;;;;;;;;;;;;++++'+'#:++++:'+##+#+###++++;'';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n ;;;;;;';;;;;;;;;;;;;;;;;;;;;;;:+####++:#';.;+';''++++#+##+#+++;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;##+#+#+###+#;#''+:+'#'+##+#++##''#:;;;:;:;:::;;;;;;;;;;;;;;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;;;'++###++'#++,'##+'+#+;#'#++##+####'+++::::::::;;:::;;;;;;;;;;;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;;;##+#++++++;;'+,'+#+++++#+#+#+#+'##+#+#:;::::::::::;;;;;;;;;;;;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;'++####+'+:;'',++;:'':#++++++++++++#+###'':::::::::::;;;;;;;;;;;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;;'+###+##+;:+#+#'';'''++'''''+++++++##+#+';::::::::::;;;:;:;;;;;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;;+#######+++++++++';;,:;';''''+''''++#+#'+;;::::::::::::::;;;;;;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;;#####++#+#+++''';:::..,:,:;:,,:;':'+#++++';::::::::::::::::;;;;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;+####++#++++';:..,.,`...`,.,,,,,,:,:+++++++;::::::::::::::::;;;;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;'####+##+++'::...``....`.`...,....,.'+++++++;:::::::::::::::::;;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;####++++++;,,.........`............,;;'+++++;::::::::::::::::;:;;;;;;;; \n ;;;;;;;;;;;;;;;;;;;;;;;;;#####+++'':..................,....,,;:'++++++::::::::::::::::::::;;;;;: \n ;;;;;;;;;;;;;;;;;;;;;;;;'####+++'':,,...................,,,,,::;;'+++:::::::::::::::::::::;;;;;: \n ;;;;;;;;;;;;;;;;;;;;;;;;;#####+;;';,,,,,......,,,,,,,....,,,,,:;:'++#;:::::::::::::::::::::;;;;: \n ;;;;;;;;;;;;;;;;;;;;;;;;+####+++:,,,,,,.,....,,,,,,..,,...,,,,,;;'++++:::::::::::::::::::::;;;;: \n ;;;;;;;;;;;;;;;;;;;;;;;:###++;';,,,,,...........,..........,,,,;:''+##:::::::::::::::::::::::;;: \n ;;;;;;;;;;;;;;;;;;;;;;;'###+;::,,,,,,......................,,,,:::''++':::::::::::::::::::::::;: \n ;;;;;;;;;;;;;;;;;;;;;;;####+;,,,,........``.``...`...........,,,::'++##::::::::::::::::::::::::: \n ;;;;;;;;;;;;;;;;;;;;;;;#+##+:,.....,...````..`..```````......,,,,:;''++::::::::::::::::::::::::: \n ;;;;;;;;;;;;;;;;;;;;;;;++#+;;,,..........`````...`.``........,,,,:;+'++;:::::::::::::::::::::::: \n ;;;;;;;;;;;;;;;;;;;;;;+##++':,,,,,.........`..`.``.``......,,,.,,,;++'+':::::::::::::::::::::::: \n ;;;;;;;;;;;;;;;;;;;;;;++##+':,......,......,..........,....,,....,,'+'';:::::::::::::::::::::::: \n ;;;;;;;;;;;;;;;;;;;;;;+#+#+':,.........,,,,,,,,,.,,,,,,,.........,,'++';:::::::::::::::::::::::: \n ;;;;;;;;;;;;;;;;;;:;;;'+#++;,,.......,:::,::::,,,,,,:;::;;,,:.....,:++'':::::::::::::::::::::::: \n ;;;;;;;;;;;;;;;;;;:;:;'##++;:,,,:,:;;++'''''''::,,::;'''+++''';,;,,:+#+;:::::::::::::::::::::::: \n ;;;;;;;;;;;;;;;;:;;:;::###';:,:::::'++++'++'''';;;;''''+++++'';::':;+##;:::::::::::::::::::::::: \n ;;;;;;;;;;;;;;;;:;:::::###';;;;;'''++++++'+'''';;;;;''''''++'''';'':'#+;:::::::::::::::::::::::: \n ;;;;;;;;;;;;;;;::::::::+#+';''+'''''''''''''''';;';'''''''''''''''';'##::::::::::::::::::::::::: \n ;;;;;;;;;;;;;;::::::::;'#+';''''''''''++++++++;,,,''+++++++''''''''';##::::::::::::::::::::::::: \n ;;;;;;;;;;;::;:::::::::;+#;'''''''+++++++#++++:.`..+++#++###+++';''';++,:::::::::::::::::::::::: \n ;;;;;;;;;;;::;;:::::::::++:'''''+++###++++++++..``.:++#+#+#+++#+'''';'#,:::::::::::::::::::::::: \n ;;;;;;;;;;;:::::::::::::#+;'+'+++#++##+++##++,,.``.,+++++#+#'++++''';;#',::::::::::::::::::::::: \n ;;;;;;;;;;:::::::::::::;+':;++++++++++++++++;.,..`.,,+++++'++++++++',;#;;,:::::::::::::::::::::: \n ;;;;;;;;:;;:::::::::::;;#:::++++++++++++++++,....`..,++++++'''++'''',:+'+:,,::,::::::::::::::::: \n ;;;;;;;;:;::::::::::::''#:,,;+++++++++++'+':.....`..,,+'+++++++'''';,:'++;,,,::::::::::::::::::: \n ;;;;;;;;::::::::::::::+++;:,:'++++++++++';.......`..,,.'''''''''''',,;;++;,,,,:::,,::::::::::::: \n ;;;;;;;;::::::::::::::+++;:,,:;'++++''':...,,,...`..,,,,,''''''''';,,;;'+;,,,,,:,,,:,::::::::::: \n ;;;;;;;;::::::::::::::+++;:,,,:::;;;......,,.....`...,:,..:;''''';;::;;++:,,,,,,,,,,,,:::::::::: \n ;;;;;;;;;:::::::::::::'++';::,,,,,,,....,::...........`:,....,:;;;:::;;+,,,,,,,,,,,,,,,::,:::::: \n ;;;;;;;::::::::::::::::++;;;::::,,...,,,,;...,,,,,,::,.,:,.,.,,,:;;;;;''',,,,,,,,,,,,,,::::::::: \n ;;;;;;;::::::::::::::::;+';;;;::,,,,,,,:;',;;';;:;;;;;:,:,,,,,,,,;';';'+,,,,,,,,,,,,,,,,,::::::: \n ;;;;;;;:::::::::::::::::+'''';;:,,,,,,:;''';'+;;;;;:'#:;::,,,,,::;;''''+,,,,,,,,,,,,,,,,,,:::::: \n ;;;;;;;:::::::::::::::::+'''';';::::,:;;'';;'++';;;;++;;:::,,::::;''''';,,,,,,,,,,,,,,,:,,:::::: \n ;;;;;;;:::::::::::::::::,''''';;:::::::;,,++#+++++++'+'',::::::;;;''''':,,,,,,,,,,,,,,,,,,:,:::: \n ;;;;;;;:::::::::::::::::,+''''';;:;::;;,..+++++++++++++'..::::::;;'''+'',,,,,,,,,,,,,,,,,,,::::: \n ;;;;;;;;::::::::::::::::,''''';;;:;:;::,..++++++++++++''..,::::;;'''''';,,,,,,,,,,,,,,,,,,:,:::: \n ;;;;;;;::::::::::::::::::+'''''';;;;::,,.,:+++++++++++++..,,:;;;;;''+'',,,,,,,,,,,,,,,,,,,,,:::, \n ;;;;;;;:::::::::::::::::::++'';';;;;;,,,,::++++++++++++',,,,:;;;''';'':,,,,,,,,,,,,,,,,,,,,,:::: \n ;;;;;;;:::::::::::::::::::+++'''''';,:,:;:::++++++++++++;,::,;;;;''''',,,,,,,,,,,,,,,,,,,,,,:::: \n ;;;;;;;;::::::::::::::::::++'''''';;:::'''::,''+'+'''''';+:;;;;;;'';'',,,,,,,,,,,,,,,,,,,,,,:::: \n ;;;;;;;;:::::::::::::::::,;'+'''''';;;':'';;'''''';'';;'''''':;;;''';',,,,,,,,,,,,,,,,,,,,,,:::: \n ;;;;;;;:;::::::::::::,::,,:''++';'';''''''''''''''';;;'';''+':;':'''':,,,,,,,,,,,,,,,,,,,,,,:::: \n ;;;;;;;:;::::::::::::::,:,,'''''+';''+++##+++++++++++'++++++''''''''':,,,,,,,,,,,,,,,,,,,,,::::: \n ;;;;;;;;;:::::::::::::,:,,,+'''';''''+++++++'+''+'''''+'''++''''''''',,,,,,,,,,,,,,,,,,,,,,,:::: \n ;;;;;;;::::::::::::::::,,,,,'''''+''+++++'',,,+'''''''''''''''''''''',,,,,,,,,,,,,,,,,,,,,,,:::: \n ;;;;;;;;;:::::::::::::,,,,,,#'''+'''++'''''';;;;;;;;;'''''''++'''';':,,,,,,,,,,,,,,,,,,,,,,,:::: \n ;;;;;;;;;::::::::::::,,,,,,,:;'''+'+++''''';''++++++'''''''++''''';+.,,,,,,,,,,,,,,,,,,,,,,,:::: \n ;;;;;;;;:::::::::::::,,,,,,,,+;''++++++;';''''++#+++''''''+'+++'''+,,,,,,,,,,,,,,,,,,,,,,,,,:::: \n ;;;;;;;;;;::::::::::::,,,,,,,:''''++'++';;;''+++##++'''';''+++'+';+,,,,,,,,,,,,,,,,,,,,,,,,::::: \n ;;;;;;;;;;::::::::::,:,,,,,,,:';+'+++''',,,;++++++++++';,;;+'+++'+,,,,,,,,,,,,,,,,,,,,,,,,:::::: \n ;;;;;;;;;;::::::::::::,,,,,,,,:+''+'+++;:,.,...''+++++:,;:;'+'+'+;.,,,,,,,,,,,,,,,,,,,,,,,:::::: \n ;;;;;;;;;;;:::::::::::,,,,,,,,::#++++++;::,,,.,.'''++',;;;''++'++:,,,,,,,,,,,,,,,,,,,,,,,,:::::: \n ;;;;;;;;;;;:::::::::::,,,,,,,,,,++'++'+;':,:,,,:;'+'',::;;+'#'++';.,,,,,,,,,,,,,,,,,,,,,,,,::::: \n ;;;;;;;;;;;:::::::::::,,,,,,,,,,+++++'+';''':::::'';:;;:;';+++';';;;.,,,,,,,,,,,,,,,,,,,,::::::: \n ;;;;;;;;;;;;;::::::::::,,,,,,,'++''++++'''';;'';''';':'+'++#++';+;,;:,,,,,,,,,,,,,,,,,,,,::::::: \n ;';;;;;;;;;;;::::::::::,,,,,''''++++++##''#'+''''''';;'+++++'+''';,:,:.,,,,,,,,,,,,,,,,,:::::::: \n ;';;;;;;;;;;;:::::::::,,,,:'''';+#++++#+++'+''';'''';''+++++'''#;::;:::;:..,,,,,,,,,,,,,:::::::: \n ;';'';;;;;;;;::::::::::,,:;;;'';'###++++#++''';;''''''+#++++++++;:::::::;;,`,,,,,,,,,,,,:::::::: \n ;''';;;;;;;;;;::::::::,:``;;''':'+###+++++++#+++++'+++++++++++#;;::,::::::```,,,,,,,,,,,:::::::: \n ''''';;;;;;;;;:::::::::``.;;;'':''####++#++++++++++++++++++++++;:::,:::::.```.,,,,,,,,,::::::::: \n ''''';;;;;;;;;:::::,`````.::';':;'+#####+++++++++++++'+++++++#;;::::;,:::.``````,,,,,,,::::::::: \n '''''';;;;;;;;;:,,``````.`.';;',:''#+##+++++++'++''+++++++++#';::::::::,:```````````.:,::::::::: \n '''''''';;;;;`````````````:;;;'::'+##++##+++++++++++++++++++#;::;:;::::,:`````````````:::::::::: \n '''''''';;;```````````````,;;;':,''+#++#++++++++++++++++++##;::;;;;:,::,.```````````````,::::::: \n '''''''''`````````````````.;;;':,''+#+++#+++++++'+++++++++++;::;;;;:.:::,``````````````````::::: \n '''''''.```````````````````;;;;:,;''+#+++++++++++++++++++++;;;;;;;;:.:::.````````````````````::: \n '''';``````````````````````:;;;:,;'''###+++++++++++++++++#;;;;;;;;;:.:::```````.```````````````: \n '''````````````````````````,;;;:,;''''##++++++++++++++++++';;;;;;;;.`::,```````````````````````` \n ''`````````````````````````.;;;:,;''';+###++++++++++++++##;;;;;;;;.``:,.```````````````````````` \n +```````````````````````````;;;:,.,'@@:###+++++++++++++#+;;;;;;;;:```:,````````````````````````` \n ````````````````````````````:;;:,.#+##+;'###+++++++++++#+;;;;;;;:````:,````````````````````````` \n `````````````````````````````;::`++++###':##++++++++++#;####';;.`````:,````````````````````````` \n `````````````````````````````.;:,+++++####'#+###++###''######+#;:````,.````````````````````````` \n ````````````````````````````````+++++++#####;+#+;:;:+########';''@.``,`````````````````````````` \n ```````````````````````````````:++++++++#####'#########++++++++++++'`.`````````````````````````` \n ``````````````````````````````;;;;;,;+########+###+#++++++++++'''+++,```````````````````````````";
        cout << "\nHello Bjarni." << endl;

    }
    else if(skosveinn == 2)
    {

        cout << "``````````````````````````````````````````````````````````````````````````````````````````````` \n ``````````````````````````````````````````````````````````````````````````````````````````````` \n ``````````````````````````````````````````````````````````````````````````````````````````````` \n ``````````````````````````````````````````````````````````````````````````````````````````````` \n ``````````````````````````````````````````````````````````````````````````````````````````````` \n ``````````````````````````````````````````````````````````````````````````````````````````````` \n ``````````````````````````````````````````````````````````````````````````````````````````````` \n ``````````````````````````````````````````````````````````````````````````````````````````````` \n ``````````````````````````````````````````````````````````````````````````````````````````````` \n ``````````````````````````````````````````````````````````````````````````````````````````````` \n `````````````````````````````````````````````````` ```````````````````````````````````````````` \n ``````````````````````````````````````````` ``,;;;;:.`````````````````````````````````````````` \n ````````````````````````````````````````` :''+'';';;::;.``````````````````````````````````````` \n ````````````````````````````````````````:'''++''''':+;;:;`````````````````````````````````````` \n ```````````````````````````````````````;'+'++;''''';';':;;````````````````````````````````````` \n ``````````````````````````````````````;+'+;++';'''';';;;;;',``````````````````````````````````` \n ```````````````````````````````````` ;;';'';';'';:;:;;;;:;'':`````````````````````````````````` \n ````````````````````````````````````;:;;;;::;;:;:;;;:':;;;''',````````````````````````````````` \n ```````````````````````````````````,:;;;::,,:::::,,,::;:::;;''````````````````````````````````` \n ``````````````````````````````````.:,::,,,,,,,,,,,,,,,,,:::;'';```````````````````````````````` \n .`````````````````````````````````:,,,,,,,,,,,,,.,,,,,,,,:::;';```````````````````````````````` \n ``````````````````````````````````:,,,,,,,,,,.,....,,,,,:::::;',``````````````````````````````` \n `````````````````````````````````.:,,,,,,...........,,,,:::,:;;;``````````````````````````````` \n `````````````````````````````````,:,,,,,............,,,,,:::::;;``````````````````````````````` \n `````````````````````````````````,:,,,,,.............,,,,:::::;;``````````````````````````````` \n `````````````````````````````````::,,,,,..............,,,,::::::..````````````````````````````` \n `````````````````````````````````::,,,,,..............,,,,::::::...```````````````````````````` \n `````````````````````````````````::,,,,,.............,,,,:::::::...```````````````````````````` \n `````````````````````````````````::,,,,..............,,,,::::;::....``````````````````````````` \n `````````````````````````````````:::,,,,.............,,,,::::;;:,...``````````````````````````` \n `````````````````````````````````::,,,,..............,,,,:::::;:,....`````````````````````````` \n `````````````````````````````````,:,,,,..............,,,,,::::::,,...`````````````````````````` \n `````````````````````````````````::::,,,,:,.......:,,,,::::;::::,,...`````````````````````````` \n ````````````````````````````````,,::::;:;;:,,....::;';;::::;;:::,,,...````````````````````````` \n ```````````````````````````````.,,::::,:;';:,,,,,:;'';:::::;;:;;,:,...````````````````````````` \n ```````````````````````````````.:,:::;+;:';';,,,;':;;'+';:::;::;;:,....```````````````````````` \n ```````````````````````````````.,,,,:;;:':.;;,.,;::,:';;';:::::;,:,....```````````````````````` \n ```````````````````````````````..,,,,,,,,:,,:,.,;::,:,,::,,,:::;,,,...````````````````````````` \n ```````````````````````````````..,,,..,::,,::,.,:::,,:::,,,,:::;,..,...```````````````````````` \n ```````````````````````````````,.,,....,,.,,:,.,::,,,,,,,,,,,::,,.,....```````````````````````` \n ```````````````````````````````,.,,,,.....,,:,.,::,,......,,:::,,.,....```````````````````````` \n ```````````````````````````````,.,,,......,::,.,::,.......,,,::.,,,,....``````````````````````` \n ```````````````````````````````..:,,......,:,..,:::,......,,::;..,,,....``````````````````````` \n ````````````````````````````````.,,,,....,:,,..,::,:,,...,,,:;;..,,,,....`````````````````````` \n ````````````````````````````````,,,,,..,,,,,,..,::::,:,,,,,::::.,::,,....`````````````````````` \n `````````````````````````````````.::,,,:,,:;;,,:''',,,:,,,:::;;,:::,,....`````````````````````` \n ``````````````````````````````````::,,:,,,,,,;'',,,,,,,:,::::;;;:::,,....`````````````````````` \n ``````````````````````````````````,,::,,,.,,.,,.,,,,,,,,:::,,:;;;;::,....`````````````````````` \n ``````````````````````````````````,.:.,::,,,,....,,,,:;,,,:,,:;;;;::,....`````````````````````` \n ``````````````````````````````````.,,,..;;:.::::;;:;;;:,.,,,::;;;;::,...``````````````````````` \n ```````````````````````````````````:.,..,:+``....,,';,,,.,,,;;;;;;::,...``````````````````````` \n ```````````````````````````````````.,,..,,,:;,,.:;::,,,..,,::;;;;::,,...``````````````````````` \n ````````````````````````````````````:,,.,,,:,,,,,,:,,,,.,,,;;:;;;::,,..```````````````````````` \n `````````````````````````````````````:,.,,,,,,,.,,,,,,,.,,:;;:;;::,,...```````````````````````` \n .````````````````````````````````````,,,,,,,,,,,,,,,,,,,::;'::;;::,,...```````````````````````` \n ``````````````````````````````````````:,,,,,,,,,,,,,,,,,::;:::;::,,....```````````````````````` \n .`````````````````````````````````````.:,.,,,,...,,,.,,::;'::::::,,....```````````````````````` \n .````````````````````````````````````.`:,,,,,....,,,.,::;+,,:,.;:,.....```````````````````````` \n ..`````````````````````````````````````::,,,,.....,,,:;;+,,,,`,':,....````````````````````````` \n ..`````````````````````````````````````::::,,.....,,:;;+,,,,:...#:....````````````````````````` \n ..````````````````````````````````````.:,:;:,,,,,,::;;+,,,,, ...##,...````````````````````````` \n ..`````````````````````````````````````.,,:;;::::;;;+;,,,,,`.`.`###+``````````````````````````` \n ..`````````````````````````````````````.,,,:;'';;'+;:,,....``...####@..```````````````````````` \n ...`````````````````````````````````````,,,:,,,,,,,,,,,,..`````,######+.``````````````````````` \n ...```````````````````````````````````'`,,,,:,.....,,,..```````;#########`````````````````````` \n ...````````````````````````````````` #+.,,,,::,...,,,..````````#########+##. `````````````````` \n ..```````````````````````````````` .###;`,,,,:,..,,,..````````.###########+##' ```````````````` \n ..`````````````````````````````` ,@####'.`,.,,:,,,,..```````` `###############+#``````````````` \n ..```````````````````````````` ,#######'.``..,,:,,.. ` ``````,.+##################, ``````````` \n ..`````````````````````````` '########+#++``..,,,..``+#`````.`'#####################+: ```````` \n ..``````````````````````` ,############+++++  .,..`##++#``` .`######################+###, ````` \n ..````````````````````` ;################++###``.###+++#.``,``##########################+#+. `` \n ..``````````````````` '##################++++#++#++++++##`,`` #############################+#+` \n ..````````````````` '######################++#+#+####+###,```,###############################++ \n ...```````````````+############################+#####++##'```;################################# \n ...```````````` ######################;###++#####++######+```+################################# \n ..```````````` #######################.+######:.,+++###+#'```################################## \n ...```````````'#######################``++##+`````,++++##;```################################## \n ...```````````+######################+```..`.```````'+++#````################################## \n ...``````````'#######################'``..`.```````````..```:################################## \n ....```````` ########################,``````````````````````'################################## \n ....```````` ########################```````````````````````################################### \n .....``````` ########################```````````` ``````````################################### \n ,....````````+#######################`````````` ``````````` ################################### \n ,,...````````+#######################`.`````````````````````+################################## \n ,,,...```````+######################+`.``````` ````````````,################################### \n ,,....```````#######################'.```````` ````````````'################################### \n ,,.,...`````,######################+:.```````` ````````````#################################### \n ,,,....`````'#######################,``````````````````````#################################### \n ,,,,....````+######################+`````````` ``````````` #################################### \n ,,,,,...````#+######################`````````` `` `````````+################################### \n ,,,,,,..````########################````````````` ````````:#################################### \n :,,,,,,..```######################+#``````````````````````+#################################### \n ,:,,,,,,..``########################``````````````````````##################################### \n ..,,,,,,...`#++####################+````````````````````` ##################################### ";
        cout << "\nHello Maggi." << endl;

    }
    else
    {

        cout << "Error: Invalid Skosveinn? Enter '1' if you are Skosveinn 1 or enter '2' if you are Skosveinn 2?" << endl;
        cin >> skosveinn;
    }

    printGrid(grid);

    while(1)
    {

        umferdir ++;
        insertPosition(grid, player);

        printGrid(grid);

        if (didIWin(grid) == 'X')
        {
            cout << "Winner is: X" << endl;
            break;
        }
        else if (didIWin(grid) == 'O')
        {
            cout << "Winner is: O" << endl;
            break;
        }
        else if (didIWin(grid) == 'Q' && umferdir == 9)
        {
            cout << "DRAW!" << endl;
            break;
        }
        XorY(player);
    }


}

void ConsoleUI::printGrid (char grid[3][3])
{

    for(int i = 0 ; i < 3 ; i++)
    {

        for(int k = 0 ; k < 3 ; k++)
        {

            cout << grid[i][k] << " ";
        }
        cout << endl;
    }
}

void ConsoleUI::insertPosition(char grid[3][3], char player)
{

    char position;

    cout << player << " position: ";
    cin >> position;

    if (position == '1' && grid[0][0] == '1')
    {
        grid[0][0] = player;
    }
    else if (position == '2' && grid[0][1] == '2')
    {
        grid[0][1] = player;
    }
    else if (position == '3' && grid[0][2] == '3')
    {
        grid[0][2] = player;
    }
    else if (position == '4' && grid[1][0] == '4')
    {
        grid[1][0] = player;
    }
    else if (position == '5' && grid[1][1] == '5')
    {
        grid[1][1] = player;
    }
    else if (position == '6' && grid[1][2] == '6')
    {
        grid[1][2] = player;
    }
    else if (position == '7' && grid[2][0] == '7')
    {
        grid[2][0] = player;
    }
    else if (position == '8' && grid[2][1] == '8')
    {
        grid[2][1] = player;
    }
    else if (position == '9' && grid[2][2] == '9')
    {
        grid[2][2] = player;
    }
    else
    {
        cout << "Invalid Position!" << endl;
        insertPosition(grid, player);
    }
}

void ConsoleUI::XorY(char& player)
{

    if(player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

char ConsoleUI::didIWin(char grid[3][3])
{

    if (grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X')
    {
        return 'X';
    }
    else if (grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X')
    {
        return 'X';
    }
    else if (grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X')
    {
        return 'X';
    }

    else if (grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X')
    {
        return 'X';
    }
    else if (grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X')
    {
        return 'X';
    }
    else if (grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X')
    {
        return 'X';
    }

    else if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X')
    {
        return 'X';
    }
    else if (grid[2][0] == 'X' && grid[1][1] == 'X' && grid[0][2] == 'X')
    {
        return 'X';
    }


    else if (grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O')
    {
        return 'O';
    }
    else if (grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O')
    {
        return 'O';
    }
    else if (grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O')
    {
        return 'O';
    }

    else if (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O')
    {
        return 'O';
    }
    else if (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O')
    {
        return 'O';
    }
    else if (grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O')
    {
        return 'O';
    }

    else if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O')
    {
        return 'O';
    }
    else if (grid[2][0] == 'O' && grid[1][1] == 'O' && grid[0][2] == 'O')
    {
        return 'O';
    }

    return 'Q';

}

