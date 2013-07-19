#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Tree tree; //create a tree of data from the database
    ui->setupUi(this);
    ui->treeWidget->addTopLevelItems(tree.getListItem()); //insret tree on QTreeWitdget
}

MainWindow::~MainWindow()
{
    delete ui;
}
