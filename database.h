#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>

class DataBase : public QObject
{
    Q_OBJECT
    QSqlQuery *query;
public:
    explicit DataBase(QObject *parent = 0);
    QSqlDatabase *database;
    DataBase(QString name);
    void addTask(QString name, QString text);
    QStringList getTaskList();
    QStringList getDoneTaskList();
    QString getTaskByName(QString name);
    void setDoneTask(QString name);
    void deleteTask(QString name);

signals:

public slots:

};

#endif // DATABASE_H
