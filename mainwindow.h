#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    bool hasChild(int id);
    void drow();
    void getAllChild(int id, QList<QTreeWidgetItem *> &listItem, QTreeWidgetItem &item  );
};

#endif // MAINWINDOW_H
