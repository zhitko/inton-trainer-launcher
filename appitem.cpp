#include "appitem.h"

#include <QDir>
#include <QApplication>
#include <QProcess>

#include <QDebug>

AppItem::AppItem(QString text, QWidget * parent) : QLabel(text, parent)
{
    this->setFont(this->font());
    this->setAlignment(Qt::AlignHCenter);
}

QFont AppItem::font()
{
    return QFont("Helvetica [Cronyx]", 12);
}

void AppItem::enterEvent(QEvent *ev)
{
    QFont font = this->font();
    font.setBold(true);
    font.setPixelSize(20);
    this->setFont(font);
}

void AppItem::leaveEvent(QEvent *ev)
{
    this->setFont(this->font());
}

void AppItem::mousePressEvent(QMouseEvent * ev)
{
    QDir dir(QApplication::applicationDirPath());
    dir.cd("applications");
    dir.cd(this->text());

    QProcess * process = new QProcess(this);
    process->setWorkingDirectory(dir.absolutePath());
    QString file = dir.absoluteFilePath("intontrainer.exe");

    qDebug() << QString("\"%1\"").arg(file);

    process->start(QString("\"%1\"").arg(file));
}

