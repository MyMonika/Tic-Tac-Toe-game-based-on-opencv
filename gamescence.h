#ifndef GAMESCENCE_H
#define GAMESCENCE_H

#include <QMainWindow>
#include <QWidget>
#include <QRect>
#include <QMouseEvent>
#include "mypushbutton1.h"
#include <QScrollArea>
#include <QLabel>
#include <QListWidget>
#include <QMessageBox>
#include<iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
namespace Ui {
class gameScence;
}

class gameScence : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameScence(QWidget *parent = nullptr);
    ~gameScence();
    void paintEvent(QPaintEvent* );
    void Listarea();//进度条拖拽函数
    void ItemColor1(bool s, int row);//Item字体显示
    void Dialog(int i);//胜负对话框
    void deleteAllSlot();//清空listwidget
    void paintCircle(int row,int colomn);//绘画圆
	void judge2();
    void InitAll();
    bool checkRow(int row, int player);
    bool line2(int player);//检查右对角线是否三连
    //检查左对角线是否三连
    bool line1(int player);
    //检查是否有列三连
    bool checkCol(int col, int player);

    //将棋子落位的格子所代表的数赋值为该玩家的号（1和2）
    //检测行列和对角线是否三连
    //输出：1代表1获胜，2代表2获胜，0代表目前没有玩家胜出
    int move(int num, int player);
	//计算机识别
    void getResult(cv::Mat img);
    int detectGrid(cv::Mat img);
    Point show2();
    void changeW(int v, void*);
    void changeB(int v, void*);
    void changeparams2(int p, void*);
    void changeminR(int r, void*);
    void changemaxR(int r, void*);
    bool isFull();
    void Dialog2();
    //函数指针部分：
    typedef void (gameScence::*pFUN)(int , void* );
    void funcW(pFUN *pfun2);
    //计算机识别
    cv::Mat gray_blur;
    cv::Mat gray;
    int params2 = 38;
    int minR = 20;
    int maxR = 60;
    int x, y, w, h = 0;
    int radius = 0;
    int radius1 = 0;
    int whitex, whitey, blackx, blacky = 0;
    int r[9] = { 0 };
    int detected[9] = { 0,0,0,0,0,0,0,0,0 };
    vector<Vec3f> circles;
    vector<Point> finalResult;
    cv::Point center;
    cv::Point center1;
    Scalar hsvWhiteLow;
    Scalar hsvWhiteHigh;
    Scalar hsvBlackLow;
    Scalar hsvBlackHigh;
signals://信号部分
    void leaved();//返回按钮
    void leaveOk();//再开一盘
    void leaveNo();//关闭游戏

private:
    Ui::gameScence *ui;
    mypushbutton1 *back;//返回按钮
    QLabel *label;//标签栏
    QListWidget *list;//定义list
    //定义绘图的起始坐标
    const int x1=20;
    const int y1=100;
    //定义棋盘高度与宽度
    int WIDTH;
    int HEIGHT;
    int CenterX;
    int CenterY;
    int player1[2][9];
    int flag[10]={3};//决定画什么颜色
    int arr[3][3];//3行3列的棋盘
    int step;//用于记录步数
    int times=0;
    int iii ;//接收move的 结果
    //检查是否有行三连
    QMessageBox msgBox;//游戏结束后跳出的对话框
    QMessageBox warnning;//游戏结束后跳出的对话框
//    void (gameScence::*pfunB)(int , void* ) = &gameScence::changeB;
//    void (gameScence::*pfunW)(int , void* ) = &gameScence::changeW;
//    void (gameScence::*pfunS2)(int , void* ) = &gameScence::changeparams2;
//    void (gameScence::*pfunMin)(int , void* ) = &gameScence::changeminR;
//    void (gameScence::*pfunMax)(int , void* ) = &gameScence::changeminR;


};
#endif // GAMESCENCE_H
