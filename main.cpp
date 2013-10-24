#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QCoreApplication::setOrganizationName("Tyutyunyk G. soft");
    QCoreApplication::setApplicationName("TSOrganizer");

    return a.exec();
}
