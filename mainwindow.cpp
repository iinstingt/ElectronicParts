#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStack>

QSqlDatabase db;
QStack<QTreeWidgetItem*> items;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL", "mydb");
    db.setHostName("localhost");
    db.setDatabaseName("dev");
    db.setUserName("root");
    db.setPassword("");
    if(db.open())
        qDebug() << "Connect: OK";
    else
        qDebug() << db.lastError();

    drow();


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::hasChild(int id)
{
    QSqlQuery *query;
    query = new QSqlQuery(db);
    query->exec("SELECT COUNT(*) FROM parent WHERE pid=" + QString::number(id));
    query->next();
    if(query->value(0).toInt() > 0)
        return true;
    else
        return false;
}

void MainWindow::drow() {
    QList<QTreeWidgetItem*> listItem;
    QSqlQuery *query;
    query = new QSqlQuery(db);
    query->exec("SELECT * FROM parent WHERE id != 1 AND pid=1");


    QTreeWidgetItem *item;

    while (query->next()) {
        if(!hasChild(query->value("id").toInt()))
        {
            QStringList name;
            name << query->value("name").toString();
            item = new QTreeWidgetItem(name);
            listItem.append(item);
        }
        else
        {
            QStringList name;
            name << query->value("name").toString();
            item = new QTreeWidgetItem(name);
            getAllChild(query->value("id").toInt(), listItem, *item);
        }
    }

    ui->treeWidget->addTopLevelItems(listItem);

}

void MainWindow::getAllChild(int id, QList<QTreeWidgetItem*> &listItem, QTreeWidgetItem &item  ) {
    items.push(&item);
    QSqlQuery *query;
    query = new QSqlQuery(db);
    query->exec("SELECT * FROM parent WHERE pid = " + QString::number(id));
     while (query->next()) {
         if(!hasChild(query->value("id").toInt()))
         {
             QStringList name;
             QTreeWidgetItem *item1;
             name << query->value("name").toString();
             item1 = new QTreeWidgetItem(name);
             items.last()->addChild(item1);
         }
         else
         {
             QTreeWidgetItem *itemNext;
             QStringList name;
             name << query->value("name").toString();
             itemNext = new QTreeWidgetItem(name);
             getAllChild(query->value("id").toInt(), listItem, *itemNext);
         }
     }

     if(items.size()==0)
     {

     }
     else
     {
         QTreeWidgetItem* item1;
         item1 = items.pop();
         if(items.size() == 0) {
             listItem.append(item1);
         }
         else
         {
             items.last()->addChild(item1);
         }

     }
     return;

}
