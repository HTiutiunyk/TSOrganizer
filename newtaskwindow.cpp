#include "newtaskwindow.h"
#include "ui_newtaskwindow.h"

newTaskWindow::newTaskWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newTaskWindow)
{
    ui->setupUi(this);

    //CONNECT ZONE
    connect(ui->pushButton,SIGNAL(clicked()),SLOT(addNewTask()));
    connect(ui->escButton,SIGNAL(clicked()),SLOT(close()));
    //CONNECT ZONE
}

newTaskWindow::~newTaskWindow()
{
    delete ui;
}

void newTaskWindow::addNewTask()
{
    QString name = ui->lineEdit->text();
    QString text = ui->plainTextEdit->toPlainText();
    if (name.length() != 0)
    {
        emit addTaskToDb(name, text);
        emit refreshList();
        this->close();
        ui->lineEdit->clear();
        ui->plainTextEdit->clear();
    }
    else
    {
        qDebug()<<"empty";
        this->close();
        ui->lineEdit->clear();
        ui->plainTextEdit->clear();
    }
}
