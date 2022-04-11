#include "gamescence2.h"
#include "ui_gamescence2.h"
#include "mypushbutton1.h"
#include <QPalette>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QRect>
#include <QBrush>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QListWidget>
#include <QFont>
#include <QTimer>
#include <QMessageBox>
#include <QIcon>
#include <QSize>
#include <iostream>
#include "difficultty.h"
using namespace std;
gameScence2::gameScence2(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::gameScence2)
{
	ui->setupUi(this);
	//清除缓存
   this->InitAll();
    //设立鼠标点击事件
    this->setMouseTracking(true);
	//画对战条框框
	this->Listarea();
	this->setFixedSize(800, 600);
	this->setWindowIcon(QIcon(":/chess.png"));
	//设立窗口名
	this->setWindowTitle("game has started!");
	//写返回按钮
	back = new mypushbutton1;
	back->setParent(this);
	back->setFixedSize(60, 30);
	back->setText("back");
	back->move(this->width() - back->width() - 20, this->height() - back->height() - 20);
	connect(back, &mypushbutton1::clicked, this, [=]() {
		emit leavedBack();
	});
	
}
    
gameScence2::~gameScence2()
{
    delete ui;
}
void gameScence2:: paintEvent(QPaintEvent *){

    //背景调色
    QPalette palette;
    palette.setColor(QPalette::Background,QColor("#B1723C"));
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    //实例化棋盘的画家
    QPainter painter(this);
    //实例化对战记录的画家
    //抗锯齿
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    //画三连棋的线条
    QPen pen(Qt::black,4);//默认是solidline直线，后期可以改
    painter.setPen(pen);
    //画边界线
    QRect rect(x,y,this->width()-40,this->height()-120);
    WIDTH=rect.width()/3;
    HEIGHT=rect.height()/3;
    painter.drawRect(rect);
    //画横线
    for(int i=0;i<3;i++)
    {
        painter.drawLine(x,y+HEIGHT*i,this->width()-20,y+HEIGHT*i);
    }
    //画竖线
    for(int i=0;i<3;i++)
    {
        painter.drawLine(x+WIDTH*i,y,x+WIDTH*i,this->height()-20);
    }
    //为对战记录加边框
    QPen pen1(Qt::white,12);
    painter.setPen(pen1);//设置画笔w形式
    QRect rect1(x,0,this->width()-40,90);
    painter.drawRect(rect1);
    for(int j=0;j<=8;j++){
        //电脑
        if(m[j]==1){
            QBrush brush2(Qt::black);
            painter.setPen(QPen(Qt::black,2));//设置画笔1形式
            painter.setBrush(brush2);//设置画刷1形式
            painter.drawEllipse(player1[0][j],player1[1][j],120,120);
            n[j]=1;
      }
        //玩家
        if(m[j]==0){
            QBrush brush2(Qt::white);
            painter.setPen(QPen(Qt::white,2));//设置画笔1形式
            painter.setBrush(brush2);//设置画刷1形式
            painter.drawEllipse(player1[0][j],player1[1][j],120,120);
            n[j]=1;
        }
    }

}
void  gameScence2::Listarea(){
    //设置listwidget
    list=new QListWidget(this);
    list->move(80,0);
    list->setFixedSize(this->width()-100,90);
    list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    list->setStyleSheet(QString("border-image:url(:/vo5eyRAGS3.jpg);border: 3px solid  #000000;"));
    //标签
    label=new QLabel(this);
    //设置边框型号和粗细
    label->setFrameShape (QFrame::Box);
     //这个会自动适应图片，我这里还设置了文本的颜色
    label->setScaledContents(true);
    label->setStyleSheet(QString("border-image:url(:/vo5eyRAGS3.jpg);border: 3px"));
//    label->setStyleSheet("border: 3px solid  #000000");
//    // 文字竖排以及其他
    label->setFont(QFont("Microsoft YaHei", 10, 75));
    label->setWordWrap(true);
    label->setAlignment(Qt::AlignCenter);
    label->move(x,0);
    label->setFixedSize(80,90);
    label->setText("Match record");
    //字体标签
//    Fontlabel=new QLabel();
//    Fontlabel->setPixmap(QPixmap(":/vo5eyRAGS3.jpg"));
}

