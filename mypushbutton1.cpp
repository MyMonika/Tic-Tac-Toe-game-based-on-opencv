#include "mypushbutton1.h"
#include <QPushButton>
#include <QDebug>
mypushbutton1::mypushbutton1(QWidget *parent) : QPushButton(parent)
{
    qDebug()<<"painting";
    this->setStyleSheet("Qpushbutton{border:0px;}");

}
