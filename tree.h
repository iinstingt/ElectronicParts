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

private:
    QList<QTreeWidgetItem*> listItem;
    void makeChild(int id, QList<QTreeWidgetItem*> &listItem, QTreeWidgetItem &item  );
    bool hasChild(int id);
    QStack<QTreeWidgetItem*> items;
};

#endif // TREE_H
