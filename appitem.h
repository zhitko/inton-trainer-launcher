#ifndef APPITEM_H
#define APPITEM_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QFont>

class AppItem : public QLabel
{
public:
    AppItem(QString text, QWidget * parent = 0);

protected:
    virtual void enterEvent(QEvent *ev);
    virtual void leaveEvent(QEvent *ev);
    virtual void mousePressEvent(QMouseEvent * ev);

    QFont font();
};

#endif // APPITEM_H
