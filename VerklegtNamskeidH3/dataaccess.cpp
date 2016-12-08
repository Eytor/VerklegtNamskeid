#include "dataaccess.h"

DataAccess::DataAccess()
{

    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString Tolvunarfraedi = "Tolvunarfraedi.sqlite";
    _db.setDatabaseName(Tolvunarfraedi);
    _db.open();

}

void DataAccess::getFromDB(vector<TolComp>& computer, vector<TolPers>& person, vector<TolComp>& deletedComputer, vector<TolPers>& deletedPerson)
{
    QSqlQuery query(_db);

    query.exec("SELECT * FROM Computers");

    TolComp comp;
    TolPers pers;
    while(query.next())
    {
        comp.ID = query.value("ID").toUInt();
        comp.name = query.value("Name").toString().toStdString();
        comp.type = query.value("Type").toString().toStdString();
        comp.built = query.value("Built").toBool();
        comp.year = query.value("Year").toUInt();
        computer.push_back(comp);
    }

    query.exec("SELECT * FROM People");

    while(query.next())
    {
        pers.ID = query.value("ID").toUInt();
        pers.fullName = query.value("FullName").toString().toStdString();
        pers.gender = query.value("Gender").toString().toStdString();
        pers.yearOfBirth = query.value("Yob").toUInt();
        pers.yearOfDeath = query.value("Yod").toUInt();
        person.push_back(pers);
    }

    query.exec("SELECT * FROM DeletedComputers");

    while(query.next())
    {
        comp.ID = query.value("ID").toUInt();
        comp.name = query.value("Name").toString().toStdString();
        comp.type = query.value("Type").toString().toStdString();
        comp.built = query.value("Built").toBool();
        comp.year = query.value("Year").toUInt();
        deletedComputer.push_back(comp);
    }

    query.exec("SELECT * FROM DeletedPeople");

    while(query.next())
    {
        pers.ID = query.value("ID").toUInt();
        pers.fullName = query.value("FullName").toString().toStdString();
        pers.gender = query.value("Gender").toString().toStdString();
        pers.yearOfBirth = query.value("Yob").toUInt();
        pers.yearOfDeath = query.value("Yod").toUInt();
        deletedPerson.push_back(pers);
    }
}

void DataAccess::addToComputers(vector<TempTolComp> computer)
{
    QSqlQuery query(_db);

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
}

void DataAccess::addToPeople(vector<TempTolPers> people)
{
    QSqlQuery query(_db);

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
}

void DataAccess::deletePerson(int i)
{
    QSqlQuery query(_db);
    query.prepare("DELETE FROM People "
                  "WHERE ID = :id");
    query.bindValue(":id", i);
    query.exec();

}

void DataAccess::deleteDeletedPerson(int i)
{
    QSqlQuery query(_db);
    query.prepare("DELETE FROM DeletedPeople "
                  "WHERE ID = :id");
    query.bindValue(":id", i);
    query.exec();

}

void DataAccess::deleteComputer(int i)
{
    QSqlQuery query(_db);
    query.prepare("DELETE FROM Computers "
                  "WHERE ID = :id");
    query.bindValue(":id", i);
    query.exec();

}

void DataAccess::deleteDeletedComputer(int i)
{
    QSqlQuery query(_db);
    query.prepare("DELETE FROM DeletedComputers "
                  "WHERE ID = :id");
    query.bindValue(":id", i);
    query.exec();

}

void DataAccess::addToDeletedPeople(vector<TempTolPers> people)
{
    QSqlQuery query(_db);

    for(unsigned int i = 0; i < people.size(); i++)
    {
        query.prepare("INSERT INTO DeletedPeople(FullName, Gender, Yob, Yod) "
                      "VALUES(:name, :gender, :yob, :yod)");
        query.bindValue(":name", people[i].fullName.c_str());
        query.bindValue(":gender", people[i].gender.c_str());
        query.bindValue(":yob", people[i].yearOfBirth);
        query.bindValue(":yod", people[i].yearOfDeath);
        query.exec();
    }
}

void DataAccess::addToDeletedComputers(vector<TempTolComp> computer)
{
    QSqlQuery query(_db);

    for(unsigned int i = 0; i < computer.size(); i++)
    {
        query.prepare("INSERT INTO DeletedComputers(Name, Type, Built, Year) "
                      "VALUES(:name, :type, :built, :year)");
        query.bindValue(":name", computer[i].name.c_str());
        query.bindValue(":type", computer[i].type.c_str());
        query.bindValue(":built", computer[i].built);
        query.bindValue(":year", computer[i].year);
        query.exec();
    }
}

void DataAccess::emptyDeletedPeople()
{
    QSqlQuery query(_db);
    query.exec("DELETE FROM DeletedPeople");

}

void DataAccess::emptyDeletedComputers()
{
    QSqlQuery query(_db);
    query.exec("DELETE FROM DeletedComputers");
}

void DataAccess::sort(vector<TolPers>& persVector, vector<TolComp>& compVector, int datab, int col, int ord)
{
    QString database;
    QString column;
    QString order;
    QSqlQuery query(_db);
    if(datab == 1)
    {
        database = "People";

        if(col == 1)
        {
            column = "FullName";
        }
        else if(col == 2)
        {
            column = "Gender";
        }
        else if(col == 3)
        {
            column = "Yob";
        }
        else
        {
            column = "Yod";
        }
    }
    else
    {
        database = "Computers";

        if(col == 1)
        {
            column = "Name";
        }
        else if(col == 2)
        {
            column = "Type";
        }
        else if(col == 3)
        {
            column = "Built";
        }
        else
        {
            column = "Year";
        }
    }

    if(ord == 1)
    {
        order = "ASC";
    }
    else
    {
        order = "DESC";
    }

    query.exec("SELECT * FROM "+ database +" ORDER BY "+ column + " COLLATE NOCASE " + order);

    if(datab == 1)
    {
        TolPers pers;
        while(query.next())
        {
            pers.ID = query.value("ID").toUInt();
            pers.fullName = query.value("FullName").toString().toStdString();
            pers.gender = query.value("Gender").toString().toStdString();
            pers.yearOfBirth = query.value("Yob").toBool();
            pers.yearOfDeath = query.value("Yod").toUInt();
            persVector.push_back(pers);
        }

    }
    else
    {
        TolComp comp;
        while(query.next())
        {
            comp.ID =  query.value("ID").toUInt();
            comp.name = query.value("Name").toString().toStdString();
            comp.type = query.value("Type").toString().toStdString();
            comp.built = query.value("Built").toBool();
            comp.year = query.value("Year").toUInt();
            compVector.push_back(comp);
        }
    }
}

void DataAccess::search(vector<TempTolSearch> &something, string s)
{
    QSqlQuery query(_db);
    QString keyword = QString::fromStdString(s);
    query.exec("SELECT FullName, Gender, Yob, Yod FROM People"
               "WHERE FullName LIKE %" + keyword +
               "% OR Gender LIKE %" + keyword +
               "% OR Yob LIKE %" + keyword +
               "OR Yod LIKE %" + keyword + "%");
    TempTolSearch searching;
    while(query.next())
    {
        searching.name = query.value("FullName").toString().toStdString();
        searching.gender = query.value("Gender").toString().toStdString();
        searching.yearOfBirth = query.value("Yob").toUInt();
        searching.yearOfDeath = query.value("Yod").toUInt();
        something.push_back(searching);
    }
}
