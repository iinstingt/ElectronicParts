#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class Database
{
public:
    Database();
    ~Database();
    QSqlQuery query(QString query);
    void connect(QString host, QString database, QString user, QString passwd, QString name);
    void connect();
    void disconnect();
private:
    QSqlDatabase db;
    QString nameDataBase;

};

#endif // DATABASE_H
