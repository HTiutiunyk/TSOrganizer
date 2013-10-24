#include "database.h"

DataBase::DataBase(QObject *parent) :
    QObject(parent)
{
}

DataBase::DataBase(QString name)
{
    database = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    database->setDatabaseName(name);
    database->open();

    //add check for table content
    query = new QSqlQuery();
    query->exec( "CREATE TABLE IF NOT EXISTS `tasks` ( "
                 " `id` INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 " `name` CHAR, `text` TEXT, 'status' CHAR default 'active')");
}

void DataBase::addTask(QString name, QString text)
{
    QString execString;
    execString = "INSERT INTO tasks (name,text) VALUES('"+name+"','"+text+"')";
    query->exec(execString);
}

QStringList DataBase::getTaskList()
{
    query->exec("select name from tasks where status = 'active'");
    QStringList nameList;
    while (query->next())
    {
        nameList<<query->value(0).toString();
    }
    return nameList;
}

QStringList DataBase::getDoneTaskList()
{
    query->exec("select name from tasks where status = 'done'");
    QStringList nameList;
    while (query->next())
    {
        nameList<<query->value(0).toString();
    }
    return nameList;
}

QString DataBase::getTaskByName(QString name)
{
    query->exec("SELECT * FROM tasks where name = '"+name+"'");
    QString textToName;
    textToName = "";
    while (query->next())
    {
        textToName+="<h1>"+query->value(1).toString()+"</h1><hr>"+query->value(2).toString()+"<br>";
    }
    return textToName;
}

void DataBase::setDoneTask(QString name)
{
    query->exec("UPDATE tasks SET status = 'done' where name = '"+name+"'");
}

void DataBase::deleteTask(QString name)
{
    query->exec("DELETE FROM tasks WHERE name = '"+name+"'");
}
