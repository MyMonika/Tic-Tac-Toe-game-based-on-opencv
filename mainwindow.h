#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamescence.h"
#include "difficultty.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    gameScence *game1;//游戏界面
    Difficultty *game2;//难度界面
};
#endif // MAINWINDOW_H
