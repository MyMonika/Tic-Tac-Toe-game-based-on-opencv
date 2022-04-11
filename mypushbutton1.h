#ifndef MYPUSHBUTTON1_H
#define MYPUSHBUTTON1_H
#include <QWidget>
#include <QPushButton>
#include <iostream>


class mypushbutton1: public QPushButton
{
    Q_OBJECT
public:
   explicit mypushbutton1(QWidget *parent = nullptr);
};

#endif // MYPUSHBUTTON1_H
