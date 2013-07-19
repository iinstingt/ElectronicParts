#include "database.h"

Database::Database()
{
    //connect("localhost", "dev", "root", "", "mydb");
}

Database::~Database()
{
    disconnect();
    db.removeDatabase(nameDataBase);
}

QSqlQuery Database::query(QString query)
{
    QSqlQuery* my;
    my = new QSqlQuery(db);
    if(!db.isOpen())
    {
        qDebug() << "Could not connect to database";
        return *my;
    }
    if(my->exec(query))
    {
        return *my;
    }
    else
    {
        qDebug() << "Query error!" << my->lastError();
        return *my;
    }
}

void Database::connect(QString host, QString database, QString user, QString passwd, QString name = "mydb")
{
    nameDataBase = name;
    db = QSqlDatabase::addDatabase("QMYSQL", name);
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(passwd);
    if(db.open())
        qDebug() << "Connect: OK";
    else
        qDebug() << db.lastError();
}

void Database::connect()
{
    connect("localhost", "dev", "root", "", "mydb");
}

void Database::disconnect()
{
    db.close();

}
