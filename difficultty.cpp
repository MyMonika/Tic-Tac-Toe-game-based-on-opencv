#include "difficultty.h"
#include "ui_difficultty.h"
#include <QPainter>
#include <QtWidgets>
#include <QPixmap>
#include "mypushbutton1.h"
#include "gamescence2.h"
#include <QTimer>
#include <iostream>
#include <QMainWindow>
Difficultty::Difficultty(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Difficultty)
{
    ui->setupUi(this);
    //建立页面
    gameCom=new gameScence2;
    this->setFixedSize(800,600);
    //设立窗口名
    this->setWindowTitle("Choose difficulty!");
    //设立窗口图标
    this->setWindowIcon(QIcon(":/chess.png"));
    this->ui->widget1->move(0.5*(this->width()-ui->widget1->width()),0.5*(this->height()-ui->widget1->height()));
    //设立按钮的位置
    back=new mypushbutton1();
    back->setParent(this);
    back->setFixedSize(60,30);
    back->setText("back");
    back->move(this->width()-back->width()-20,this->height()-back->height()-20);
    //返回按钮的监视
    connect(back,&mypushbutton1::clicked,this,[=](){
        emit comeback();
    });
    //选择难度
    connect(ui->Easy,&mypushbutton1::clicked,this,[=](){
        this->hide();
        gameCom->show();
        gameCom->judge(4);
    });
    connect(ui->Normal,&mypushbutton1::clicked,this,[=](){
        this->hide();
        gameCom->show();
        gameCom->judge(1);
    });
    connect(ui->Hard,&mypushbutton1::clicked,this,[=](){
        this->hide();
        gameCom->show();
         gameCom->judge(2);
    });
    connect(ui->SoHard,&mypushbutton1::clicked,this,[=](){
        this->hide();
        gameCom->show();
         gameCom->judge(3);
    });
    //正式人机的界面返回
    connect(gameCom,&gameScence2::leavedBack,this,[=](){
        QTimer::singleShot(400,this,[=](){
            gameCom->deleteAllSlot();
            gameCom->hide();
            this->show();
        });
    });
}

Difficultty::~Difficultty()
{
    delete ui;
    delete gameCom;
}
void Difficultty:: paintEvent(QPaintEvent *){
    QPainter painter(this);
    //添加背景
    QPixmap pix;
    pix.load(":/tooopen_sl_17042442479476.jpg");
    painter.setRenderHint(QPainter::LosslessImageRendering,true);
    painter.drawPixmap(0,0,this->width(), this->height(),pix);
}
