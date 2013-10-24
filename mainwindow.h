#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>
#include <QFileDialog>
#include "database.h"
#include "newtaskwindow.h"
#include "settingspage.h"
#include <QDir>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSettings *settings;
    DataBase *core;
    newTaskWindow *addTaskWindow;
    settingsPage *settingsWindow;
    void setTable(QStringList name);
    void setDoneTable(QStringList name);
    void generatePostList(QString name);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString doneName;
    QString delName;

private:
    Ui::MainWindow *ui;

private slots:
    void showTaskByName(int row, int);
    void showDoneByName(int row, int);
    void appendTaskToDb(QString name, QString text);
    void loadTasks();
    void showAddPage();
    void setTaskDone(int row, int);
    void setDone();
    void delTask();
    void setDelName(int row, int);
    void showTimeTableImage();
    void hideTimeTableImage();
    void showSettingsWindow();
};

#endif // MAINWINDOW_H
