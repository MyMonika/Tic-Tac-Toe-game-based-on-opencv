#ifndef gameScence2_H
#define gameScence2_H

#include <QMainWindow>
#include <QWidget>
#include <QRect>
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
#include "mypushbutton1.h"
#include <QScrollArea>
#include <QLabel>
#include <QListWidget>
#include <QMessageBox>
#include <iostream>
using namespace std;

namespace Ui {
class gameScence2;
}
class gameScence2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameScence2(QWidget *parent = nullptr);
    ~gameScence2();
    void paintEvent(QPaintEvent* );
    void Listarea();//进度条拖拽函数
    void ItemColor1(int s, int row);//Item字体显示
    void Dialog(int i);//胜负对话框
    void deleteAllSlot();//清空listwidgetn
    void InitAll();
    void Compaint(int grid);
    void judge(int i);
    bool event(QEvent *ev);
    //人机对弈算法规则代码
    //电脑落子所对应的格子值为5
    //人落子所对应的格子值为2
    //空格子值为1
    int PcPlay_stupid();//返回棋子落位1~9，并将此位置的值赋为5
    int PcPlay_easy();//同上
    int PcPlay_normal();//同上
    int PcPlay();//同上
    int isWin();//胜负判断函数，返回值：1人赢；2电脑赢：0平局（不会判断是否下满）
    bool isFull();//棋盘是否满位判断，True:满，False:非满
    int getdiff();
    int m[9];//记录每格子下哪一个颜色
    int n[9];//记录是否下棋
signals:
    void leavedBack();//返回按钮
    void leaveOk();//再开一盘
    void leaveNo();//关闭游戏

private:
    Ui::gameScence2 *ui;
    mypushbutton1 *back;
    QLabel *label;
    QListWidget *list;//定义list
    QPainter painter;
    //定义起始坐标
    const int x=20;
    const int y=100;
    //定义棋盘高度与宽度
    int WIDTH;
    int HEIGHT;
    int CenterX;
    int CenterY;
    int player1[2][9];
    int filterD=0;//用来筛选难度，只能取4 1 2 3
    //检查是否有行三连
    QMessageBox msgBox;//游戏结束后跳出的对话框
    const int ROW=3;
    const int COL=3;
    int chessboard[3][3];//棋盘格子对应的值，用于区别电脑和玩家，以及权重算法
    int score[3][3];//算法中用道的权重变量，可不了解
    int order=1;
    int b=100;//记录电脑下在哪一格子
    int diff=3;//记录难度
    QEvent *ev;
    int g;//记录人在第几格子
};


#endif // gameScence2_H

