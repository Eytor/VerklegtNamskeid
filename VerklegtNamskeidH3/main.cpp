#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct TolPers{
    string name;
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
    string sex;
    int birth;
    int death;
    TolPers pers;
    while(file >> name >> sex >> birth >> death)
    {
        pers.name = name;
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
    cout << "Select number or people:";
    cin >> numOfPeople;
    TolPers pers;
    for(int i = 0; i < numOfPeople; i++)
    {

        cout << "Name: ";
        cin >> pers.name;
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
void displayList(vector<TolPers> person, int count)
{
    for(int i = 0; i < count; i++)
    {
        cout << "Name: " << person[i].name << endl
             << "Sex: " << person[i].sex << endl
             << "Year of birth: " << person[i].yearOfBirth << endl;
            if(person[i].yearOfDeath != 0)
            {
                cout << "Year of Death: " << person[i].yearOfDeath << endl;
            }
            cout << endl;
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