void gameScence2:: ItemColor1(int flag2, int row){
    if(flag2==0){
        //玩家1
        QListWidgetItem *item=new QListWidgetItem(QString("the computer actions in the %1 grid").arg(row));
       // item->setBackground(QColor(Qt::white));//改变背景颜色
        item->setTextAlignment(Qt::AlignHCenter);//文本放中间
        list->addItem(item);
        update();
    }
    if(flag2==1){
        //玩家2
        QListWidgetItem *item=new QListWidgetItem(QString("the player actions in the %2 grid").arg(row));
       // item->setBackground(QColor(Qt::red));//改变背景颜色
        item->setTextAlignment(Qt::AlignHCenter);//文本放中间
        list->addItem(item);
        update();
        //qDebug()<<"has drawn";
    }
    else QListWidgetItem *item=new QListWidgetItem(QString("   "));
}
void gameScence2::Dialog(int i){
        msgBox.setWindowTitle("Result");/** 设置标题 **/
        if(i==1)
       { msgBox.setText("The player succeed!\n \n \n \n Do you want to play again with others?");}
        if(i==2)
       { msgBox.setText("The computer succeed!\n \n \n \n Do you want to play again with others?");}
        if(i==0)
       { msgBox.setText("No one wins! it is draw\n \n \n \n Do you want to play again with others?");}
      //  msgBox.setInformativeText("The player1 succeed!\n Do you want to play again with others?");
        msgBox.setStandardButtons( QMessageBox::Ok | QMessageBox::No);/** 添加标准按钮 **/
        msgBox.setDefaultButton(QMessageBox::Ok);/** 设置默认按钮 **/
        QPixmap pix;
        pix.load(":/chess.png");
        msgBox.setIconPixmap(pix);

        int ret = msgBox.exec();/** 返回点击的按钮对应的整型值 **/
        switch(ret){
        case QMessageBox::Ok:
            msgBox.hide();
            emit leaveOk();
            break;
        case QMessageBox::No:
            msgBox.hide();
            emit leaveNo();
            break;
        default:
            qDebug()<<"error!";
            }
}
void gameScence2::deleteAllSlot()
{
    int counter =list->count();
    for(int index=0;index<counter;index++)
    {
        QListWidgetItem *item = list->takeItem(0);
            delete item;
    }
    for (int i=0;i<2;i++) {
        for (int j=0;j<9;j++) {
            player1[i][j]=100000;
            player1[i][j]=100000;
        }
    }
    CenterX=NULL;
    CenterY=NULL;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            chessboard[i][j]=1;
        }
    }
    for (int j=0;j<9;j++) {
        m[j]=9;
        n[j]=0;
    }
}
void gameScence2::InitAll(){

    for (int i=0;i<2;i++) {
        for (int j=0;j<9;j++) {
            player1[i][j]=10000;
            player1[i][j]=10000;
        }
    }
    CenterX=100000;
    CenterY=100000;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            chessboard[i][j]=1;
        }
    }
    for (int j=0;j<9;j++) {
        m[j]=9;
        n[j]=0;
    }
}
int gameScence2::  PcPlay_stupid()
{
    int flag = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (chessboard[i][j] == 1)
            {
                flag = 1;
                chessboard[i][j] = 5;
                return i * 3 + j + 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
}
int gameScence2:: PcPlay_easy()
{
    while (1)
    {
        int row = rand() % 3;
        int col = rand() % 3;
        if (chessboard[row][col] == 1)
        {
            chessboard[row][col] = 5;
            return row * 3 + col + 1;
            break;
        }
    }
}
int gameScence2:: PcPlay_normal()
{
    int sum = 0;
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            score[i][j] = 0;

    // 对每行进行分数统计
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            sum += chessboard[i][j];

        switch (sum)
        {
        case 3:                     //1+1+1;重要性：最低;权重：1
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 1;
            }
            break;
        case 4:                     //1+1+2;重要性：次低;权重：10
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 2;
            }
            break;
        case 8:                    //1+2+5;重要性：较低，权值50
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 3;
            }
            break;
        case 7:                     //1+1+5;重要性：较高;权重：5
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 5;     //把行列的重要性比对角线高
            }
            break;
        case 5:                     //1+2+2;重要性：次高;权重：8
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 8;
            }
            break;
        case 11:                     //1+5+5;重要性：最高;权重：13
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 13;
            }
            break;
        }
        sum = 0;
    }

    // 对每列进行分数统计
    for (int j = 0; j < COL; j++)
    {
        for (int i = 0; i < ROW; i++)
            sum += chessboard[i][j];

        switch (sum)
        {
        case 3:
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[k][j] == 1)
                    score[k][j] += 1;
            }
            break;
        case 4:
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[k][j] == 1)
                    score[k][j] += 2;
            }
            break;
        case 8:
            for (int k = 0; k <
                COL; k++)
            {
                if (chessboard[k][j] == 1)
                    score[k][j] += 3;
            }
            break;
        case 7:
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[k][j] == 1)     //1+1+5;重要性：较高;权重：5
                    score[k][j] += 5;
            }
            break;
        case 5:
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[k][j] == 1)
                    score[k][j] += 8;
            }
            break;
        case 11:
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[k][j] == 1)
                    score[k][j] += 13;
            }
            break;
        }
        sum = 0;
    }

    // 对对角线进行分数统计
    for (int i = 0; i < ROW; i++)
        sum += chessboard[i][i];
    switch (sum)
    {
    case 3:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 1;
        }
        break;
    case 4:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 2;
        }
        break;
    case 8:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 3;
        }
        break;
    case 7:                     //1+1+5;权重：5
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 5;
        }
        break;
    case 5:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 8;
        }
        break;
    case 11:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 13;
        }
        break;
    }

    // 对反对角线进行分数统计
    sum = 0;
    for (int i = 0; i < ROW; i++)
        sum += chessboard[i][2 - i];
    switch (sum)
    {
    case 3:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)
                score[i][2 - i] += 1;
        }
        break;
    case 4:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)
                score[i][2 - i] += 2;
        }
        break;
    case 8:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)
                score[i][2 - i] += 3;
        }
        break;
    case 7:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)    //1+1+5;权重：5
                score[i][2 - i] += 5;
        }
        break;
    case 5:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)
                score[i][2 - i] += 8;
        }
        break;
    case 11:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)
                score[i][2 - i] += 13;
        }
        break;
    }

    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
        {
            if (score[i][j] > score[maxRow][maxCol])
            {
                maxRow = i;
                maxCol = j;
            }
        }
    chessboard[maxRow][maxCol] = 5;
    return maxRow * 3 + maxCol + 1;
}
int gameScence2::  PcPlay()
{
    int sum = 0;
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            score[i][j] = 0;

    // 对每行进行分数统计
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            sum += chessboard[i][j];

        switch (sum)
        {
        case 3:                     //1+1+1;重要性：最低;权重：1
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 1;
            }
            break;
        case 4:                     //1+1+2;重要性：次低;权重：10
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 10;
            }
            break;
        case 8:                    //1+2+5;重要性：较低，权值50
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 50;
            }
            break;
        case 7:                     //1+1+5;重要性：较高;权重：200
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 200;     //把行列的重要性比对角线高
            }
            break;
        case 5:                     //1+2+2;重要性：次高;权重：500
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 500;
            }
            break;
        case 11:                     //1+5+5;重要性：最高;权重：1000
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[i][k] == 1)
                    score[i][k] += 1000;
            }
            break;
        }
        sum = 0;
    }

    // 对每列进行分数统计
    for (int j = 0; j < COL; j++)
    {
        for (int i = 0; i < ROW; i++)
            sum += chessboard[i][j];

        switch (sum)
        {
        case 3:
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[k][j] == 1)
                    score[k][j] += 1;
            }
            break;
        case 4:
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[k][j] == 1)
                    score[k][j] += 10;
            }
            break;
        case 8:
            for (int k = 0; k <
                COL; k++)
            {
                if (chessboard[k][j] == 1)
                    score[k][j] += 50;
            }
            break;
        case 7:
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[k][j] == 1)     //1+1+5;重要性：较高;权重：200
                    score[k][j] += 200;
            }
            break;
        case 5:
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[k][j] == 1)
                    score[k][j] += 500;
            }
            break;
        case 11:
            for (int k = 0; k < COL; k++)
            {
                if (chessboard[k][j] == 1)
                    score[k][j] += 1000;
            }
            break;
        }
        sum = 0;
    }

    // 对对角线进行分数统计
    for (int i = 0; i < ROW; i++)
        sum += chessboard[i][i];
    switch (sum)
    {
    case 3:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 1;
        }
        break;
    case 4:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 10;
        }
        break;
    case 8:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 50;
        }
        break;
    case 7:                     //1+1+5;权重：100
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 100;
        }
        break;
    case 5:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 500;
        }
        break;
    case 11:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][i] == 1)
                score[i][i] += 1000;
        }
        break;
    }

    // 对反对角线进行分数统计
    sum = 0;
    for (int i = 0; i < ROW; i++)
        sum += chessboard[i][2 - i];
    switch (sum)
    {
    case 3:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)
                score[i][2 - i] += 1;
        }
        break;
    case 4:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)
                score[i][2 - i] += 10;
        }
        break;
    case 8:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)
                score[i][2 - i] += 50;
        }
        break;
    case 7:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)    //1+1+5;权重：100
                score[i][2 - i] += 100;
        }
        break;
    case 5:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)
                score[i][2 - i] += 500;
        }
        break;
    case 11:
        for (int i = 0; i < COL; i++)
        {
            if (chessboard[i][2 - i] == 1)
                score[i][2 - i] += 1000;
        }
        break;
    }

    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
        {
            if (score[i][j] > score[maxRow][maxCol])
            {
                maxRow = i;
                maxCol = j;
            }
        }
    chessboard[maxRow][maxCol] = 5;
    return maxRow * 3 + maxCol + 1;
}
int gameScence2:: isWin()
{
    int sum = 0;
    for (int i = 0; i < ROW; i++)      //对每行判断是否获胜
    {
        for (int j = 0; j < COL; j++)
            sum += chessboard[i][j];

        if (sum == 6)
        {
            printf("人获胜！\n");
            return 1;
        }
        if (sum == 15)
        {
            printf("电脑获胜！\n");
            return 2;
        }
        sum = 0;
    }

    for (int j = 0; j < ROW; j++)      //对每列判断是否获胜
    {
        for (int i = 0; i < COL; i++)
            sum += chessboard[i][j];

        if (sum == 6)
        {
            printf("人获胜！\n");
            return 1;
        }
        if (sum == 15)
        {
            printf("电脑获胜！\n");
            return 2;
        }
        sum = 0;
    }

    for (int i = 0; i < ROW; i++)     //对对角线判断是否获胜
        sum += chessboard[i][i];
    if (sum == 6)
    {
        printf("人获胜！\n");
        return 1;
    }
    if (sum == 15)
    {
        printf("电脑获胜！\n");
        return 2;
    }

    sum = 0;
    for (int i = 0; i < ROW; i++)     //对反对角线判断是否获胜
        sum += chessboard[i][2 - i];
    if (sum == 6)
    {
        printf("人获胜！\n");
        return 1;
    }
    if (sum == 15)
    {
        printf("电脑获胜！\n");
        return 2;
    }

    return 0;
}
bool gameScence2:: isFull()
{
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            if (chessboard[i][j] == 1)
                return false;
    return true;
}
//电脑画圆
void gameScence2::Compaint(int row){
   switch (row){
   case 1: CenterX=((this->width()/6)+x)/2;
           CenterY=((this->height()/6)+y+20)/2;
               this->ItemColor1(0,row);
               player1[0][0]=CenterX;
               player1[1][0]=CenterY;
               m[0]=1;
               qDebug()<<"kkk";
               update();
           break;
   case 2: CenterX=((this->width()*4/5)+x)/2;
           CenterY=((this->height()/6)+y+20)/2;
               this->ItemColor1(0,row);
               player1[0][1]=CenterX;
               player1[1][1]=CenterY;
               m[1]=1;
               update();
           break;
   case 3: CenterX=((this->width()*1.45)+x)/2;
           CenterY=((this->height()/6)+y+20)/2;
               this->ItemColor1(0,row);
               player1[0][2]=CenterX;
               player1[1][2]=CenterY;
               m[2]=1;
               update();
           break;
   case 4: CenterX=((this->width()/6)+x)/2;
           CenterY=((this->height()*0.72)+y+20)/2;

               this->ItemColor1(0,row);
               player1[0][3]=CenterX;
               player1[1][3]=CenterY;
               m[3]=1;

               update();
           break;
   case 5: CenterX=((this->width()*0.8)+x)/2;
           CenterY=((this->height()*0.72)+y+20)/2;
               this->ItemColor1(0,row);
               player1[0][4]=CenterX;
               player1[1][4]=CenterY;
               m[4]=1;
               update();
               qDebug()<<"jisuan";
           break;
   case 6: CenterX=((this->width()*1.45)+x)/2;
           CenterY=((this->height()*0.72)+y+20)/2;
               this->ItemColor1(0,row);
               player1[0][5]=CenterX;
               player1[1][5]=CenterY;
               m[5]=1;
               update();
           break;
   case 7: CenterX=((this->width()/6)+x)/2;
           CenterY=((this->height()*1.25)+y+20)/2;
               this->ItemColor1(0,row);
               player1[0][6]=CenterX;
               player1[1][6]=CenterY;
               m[6]=1;
               update();
           break;
   case 8: CenterX=((this->width()*0.8)+x)/2;
           CenterY=((this->height()*1.25)+y+20)/2;
               this->ItemColor1(0,row);
               player1[0][7]=CenterX;
               player1[1][7]=CenterY;
               m[7]=1;
               update();
           break;
   case 9: CenterX=((this->width()*1.45)+x)/2;
           CenterY=((this->height()*1.25)+y+20)/2;
               this->ItemColor1(0,row);
               player1[0][8]=CenterX;
               player1[1][8]=CenterY;
               m[8]=1;
               update();
           break;
   }
}
void gameScence2::judge(int ii)
{
    diff=ii;
         if ((isFull()==false) && (isWin() == 0)) {
                if(ii==4){
                    b = PcPlay_stupid();
                }
                if(ii==1){
                    b = PcPlay_easy();
                }
                if(ii==2){
                    b = PcPlay_normal();

                }
                if(ii==3){
                    b = PcPlay();
                }
                QTimer::singleShot(400,this,[=](){
                     this->Compaint(b);
                });
         }

        if (isWin() == 1) {
            this->Dialog(1);
            return;
        }
        if (isWin() == 2) {
            this->Dialog(2);
            return;
        }
        if (isFull() == true && isWin() == 0) {
            this->Dialog(0);
            return;
        }

}
//鼠标事件的拦截
bool gameScence2::event(QEvent *ev)
{
    if(ev->type() == QEvent::MouseButtonPress)
    {

        //一般情况下我们部队鼠标按键直接通过QEvent函数处理，而是经过其子类QMouseEvent类来处理
        QMouseEvent *e = (QMouseEvent *)ev;
        if(e->type() == QMouseEvent::MouseButtonPress)
        {
            //开始判断
            if(e->button()==Qt::LeftButton){
                //对横坐标进行约束，第1列
                if(e->pos().x()>20&e->pos().x()<x+WIDTH){
                    //对纵坐标进行约束，第一格
                    if(n[0]!=1){
                     if(e->pos().y()>100&e->pos().y()<y+HEIGHT*1){
                          CenterX=((this->width()/6)+x)/2;
                          CenterY=((this->height()/6)+y+20)/2;
                          player1[0][0]=CenterX;
                          player1[1][0]=CenterY;
                          this->ItemColor1(1,1);
                          chessboard[0][0]=2;
                          m[0]=0;
                          qDebug()<<"1";
                          update();
                          this->judge(diff);
                     }
                    }

                     //对纵坐标进行约束，第4格
                      else if(e->y()>(this->height()-40)/3 & e->y()<y+HEIGHT*2)
                      {
                       if(n[3]!=1){
                        CenterX=((this->width()/6)+x)/2;
                        CenterY=((this->height()*0.72)+y+20)/2;
                        this->ItemColor1(1,4);
                        player1[0][3]=CenterX;
                        player1[1][3]=CenterY;
                         chessboard[1][0]=2;
                         m[3]=0;
                        update();
                        this->judge(diff);
                      }
                    }
                     //对纵坐标进行约束，第7格
                      else if(e->pos().y()>y+HEIGHT*2 & e->pos().y()<y+HEIGHT*3)
                      {
                        if(n[6]!=1){
                         CenterX=((this->width()/6)+x)/2;
                         CenterY=((this->height()*1.25)+y+20)/2;
                         this->ItemColor1(1,7);
                         player1[0][6]=CenterX;
                         player1[1][6]=CenterY;
                          chessboard[2][0]=2;
                          m[6]=0;
                         update();
                         this->judge(diff);
                      }
                    }
                }
                //对横坐标进行约束，第2列
                if(e->pos().x()>x+WIDTH&e->pos().x()<x+WIDTH*2){
                    //对纵坐标进行约束，第2格
                      if(e->pos().y()>100&e->pos().y()<y+HEIGHT*1){
                       if(n[1]!=1){
                         CenterX=((this->width()*0.8)+x)/2;
                         CenterY=((this->height()/6)+y+20)/2;
                         this->ItemColor1(1,2);//对战框输出文字
                         //以下为重绘函数提供数据
                         player1[0][1]=CenterX;
                         player1[1][1]=CenterY;
                          chessboard[0][1]=2;
                          m[1]=0;
                         //重绘
                         update();
                         this->judge(diff);
                       }
                     }
                     //对纵坐标进行约束，第5格
                      else if(e->pos().y()>(this->height()-40)/3 & e->pos().y()<y+HEIGHT*2)
                      {
                       if(n[4]!=1){
                         CenterX=((this->width()*0.8)+x)/2;
                         CenterY=((this->height()*0.72)+y+20)/2;
                         this->ItemColor1(1,5);//对战框输出文字
                         //以下为重绘函数提供数据
                         player1[0][4]=CenterX;
                         player1[1][4]=CenterY;
                          chessboard[1][1]=2;
                          m[4]=0;
                         update();
                         this->judge(diff);
                      }
                     }
                     //对纵坐标进行约束，第8格
                       else if(e->pos().y()>y+HEIGHT*2 & e->pos().y()<y+HEIGHT*3)
                      {
                       if(n[7]!=1){
                         CenterX=((this->width()*0.8)+x)/2;
                         CenterY=((this->height()*1.25)+y+20)/2;
                         this->ItemColor1(1,8);
                         player1[0][7]=CenterX;
                         player1[1][7]=CenterY;
                          chessboard[2][1]=2;
                          m[7]=0;
                         update();
                         this->judge(diff);
                      }
                    }
                }
               //对横坐标进行约束，第3列
                if(e->pos().x()>x+WIDTH*2&e->pos().x()<x+WIDTH*3){
                    //对纵坐标进行约束，第3格
                      if(e->pos().y()>100&e->pos().y()<y+HEIGHT*1){
                       if(n[2]!=1){
                         CenterX=((this->width()*1.45)+x)/2;
                         CenterY=((this->height()/6)+y+20)/2;
                         this->ItemColor1(1,3);
                         player1[0][2]=CenterX;
                         player1[1][2]=CenterY;
                          chessboard[0][2]=2;
                          m[2]=0;
                         update();
                         this->judge(diff);
                      }
                     }
                     //对纵坐标进行约束，第6格
                      else if(e->pos().y()>(this->height()-40)/3 & e->pos().y()<y+HEIGHT*2)
                      {
                        if(n[5]!=1){
                         CenterX=((this->width()*1.45)+x)/2;
                         CenterY=((this->height()*0.72)+y+20)/2;
                         this->ItemColor1(1,6);
                         player1[0][5]=CenterX;
                         player1[1][5]=CenterY;
                         chessboard[1][2]=2;
                         m[5]=0;
                         update();
                         this->judge(diff);
                        }
                      }
                     //对纵坐标进行约束，第9格
                   else if(e->pos().y()>y+HEIGHT*2 & e->pos().y()<y+HEIGHT*3)
                      {
                       if(n[8]!=1){
                         CenterX=((this->width()*1.45)+x)/2;
                         CenterY=((this->height()*1.25)+y+20)/2;
                         this->ItemColor1(1,9);
                         player1[0][8]=CenterX;
                         player1[1][8]=CenterY;
                         chessboard[2][2]=2;
                         m[8]=0;
                         update();
                         this->judge(diff);
                      }
                    }
               }
             }
//            order=1;
        }
    }

    //函数最后返回原来的event函数，即返回父类的event
    return QWidget::event(ev);
}
int gameScence2::getdiff(){
    return diff;
}
