#include "tree.h"

Tree::Tree()
{
    listItem = makeTree();
}

QList<QTreeWidgetItem*> Tree::makeTree()
{
    QSqlQuery query = Database::query("SELECT * FROM parent WHERE id != 1 AND pid=1");
    QTreeWidgetItem *item;
    while (query.next())
    {
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
            makeChild(query.value("id").toInt(), listItem, *item);
        }
    }
    return listItem;
}

QList<QTreeWidgetItem *> Tree::getListItem()
{
    return listItem;
}

bool Tree::hasChild(QString name)
{
    QSqlQuery query = Database::query("SELECT id FROM parent WHERE name='" + name + "'");
    query.next();
    bool result = hasChild(query.value(0).toInt());
    return result;
}

void Tree::makeChild(int id, QList<QTreeWidgetItem *> &listItem, QTreeWidgetItem &item)
{
    QTreeWidgetItem *tmp;
    items.push(&item);
    QSqlQuery query = Database::query("SELECT * FROM parent WHERE pid = " + QString::number(id));
    while (query.next())
    {
        if(!hasChild(query.value("id").toInt()))
        {
            QStringList name;
            name << query.value("name").toString();
            tmp = new QTreeWidgetItem(name);
            items.last()->addChild(tmp);
        }
        else
        {
            QStringList name;
            name << query.value("name").toString();
            tmp = new QTreeWidgetItem(name);
            makeChild(query.value("id").toInt(), listItem, *tmp);
        }
    }
    tmp = items.pop();
    if(items.size() == 0)
    {
        listItem.append(tmp);
    }
    else
    {
        items.last()->addChild(tmp);
    }
    return;
}

bool Tree::hasChild(int id)
{
    QSqlQuery query = Database::query("SELECT COUNT(*) FROM parent WHERE pid=" + QString::number(id));
    query.next();
    if(query.value(0).toInt() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

QSqlQueryModel Tree::printTable(QTreeWidgetItem &item, QTreeWidget &witdget)
{

}
