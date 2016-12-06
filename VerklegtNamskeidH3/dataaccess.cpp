#include "dataaccess.h"

DataAccess::DataAccess()
{

}

void DataAccess::getFromDB(vector<TolComp>& computer, vector<TolPers>& person)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString Tolvunarfraedi = "Tolvunarfraedi.sqlite";
    db.setDatabaseName(Tolvunarfraedi);

    db.open();

    QSqlQuery query(db);

    query.exec("SELECT * FROM Computers");

    TolComp comp;
    while(query.next())
    {
        comp.ID = query.value("ID").toUInt();
        comp.name = query.value("Name").toString().toStdString();
        comp.type = query.value("Type").toString().toStdString();
        comp.built = query.value("Built");
        comp.year = query.value("Year").toUInt();
        computers.push_back(comp);
    }

    query.exec("SELECT * FROM People");
    TolPers pers;
    while(query.next())
    {
        pers.ID = query.value("ID").toUInt();
        pers.fullName = query.value("FullName").toString().toStdString();
        pers.gender = query.value("Gender").toString().toStdString();
        pers.yearOfBirth = query.value("Yob").toUInt();
        pers.yearOfDeath = query.value("Yod").toUInt();
        person.push_back(pers);
    }
    db.close();
}

void DataAccess::retriveInfo(vector<TolPers>& person, vector<TolPers>& tBin)
{
    ifstream file, trash;
    file.open ("list.txt");
    trash.open ("bin.txt");
    string name, middleInitial, lastName, sex;
    int birth, death;
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
    }
    file.close();
    while(trash >> name >> middleInitial >> lastName >> sex >> birth >> death)
    {
        pers.name = name;
        pers.middleInitial = middleInitial;
        pers.lastName = lastName;
        pers.sex = sex;
        pers.yearOfBirth = birth;
        pers.yearOfDeath = death;
        tBin.push_back(pers);
    }
    trash.close();
}

void DataAccess::updateFile(vector<TolPers> person)
{
    ofstream file;
    remove("list.txt");
    file.open("list.txt");
    if(file.is_open())
    {
        for(unsigned int i = 0; i < person.size(); i++)
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
}


void DataAccess::updateTrash(vector<TolPers> trash)
{
    ofstream trashbin;
    trashbin.open("bin.txt");
    if(trashbin.is_open())
    {
        for(unsigned int i = 0; i < trash.size(); i++)
        {
            trashbin << trash[i].name << '\t' ;
            trashbin << trash[i].middleInitial << '\t';
            trashbin << trash[i].lastName << '\t';
            trashbin << trash[i].sex << '\t';
            trashbin << trash[i].yearOfBirth << '\t';
            trashbin << trash[i].yearOfDeath << endl ;
        }
        trashbin.close();
    }
}

void DataAccess::emptyTrash()
{
    remove("bin.txt");
}
