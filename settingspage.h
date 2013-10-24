#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>
#include <QSettings>
#include <QFileDialog>
#include <QDir>

namespace Ui {
class settingsPage;
}

class settingsPage : public QWidget
{
    Q_OBJECT
    QSettings *settings;

public:
    explicit settingsPage(QWidget *parent = 0);
    ~settingsPage();

private:
    Ui::settingsPage *ui;

private slots:
    void getPath();
};

#endif // SETTINGSPAGE_H
