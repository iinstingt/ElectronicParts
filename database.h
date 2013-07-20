#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>

class Database
{
public:
    Database();
    ~Database();
    static QSqlQuery query(QString query);
    static void connect(QString host, QString database, QString user, QString passwd, QString name);
    static void connect();
    static void disconnect();


};

#endif // DATABASE_H
