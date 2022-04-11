#ifndef GAMESCENCECOM_H
#define GAMESCENCECOM_H

#include <QMainWindow>

namespace Ui {
class gameScenceCom;
}

class gameScenceCom : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameScenceCom(QWidget *parent = nullptr);
    ~gameScenceCom();

private:
    Ui::gameScenceCom *ui;
};

#endif // GAMESCENCECOM_H
