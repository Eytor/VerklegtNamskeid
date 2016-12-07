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
        comp.built = query.value("Built").toBool();
        comp.year = query.value("Year").toUInt();
        computer.push_back(comp);
        _previousCompSize++;
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

void DataAccess::addToComputers(vector<TempTolComp> computer)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString Tolvunarfraedi = "Tolvunarfraedi.sqlite";
    db.setDatabaseName(Tolvunarfraedi);

    db.open();

    QSqlQuery query(db);

    for(unsigned int i = 0; i < computer.size(); i++)
    {
        query.prepare("INSERT INTO Computers(Name, Type, Built, Year) "
                      "VALUES(:name, :type, :built, :year)");
        query.bindValue(":name", computer[i].name.c_str());
        query.bindValue(":type", computer[i].type.c_str());
        query.bindValue(":built", computer[i].built);
        query.bindValue(":year", computer[i].year);
        query.exec();
    }
    db.close();
}

void DataAccess::addToPeople(vector<TempTolPers> people)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString Tolvunarfraedi = "Tolvunarfraedi.sqlite";
    db.setDatabaseName(Tolvunarfraedi);

    db.open();

    QSqlQuery query(db);

    for(unsigned int i = 0; i < people.size(); i++)
    {
        query.prepare("INSERT INTO People(FullName, Gender, Yob, Yod) "
                      "VALUES(:name, :gender, :yob, :yod)");
        query.bindValue(":name", people[i].fullName.c_str());
        query.bindValue(":gender", people[i].gender.c_str());
        query.bindValue(":yob", people[i].yearOfBirth);
        query.bindValue(":yod", people[i].yearOfDeath);
        query.exec();
    }


    db.close();
}

void DataAccess::deletePerson(int i)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString Tolvunarfraedi = "Tolvunarfraedi.sqlite";
    db.setDatabaseName(Tolvunarfraedi);

    db.open();

    QSqlQuery query(db);
    query.prepare("DELETE FROM PEOPLE "
                  "WHERE ID = :id");
    query.bindValue(":id", i);
    query.exec();

}
