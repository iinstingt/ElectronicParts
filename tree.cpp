#include "tree.h"

Database database;
Tree::Tree()
{
    listItem = makeTree();
}

QList<QTreeWidgetItem*> Tree::makeTree()
{
    //database.connect();
    QSqlQuery query = database.query("SELECT * FROM parent WHERE id != 1 AND pid=1");
    QTreeWidgetItem *item;
    while (query.next()) {
        if(!hasChild(query.value("id").toInt()))
        {
            QStringList name;
            name << query.value("name").toString();
            item = new QTreeWidgetItem(name);
            listItem.append(item);
        }
        else
        {
            QStringList name;
            name << query.value("name").toString();
            item = new QTreeWidgetItem(name);
            qDebug() << query.value("id");
            makeChild(query.value("id").toInt(), listItem, *item);
        }
    }
    database.disconnect();
    return listItem;
}

QList<QTreeWidgetItem *> Tree::getListItem()
{
    return listItem;
}

void Tree::makeChild(int id, QList<QTreeWidgetItem *> &listItem, QTreeWidgetItem &item)
{
    items.push(&item);
        QSqlQuery query = database.query("SELECT * FROM parent WHERE pid = " + QString::number(id));
         while (query.next()) {
             if(!hasChild(query.value("id").toInt()))
             {
                 QStringList name;
                 QTreeWidgetItem *item1;
                 name << query.value("name").toString();
                 item1 = new QTreeWidgetItem(name);
                 items.last()->addChild(item1);
             }
             else
             {
                 QTreeWidgetItem *itemNext;
                 QStringList name;
                 name << query.value("name").toString();
                 itemNext = new QTreeWidgetItem(name);
                 makeChild(query.value("id").toInt(), listItem, *itemNext);
             }
         }
    QTreeWidgetItem* item1;
    item1 = items.pop();
    if(items.size() == 0)
    {
        listItem.append(item1);
    }
    else
    {
        items.last()->addChild(item1);
    }
    return;
}

bool Tree::hasChild(int id)
{
    QSqlQuery query = database.query("SELECT COUNT(*) FROM parent WHERE pid=" + QString::number(id));
    query.next();
    if(query.value(0).toInt() > 0)
        return true;
    else
        return false;
}
