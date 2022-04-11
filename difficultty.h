#ifndef DIFFICULTTY_H
#define DIFFICULTTY_H

#include <QMainWindow>
#include <QWidget>
#include <mypushbutton1.h>
#include "gamescence2.h"
namespace Ui {
class Difficultty;
}

class Difficultty : public QMainWindow
{
    Q_OBJECT

public:
    explicit Difficultty(QWidget *parent = nullptr);
    ~Difficultty();
    void paintEvent(QPaintEvent *);
    gameScence2 *gameCom;
signals:
    void comeback();
    void easyChoose();
    void normalChoose();
    void hardChoose();
    void SoHardChoose();
private:
    Ui::Difficultty *ui;
    mypushbutton1 *back;
};

#endif // DIFFICULTTY_H
