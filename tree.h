#ifndef TREE_H
#define TREE_H
#include "database.h"
#include <QStack>
#include <QTreeWidgetItem>

class Tree
{
public:
    Tree();
    QList<QTreeWidgetItem*> makeTree();
    QList<QTreeWidgetItem*> getListItem();
    QSqlQueryModel printTable(QTreeWidgetItem &item,  QTreeWidget &witdget);
    static bool hasChild(QString name);
    static bool hasChild(int id);

private:
    QList<QTreeWidgetItem*> listItem;
    void makeChild(int id, QList<QTreeWidgetItem*> &listItem, QTreeWidgetItem &item  );
    QStack<QTreeWidgetItem*> items;
};

#endif // TREE_H
