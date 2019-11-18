#include "launcher.h"
#include "ui_launcher.h"

#include <QPainter>
#include <QImage>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QApplication>

#include "appitem.h"

Launcher::Launcher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Launcher)
{
    ui->setupUi(this);
    this->addApplications(this->findApplications());
}

Launcher::~Launcher()
{
    delete ui;
}

void Launcher::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    QDir dir(QApplication::applicationDirPath());
    QImage image(dir.absoluteFilePath("image.png"));
    painter.drawImage(0,0, image);

    this->ui->space->setFixedHeight(image.height());
    this->setFixedWidth(image.width());
}

void Launcher::addApplications(QStringList applications)
{
    QFont sansFont("Helvetica [Cronyx]", 12);
    foreach (QString app, applications) {
        AppItem * label = new AppItem(app, this);
        this->ui->appsList->addWidget(label);
    }
}

QStringList Launcher::findApplications()
{
    QDir dir(QApplication::applicationDirPath());
    dir.cd("applications");
    return dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
}
