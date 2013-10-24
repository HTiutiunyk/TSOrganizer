#include "settingspage.h"
#include "ui_settingspage.h"
#include <QDebug>

settingsPage::settingsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingsPage)
{
    ui->setupUi(this);
    settings = new QSettings("Settings.ini",QSettings::IniFormat,this);
    connect(ui->pushButton,SIGNAL(clicked()),SLOT(getPath()));
}

settingsPage::~settingsPage()
{
    delete ui;
}

void settingsPage::getPath()
{
    QString fileName = QDir::toNativeSeparators(QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.jpg *.bmp *.jpeg *.png);")));
    if (fileName.length() != 0)
        settings->setValue("path", fileName);
}
