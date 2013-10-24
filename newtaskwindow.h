#ifndef NEWTASKWINDOW_H
#define NEWTASKWINDOW_H

#include <QWidget>
#include "database.h"

namespace Ui {
class newTaskWindow;
}

class newTaskWindow : public QWidget
{
    Q_OBJECT

public:
    explicit newTaskWindow(QWidget *parent = 0);
    ~newTaskWindow();
signals:
    void addTaskToDb(QString name, QString text);
    void refreshList();
private:
    Ui::newTaskWindow *ui;
private slots:
    void addNewTask();
};

#endif // NEWTASKWINDOW_H
