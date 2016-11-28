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
    ifstream file;
    file.open ("list.txt");

    for(int i = count; i < (count+num); i++)
    {
        file >> person[i].name >> person[i].sex >> person[i].yearOfBirth >> person[i].yearOfDeath ;
    }
    file.close();
    count += num;
}

void retriveInfo(vector<TolPers> person, int& count)
{
    fstream file;
    file.open ("list.txt");
    string name;
    string sex;
    int birth;
    int death;
    while(file >> name >> sex >> birth >> death)
    {
        TolPers pers;
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
         << "4. Order list." << endl;
    cin >> selectNum;
    return selectNum;

}

void InputPeople(vector<TolPers> person, int& count)
{
    int numOfPeople;
    cout << "Select number or people:";
    cin >> numOfPeople;

    for(int i = 0; i < numOfPeople; i++)
    {
        TolPers pers;
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
            break;
        case 2:
            displayList(personur, count);
        break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            break;
        default:
            cout << "Wrong input";
            break;
        }
    }
    return 0;
}
