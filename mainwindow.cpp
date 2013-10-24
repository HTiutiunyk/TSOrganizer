#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    core = new DataBase("database.sqlite");
    settings = new QSettings("Settings.ini",QSettings::IniFormat,this);
    addTaskWindow = new newTaskWindow();
    settingsWindow = new settingsPage();
    loadTasks();
    ui->taskView->hide();
    ui->timeTableImage->hide();
    ui->hideTTButton->hide();
    restoreGeometry(settings->value("geometry",saveGeometry()).toByteArray());
    //CONNECT ZONE
    connect(ui->newTaskButton,SIGNAL(clicked()),SLOT(showAddPage()));
    connect(addTaskWindow,SIGNAL(addTaskToDb(QString,QString)),SLOT(appendTaskToDb(QString,QString)));
    connect(addTaskWindow,SIGNAL(refreshList()),SLOT(loadTasks()));
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),SLOT(showTaskByName(int,int)));
    connect(ui->tableWidgetDone,SIGNAL(cellClicked(int,int)),SLOT(showDoneByName(int,int)));
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),SLOT(setTaskDone(int,int)));
    connect(ui->tableWidgetDone,SIGNAL(cellClicked(int,int)),SLOT(setDelName(int,int)));
    connect(ui->doneTaskButton,SIGNAL(clicked()),SLOT(setDone()));
    connect(ui->delButton,SIGNAL(clicked()),SLOT(delTask()));
    connect(ui->timeTableButton,SIGNAL(clicked()),SLOT(showTimeTableImage()));
    connect(ui->hideTTButton,SIGNAL(clicked()),SLOT(hideTimeTableImage()));
    connect(ui->settingsButton,SIGNAL(clicked()),SLOT(showSettingsWindow()));
    //CONNECT ZONE
}

void MainWindow::setTable(QStringList name)
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    for(int i=0;i<=name.count()-1;i++)
    {
        int lastRow = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(lastRow);
        QTableWidgetItem *item=new QTableWidgetItem (name[i]);
        ui->tableWidget->setItem(lastRow,0,item);
    }
}

void MainWindow::setDoneTable(QStringList name)
{
    ui->tableWidgetDone->clear();
    ui->tableWidgetDone->setRowCount(0);
    ui->tableWidgetDone->setColumnCount(1);
    ui->tableWidgetDone->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetDone->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetDone->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetDone->verticalHeader()->setVisible(false);
    ui->tableWidgetDone->horizontalHeader()->setVisible(false);
    for(int i=0;i<=name.count()-1;i++)
    {
        int lastRow = ui->tableWidgetDone->rowCount();
        ui->tableWidgetDone->insertRow(lastRow);
        QTableWidgetItem *item=new QTableWidgetItem (name[i]);
        ui->tableWidgetDone->setItem(lastRow,0,item);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
    settings->setValue("geometry",saveGeometry());
}

void MainWindow::showTaskByName(int row, int)
{
    ui->taskView->setHtml(core->getTaskByName(ui->tableWidget->item(row, 0)->text()));
    ui->taskView->show();
}

void MainWindow::showDoneByName(int row, int)
{
    ui->taskView->setHtml(core->getTaskByName(ui->tableWidgetDone->item(row, 0)->text()));
    ui->taskView->show();
}

void MainWindow::appendTaskToDb(QString name, QString text)
{
    core->addTask(name, text);
}

void MainWindow::loadTasks()
{
    setTable(core->getTaskList());
    setDoneTable(core->getDoneTaskList());
}

void MainWindow::showAddPage()
{
    addTaskWindow->show();
}

void MainWindow::setTaskDone(int row, int)
{
    QString name = ui->tableWidget->item(row, 0)->text();
    doneName = name;
}

void MainWindow::setDone()
{
    core->setDoneTask(doneName);
    loadTasks();
    ui->taskView->setHtml("");
}

void MainWindow::delTask()
{
    core->deleteTask(delName);
    loadTasks();
    ui->taskView->setHtml("");
}

void MainWindow::setDelName(int row, int)
{
    QString name = ui->tableWidgetDone->item(row, 0)->text();
    delName = name;
}

void MainWindow::showTimeTableImage()
{
    ui->timeTableImage->show();
    ui->delButton->hide();
    ui->newTaskButton->hide();
    ui->doneTaskButton->hide();
    ui->timeTableButton->hide();
    ui->hideTTButton->show();
    ui->tabWidget->hide();
    ui->settingsButton->hide();
    ui->timeTableImage->setScaledContents(true);
    QString filePath = settings->value("path").toString();
    ui->timeTableImage->setPixmap(filePath);
    settings->setValue("geometry",saveGeometry());
    restoreGeometry(settings->value("geometryImage",saveGeometry()).toByteArray());
}

void MainWindow::hideTimeTableImage()
{
    ui->timeTableImage->hide();
    ui->delButton->show();
    ui->newTaskButton->show();
    ui->doneTaskButton->show();
    ui->timeTableButton->show();
    ui->hideTTButton->hide();
    ui->tabWidget->show();
    ui->settingsButton->show();
    settings->setValue("geometryImage",saveGeometry());
    restoreGeometry(settings->value("geometry",saveGeometry()).toByteArray());
}

void MainWindow::showSettingsWindow()
{
    settingsWindow->show();
}



