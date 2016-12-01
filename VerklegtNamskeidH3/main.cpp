#include <iostream>
#include <vector>
#include <fstream>
#include <locale>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

struct TolPers{
    string name;
    string middleInitial;
    string lastName;
    string sex;
    int yearOfBirth;
    int yearOfDeath;
};

void updateFile(vector<TolPers> person, int num, int& count)
{
    ofstream file;
    file.open("list.txt");
    if(file.is_open())
    {
        for(int i = 0; i < (count+num); i++)
        {
            file << person[i].name << '\t' ;
            file << person[i].middleInitial << '\t';
            file << person[i].lastName << '\t';
            file << person[i].sex << '\t';
            file << person[i].yearOfBirth << '\t';
            file << person[i].yearOfDeath << endl ;
        }
        file.close();
    }
    count += num;
}

void retriveInfo(vector<TolPers>& person, int& count)
{
    ifstream file;
    file.open ("list.txt");
    string name;
    string middleInitial;
    string lastName;
    string sex;
    int birth;
    int death;
    TolPers pers;
    while(file >> name >> middleInitial >> lastName >> sex >> birth >> death)
    {
        pers.name = name;
        pers.middleInitial = middleInitial;
        pers.lastName = lastName;
        pers.sex = sex;
        pers.yearOfBirth = birth;
        pers.yearOfDeath = death;
        person.push_back(pers);
        count++;
    }
    file.close();
}

int selection()
{
    int selectNum;
    cout << "Hello! Please enter one of the following commands." << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1. Input people." << endl
         << "2. Display list." << endl
         << "3. Search from list" << endl
         << "4. Order list." << endl
         << "0. Quit." << endl;
    cout << "--------------------------------------------------" << endl;

    cin >> selectNum;
    return selectNum;

}
int sortSelection()
{
    int selectNum;
    cout << "Enter one of the following commands:" << endl << endl;
    cout << "1. Order by first name." << endl
         << "2. Order by last name." << endl
         << "3. Order by year of birth." << endl
         << "4. Order by year of death." << endl;
    cin >> selectNum;
    return selectNum;

}

void InputPeople(vector<TolPers>& person, int& count)
{

    int numOfPeople;
    cout << "Select number of people: ";
    cin >> numOfPeople;
    while (cin.fail()||numOfPeople<0)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid size. Select number from 1-100, '0' for main menu ";
        cin >> numOfPeople;
    }

    TolPers pers;
    for(int i = 0; i < numOfPeople; i++)
    {

        cout << "Name: ";
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


        person.push_back(pers);
    }
    updateFile(person, numOfPeople, count);
}
void printPerson(vector<TolPers> person, int i)
{
    const char seperator = ' ';
    const int sexWidth = 5;
    const int yearWidth = 6;
    const int nameWidth = 25;
    string fullName;

    /*cout << person[i].name ;
    if(person[i].middleInitial != "0")
    {
    cout << " " << person[i].middleInitial;
    }
    cout << " " << person[i].lastName << "\t"
         << person[i].sex << "\t"
         << person[i].yearOfBirth << "\t";
    if(person[i].yearOfDeath != "0")
    {
        cout << person[i].yearOfDeath << "\t";
    }
    cout << endl;*/

    if(person[i].middleInitial != "0")
    {
        fullName = person[i].name + " " + person[i].middleInitial + " " + person[i].lastName;
    }
    else
    {
        fullName = person[i].name + " " + person[i].lastName;    }

    cout << left << setw(nameWidth) << setfill(seperator) << fullName;
    cout << left << setw(sexWidth) << setfill(seperator) << person[i].sex;
    if(person[i].yearOfDeath != 0)
    {
        cout << left << setw(yearWidth) << setfill(seperator) << person[i].yearOfBirth
             << left << setw(yearWidth) << setfill(seperator) << person[i].yearOfDeath << endl;
    }
    else
    {
        cout << left << setw(yearWidth) << setfill(seperator) << person[i].yearOfBirth << endl;
    }
}

void displayList(vector<TolPers> person, int count)
{
    if(person.empty() == false)
    {
        const char seperator = ' ';
        const int firstNameWidth = 25;
        const int sexWidth = 5;
        const int yearWidth = 6;

        cout << left << setw(firstNameWidth) << setfill(seperator) << "Name"
             << left << setw(sexWidth) << setfill(seperator) << "Gender"
             << left << setw(yearWidth) << setfill(seperator) << "Birth"
             << left << setw(yearWidth) << setfill(seperator) << "Death" << endl;
    }


    for(int i = 0; i < count; i++)
    {
        printPerson(person, i);
    }
}
string convertToLower(string temp)
{
    locale loc;
    string lowerCaseString;
    for(unsigned int i = 0; i < temp.length(); i++)
    {
        lowerCaseString += tolower(temp[i],loc);
    }
    return lowerCaseString;
}


void search(vector<TolPers> person, int count)
{
    bool found = false;
    bool containsLetter = false;
    string term;
    cout << "What are you looking for?" << endl;
    cin.ignore();
    getline(cin,term);
    for(int i = 0; i < term.length(); i++)
    {
        if(isalpha(term[i]))
        {
            containsLetter = true;
        }
    }
    for(int i = 0; i < count; i++)
    {
        if(containsLetter)
        {
            if((convertToLower(person[i].name) == convertToLower(term))||
               (convertToLower(person[i].middleInitial) == convertToLower(term))||
               (convertToLower(person[i].lastName) == convertToLower(term))||
               (convertToLower(person[i].sex) == convertToLower(term)))
            {
                found = true;
            }
            else if((convertToLower(person[i].name + " " + person[i].middleInitial + " " + person[i].lastName) == convertToLower(term))||
                    (convertToLower(person[i].name + " " + person[i].lastName) == convertToLower(term))||
                    (convertToLower(person[i].name + " " + person[i].middleInitial) == convertToLower(term))||
                    (convertToLower(person[i].middleInitial + " " + person[i].lastName) == convertToLower(term)))
            {
                found = true;
            }
        }
        else if((person[i].yearOfBirth == stoi(term, 0, 10)) || ((person[i].yearOfDeath == stoi(term, 0, 10)) && stoi(term, 0, 10) != 0))
        {
            found = true;
        }

        if(found)
        {
            printPerson(person, i);
            found = false;
        }
    }
}



int main()
{
    vector<TolPers> personur;
    int count = 0;
    int selected = 1000;
    int sortSelect;
    retriveInfo(personur, count);

    while(selected != 0){
        selected = selection();
        switch (selected) {
        case 1:
            InputPeople(personur, count);
            cout << endl;
            break;
        case 2:
            displayList(personur, count);
            cout << endl;
        break;
        case 3:
            search(personur, count);
            break;
        case 4:
            sortSelect = sortSelection();
            switch (sortSelect) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            default:
                break;
            }
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }
    }
    return 0;
}
