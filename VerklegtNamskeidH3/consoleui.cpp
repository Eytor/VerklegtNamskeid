#include "consoleui.h"
#include <iomanip>
#include <iostream>


ConsoleUI::ConsoleUI()
{

}

int ConsoleUI::selection()
{
    int selectNum;
    cout << "1. Add to List." << endl
         << "2. Display List." << endl
         << "3. Search from list" << endl
         << "4. Order list." << endl
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
             _service.addToList();
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

void ConsoleUI::printPerson(int i)
{
    const char seperator = ' ';
    const int sexWidth = 5;
    const int yearWidth = 6;
    const int nameWidth = 25;
    string fullName =  _service.getName(i);
    string gender =  _service.getGender(i);
    int YoB =  _service.getYoB(i);
    int YoD =  _service.getYoD(i);

    cout << left << setw(nameWidth) << setfill(seperator) << fullName;
    cout << left << setw(sexWidth) << setfill(seperator) << gender;
    if(YoB != 0)
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
        const int firstNameWidth = 25;
        const int sexWidth = 5;
        const int yearWidth = 6;
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
        cout << "List is empty!";
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
