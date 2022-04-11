#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include "mypushbutton1.h"
#include <QTimer>
#include "gamescence.h"
#include "gamescence2.h"
#include <iostream>
#include <QMainWindow>
#include "difficultty.h"
#include<iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
using namespace std;

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //实例化游戏场景
    game1=new gameScence;
    game2=new Difficultty;
    //绑定ui界面的父类
    ui->setupUi(this);
    this->setFixedSize(800,600);
    //设立窗口名
    this->setWindowTitle("Triple Chess Game");
    //设立窗口图标
    this->setWindowIcon(QIcon(":/chess.png"));
    //设立widget的位置
    ui->widget->move(0.5*(this->width()-ui->widget->width()),0.5*(this->height()-ui->widget->height()));
    //设立一个监视器back
    connect(game1,&gameScence::leaved,this,[=](){
        QTimer::singleShot(100,this,[=](){
            game1->hide();
            this->show();
        });
    });
     //设立一个监视器再开一把(人人与人机)
    connect(game1,&gameScence::leaveOk,this,[=](){
        game1->deleteAllSlot();
        game1->hide();
        QTimer::singleShot(100,this,[=](){
        game1->show();
        });
    });
    connect(game2->gameCom,&gameScence2::leaveOk,this,[=](){
        game2->gameCom->deleteAllSlot();
       game2->gameCom->hide();
        QTimer::singleShot(100,this,[=](){
        game2->gameCom->show();
        game2->gameCom->judge(game2->gameCom->getdiff());
        });
    });
    //设立一个监视器从难度选择中返回
    connect(game2,&Difficultty::comeback,this,[=](){
        QTimer::singleShot(400,this,[=](){
            game2->hide();
            this->show();
        });

    });
    // //设立一个监视器离开游戏（人人与人机）
    connect(game1,&gameScence::leaveNo,this,[=](){
        game1->hide();
        this->close();
    });
    connect(game2->gameCom,&gameScence2::leaveNo,this,[=](){
        game2->gameCom->hide();
        this->close();
    });
    //人机对战的按钮
    connect(ui->Combtn,&mypushbutton1::clicked,[=](){
            this->hide();
            game2->show();
    });
    //点击离开游戏从而关闭游戏
    connect(ui->Exitbtn,&mypushbutton1::clicked,this,[=](){
        this->close();
    });
    //点击开始游戏切换场景
    connect(ui->Startbtn,&mypushbutton1::clicked,[=](){
        QTimer::singleShot(400,this,[=](){
            this->hide();
            game1->show();
            game1->judge2();
        });
    });
}

MainWindow::~MainWindow()
{
    delete game1;
    delete game2;
    delete ui;

}
void MainWindow:: paintEvent(QPaintEvent *){
    QPainter painter(this);
    //添加背景
    QPixmap pix;
    pix.load(":/tooopen_sl_17042442479476.jpg");
    painter.setRenderHint(QPainter::LosslessImageRendering,true);
    painter.drawPixmap(0,0,this->width(), this->height(),pix);
}
