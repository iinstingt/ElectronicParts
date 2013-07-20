#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>

Tree tree; //create a tree of data from the database

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->treeWidget->addTopLevelItems(tree.getListItem()); //insret tree on QTreeWitdget
    this->setWindowIcon(QIcon("://Resurces/iconMainWindow.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Slot for settigns button
void MainWindow::on_actionSettings_triggered()
{

}

void MainWindow::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    if(!Tree::hasChild(ui->treeWidget->currentItem()->text(0)))
    {
        QTreeWidgetItem* lastItem = ui->treeWidget->currentItem();
        while(ui->treeWidget->indexOfTopLevelItem(lastItem)==-1)
        {
            lastItem = lastItem->parent();
        }


        QSqlQuery query = Database::query("SELECT CONCAT('SELECT ',(SELECT GROUP_CONCAT(COLUMN_NAME)"
                                          "FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_SCHEMA='dev' "
                                          "AND TABLE_NAME='" + lastItem->text(0) + "' AND COLUMN_NAME NOT IN "
                                          "('id', 'pid', 'Decr', 'package') ORDER BY ORDINAL_POSITION), ',name as Package FROM " + lastItem->text(0) + "');");
        query.next();
        query = Database::query(query.value(0).toString() + " INNER JOIN packs on " + lastItem->text(0) + ".package=packs.id WHERE pid IN(SELECT id FROM parent "
                                "WHERE name='" + ui->treeWidget->currentItem()->text(0) + "')");
        qDebug() << endl << query.lastQuery();
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(query);
        ui->tableView->setModel(model);
        ui->tableView->show();
    }



}
