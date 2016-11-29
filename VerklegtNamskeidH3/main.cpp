#include <iostream>
#include <vector>
#include <fstream>
#include <locale>

using namespace std;

struct TolPers{
    string name;
    string middleInitial;
    string lastName;
    string sex;
    string yearOfBirth;
    string yearOfDeath;
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
    string birth;
    string death;
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
    cout << "1. Input people." << endl
         << "2. Display List." << endl
         << "3. Search from list" << endl
         << "4. Order list." << endl
         << "0. Quit." << endl;
    cin >> selectNum;
    return selectNum;

}

void InputPeople(vector<TolPers>& person, int& count)
{
    int numOfPeople;
    cout << "Select number or people: ";
    cin >> numOfPeople;
    TolPers pers;
    for(int i = 0; i < numOfPeople; i++)
    {

        cout << "First name: ";
        cin >> pers.name;
        cout << "Middle initial: ";
        cin >> pers.middleInitial;
        cout << "Last name: ";
        cin >> pers.lastName;
        cout << "Sex: ";
        cin >> pers.sex;
        cout << "Year of birth: ";
        cin >> pers.yearOfBirth;
        cout << "Year of death: ";
        cin >> pers.yearOfDeath;
        person.push_back(pers);
    }
    updateFile(person, numOfPeople, count);
}
void printPerson(vector<TolPers> person, int i)
{
    cout << "First name: " << person[i].name ;
    if(person[i].middleInitial != "0")
    {
    cout << " " << person[i].middleInitial;
    }
    cout << " " << person[i].lastName << endl
         << "Sex: " << person[i].sex << endl
         << "Year of birth: " << person[i].yearOfBirth << endl;
    if(person[i].yearOfDeath != "0")
    {
        cout << "Year of Death: " << person[i].yearOfDeath << endl;
    }
    cout << endl;
}

void displayList(vector<TolPers> person, int count)
{
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
    string term;
    cout << "Type what you are looking for in lowercase letters " << endl;
    cin.ignore();
    getline(cin,term);
    //int number; hér þurfum við að breyta string í int
    for(int i = 0; i < count; i++)
    {
        if((convertToLower(person[i].name) == convertToLower(term))||
           (convertToLower(person[i].middleInitial) == convertToLower(term))||
           (convertToLower(person[i].lastName) == convertToLower(term))||
           (convertToLower(person[i].sex) == convertToLower(term)) ||
           (person [i].yearOfBirth == term) || (person[i].yearOfDeath == term))
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

        /*else if(person[i].yearOfBirth == number)
        {
            found = true;
        }
        else if(person[i].yearOfDeath == number)
        {
            found = true;
        }*/


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
    int selected;
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
