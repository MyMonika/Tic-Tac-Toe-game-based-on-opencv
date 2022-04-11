#include "gamescence.h"
#include "ui_gamescence.h"
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
#include<iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
using namespace std;

gameScence::gameScence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameScence)
{
    this->InitAll();
    step=0;//步数初始化0
	//设立窗口的一些信息
    ui->setupUi(this);
    this->Listarea();
    this->setMouseTracking(true);
    this->setFixedSize(800,600);
    this->setWindowIcon(QIcon(":/chess.png"));
    //设立窗口名
    this->setWindowTitle("game has started!");
    //写返回按钮
    back=new mypushbutton1;
    back->setParent(this);
    back->setFixedSize(60,30);
    back->setText("back");
    back->move(this->width()-back->width()-20,this->height()-back->height()-20);
    connect(back,&mypushbutton1::clicked,this,[=](){
        emit leaved();
    });
    cv::Point center(0,0);
    cv::Point center1(0, 0);
    cv::Scalar hsvWhiteLow(0, 0, 120);
    cv::Scalar hsvWhiteHigh(255, 255, 255);
    cv::Scalar hsvBlackLow(0, 0, 0);
    cv::Scalar hsvBlackHigh(255, 255, 50);
}
gameScence::~gameScence()
{
    delete ui;
}
//绘图函数，用来绘图
void gameScence:: paintEvent(QPaintEvent *){


    //实例化棋盘的画家
    QPainter painter(this);
    //实例化对战记录的画家
    //抗锯齿
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    //背景tiaose
    QPalette palette;
    palette.setColor(QPalette::Background,QColor("#B1723C"));
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    //画三连棋的线条
    QPen pen(Qt::black,4);//默认是solidline直线，后期可以改
    painter.setPen(pen);
    //画边界线
    QRect rect(x1,y1,this->width()-40,this->height()-120);
    WIDTH=rect.width()/3;
    HEIGHT=rect.height()/3;
    painter.drawRect(rect);
    //画横线
    for(int i=0;i<3;i++)
    {
        painter.drawLine(x1,y1+HEIGHT*i,this->width()-20,y1+HEIGHT*i);
    }
    //画竖线
    for(int i=0;i<3;i++)
    {
        painter.drawLine(x1+WIDTH*i,y1,x1+WIDTH*i,this->height()-20);
    }
    //为对战记录加边框
    QPen pen1(Qt::white,12);
    painter.setPen(pen1);//设置画笔w形式
    QRect rect1(x1,0,this->width()-40,90);
    painter.drawRect(rect1);

    //画棋子
    //1是黑棋，2是白棋
   for(int j=1;j<10;j++){
       if(flag[j]==1){
           QBrush brush2(Qt::black);
           painter.setPen(QPen(Qt::black,2));//设置画笔1形式
           painter.setBrush(brush2);//设置画刷1形式
           painter.drawEllipse(player1[0][j-1],player1[1][j-1],120,120);
       }
       if(flag[j]==2){
           QBrush brush1(Qt::white);
           painter.setPen(QPen(Qt::white,2));//设置画笔1形式
           painter.setBrush(brush1);//设置画刷1形式
           painter.drawEllipse(player1[0][j-1],player1[1][j-1],120,120);
       }
   }
}

//得到画棋的格子，row代表1~9格子，colomn代表颜色黑白
 void gameScence::paintCircle(int row,int colomn){

    switch (row){
    case 1: CenterX=((this->width()/6)+x1)/2;
            CenterY=((this->height()/6)+y1+20)/2;
            if(colomn==1){
                this->ItemColor1(0,row);
                flag[1]=1;
                player1[0][0]=CenterX;
                player1[1][0]=CenterY;
                update();
            }else if(colomn==2){
                this->ItemColor1(0,row);
                flag[1]=2;
                player1[0][0]=CenterX;
                player1[1][0]=CenterY;
                update();
            }
            break;
    case 2: CenterX=((this->width()*4/5)+x1)/2;
            CenterY=((this->height()/6)+y1+20)/2;
            if(colomn==1){
                this->ItemColor1(0,row);
                flag[2]=1;
                player1[0][1]=CenterX;
                player1[1][1]=CenterY;
                update();
            }else if(colomn==2){
                this->ItemColor1(0,row);
                flag[2]=2;
                player1[0][1]=CenterX;
                player1[1][1]=CenterY;
                update();
            }
            break;
    case 3: CenterX=((this->width()*1.45)+x1)/2;
            CenterY=((this->height()/6)+y1+20)/2;
            if(colomn==1){
                this->ItemColor1(0,row);
                flag[3]=1;
                player1[0][2]=CenterX;
                player1[1][2]=CenterY;
                update();
            }else if(colomn==2){
                this->ItemColor1(0,row);
                flag[4]=2;
                player1[0][2]=CenterX;
                player1[1][2]=CenterY;
                update();
            }
            break;
    case 4: CenterX=((this->width()/6)+x1)/2;
            CenterY=((this->height()*0.72)+y1+20)/2;
            if(colomn==1){
                this->ItemColor1(0,row);
                flag[4]=1;
                player1[0][3]=CenterX;
                player1[1][3]=CenterY;
                update();
            }else if(colomn==2){
                this->ItemColor1(0,row);
                flag[4]=2;
                player1[0][3]=CenterX;
                player1[1][3]=CenterY;
                update();
            }
            break;
    case 5: CenterX=((this->width()*0.8)+x1)/2;
            CenterY=((this->height()*0.72)+y1+20)/2;
            if(colomn==1){
                this->ItemColor1(0,row);
                flag[5]=1;
                player1[0][4]=CenterX;
                player1[1][4]=CenterY;
                update();
            }else if(colomn==2){
                this->ItemColor1(0,row);
                flag[5]=2;
                player1[0][4]=CenterX;
                player1[1][4]=CenterY;
                update();
            }
            break;
    case 6: CenterX=((this->width()*1.45)+x1)/2;
            CenterY=((this->height()*0.72)+y1+20)/2;
            if(colomn==1){
                this->ItemColor1(0,row);
                flag[6]=1;
                player1[0][5]=CenterX;
                player1[1][5]=CenterY;
                update();
            }else if(colomn==2){
                this->ItemColor1(0,row);
                flag[6]=2;
                player1[0][5]=CenterX;
                player1[1][5]=CenterY;
                update();
            }
            break;
    case 7: CenterX=((this->width()/6)+x1)/2;
            CenterY=((this->height()*1.25)+y1+20)/2;
            if(colomn==1){
                this->ItemColor1(0,row);
                flag[7]=1;
                player1[0][6]=CenterX;
                player1[1][6]=CenterY;
                update();
            }else if(colomn==2){
                this->ItemColor1(0,row);
                flag[7]=2;
                player1[0][6]=CenterX;
                player1[1][6]=CenterY;
                update();
            }
            break;
    case 8: CenterX=((this->width()*0.8)+x1)/2;
            CenterY=((this->height()*1.25)+y1+20)/2;
            if(colomn==1){
                this->ItemColor1(0,row);
                flag[8]=1;
                player1[0][7]=CenterX;
                player1[1][7]=CenterY;
                update();
            }else if(colomn==2){
                this->ItemColor1(0,row);
                flag[8]=2;
                player1[0][7]=CenterX;
                player1[1][7]=CenterY;
                update();
            }
            break;
    case 9: CenterX=((this->width()*1.45)+x1)/2;
            CenterY=((this->height()*1.25)+y1+20)/2;
            if(colomn==1){
                this->ItemColor1(0,row);
                flag[9]=1;
                player1[0][8]=CenterX;
                player1[1][8]=CenterY;
                update();
            }else if(colomn==2){
                this->ItemColor1(0,row);
                flag[9]=2;
                player1[0][8]=CenterX;
                player1[1][8]=CenterY;
                update();
            }
            break;
    }
 }
 //对战框框，对对战信息进行记录
void  gameScence::Listarea(){
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
    label->move(x1,0);
    label->setFixedSize(80,90);
    label->setText("Match record");
    //字体标签
//    Fontlabel=new QLabel();
//    Fontlabel->setPixmap(QPixmap(":/vo5eyRAGS3.jpg"));
}
//设立对战框的文字的显示
void gameScence:: ItemColor1(bool flag2, int row){
    if(flag2==0){
        //玩家1
        QListWidgetItem *item=new QListWidgetItem(QString("the first player actions in the %1 grid").arg(row));
       // item->setBackground(QColor(Qt::white));//改变背景颜色
        item->setTextAlignment(Qt::AlignHCenter);//文本放中间
        list->addItem(item);
        update();
    }
    if(flag2==1){
        //玩家2
        QListWidgetItem *item=new QListWidgetItem(QString("the second player actions in the %2 grid").arg(row));
       // item->setBackground(QColor(Qt::red));//改变背景颜色
        item->setTextAlignment(Qt::AlignHCenter);//文本放中间
        list->addItem(item);
        update();
        qDebug()<<"has drawn";
    }
}
//一把游戏结束后的询问框
void gameScence::Dialog(int i){
        msgBox.setWindowTitle("Result");/** 设置标题 **/
        if(i==1)
       { msgBox.setText("The player1 succeed!\n \n \n \n Do you want to play again with others?");}
        if(i==2)
       { msgBox.setText("The player1 succeed!\n \n \n \n Do you want to play again with others?");}
        if(i==0)
       { msgBox.setText("No one wins! it is draw\n \n \n \n Do you want to play again with others?");}
        if(i==5)
       { msgBox.setText("The camera doesn't detect the chess pieces for 20 seconds. \n \n \n \n Now it stops detection!\n\n\n"
                        "please close the camera");}
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
void gameScence::Dialog2(){
        warnning.setWindowTitle("Result");/** 设置标题 **/
        warnning.setText("If you want to close the photo page. Please press Q!");
        warnning.setIcon(QMessageBox::Warning);
        warnning.setDefaultButton(QMessageBox::Ok);
        int ret = warnning.exec();
}
//删除一切信息
void gameScence::deleteAllSlot()
{
    step=0;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            arr[i][j]=NULL;
        }
    }
    int counter =list->count();
    for(int index=0;index<counter;index++)
    {
        QListWidgetItem *item = list->takeItem(0);
            delete item;
    }
    this->InitAll();
    x=0; y=0; w=0; h = 0;
    update();
}
//检测行是否三联
bool gameScence::checkRow(int row, int player){

    for (int i = 0; i < 3; i++) {

        if (arr[row][i] != player) {

            return false;

        }

    }

    return true;
}
bool gameScence::checkCol(int col, int player) {

    for (int i = 0; i < 3; i++) {

        if (arr[i][col] != player) {

            return false;

        }

    }

    return true;

}


//检查左对角线是否三连
bool gameScence::line1(int player) {


    for (int i = 0; i < 3; i++) {

        if (arr[i][i] != player) {

            return false;

        }

    }

    return true;

}


//检查右对角线是否三连
bool gameScence::line2(int player) {


    for (int i = 0; i < 3; i++) {

        if (arr[i][3 - i - 1] != player) {

            return false;

        }

    }

    return true;

}


//将棋子落位的格子所代表的数赋值为该玩家的号（1和0）
//检测行列和对角线是否三连
//输出：1代表1获胜，2代表2获胜，0代表目前没有玩家胜出
int gameScence::move(int num, int player) {

   int row = (num - 1) / 3;
    int col = (num - 1) % 3;
    arr[row][col] = player;
    if (checkCol(col, player) || checkRow(row, player) || line1(player) || line2(player))
        return player;
    else if (isFull() == true)//表示下满
        return 0;
    else
        return 3;
}
void gameScence::InitAll(){
    CenterX=NULL;
    CenterY=NULL;
    for (int i=0;i<2;i++) {
        for (int j=0;j<9;j++) {
            player1[i][j]=100000;

        }
    }
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            arr[i][j]=2;
        }
    }
}







//这以后都是opencv的识别函数
int gameScence::detectGrid(cv::Mat img) {
    cv::Mat gray;
    vector<vector<Point> > contours;
    cv::Mat gray_blur;
    cv::Mat thresh;

    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);


    cv::GaussianBlur(gray, gray_blur, Point(15, 15), 0);


    cv::adaptiveThreshold(gray_blur, thresh, 255, 1, 1, 11, 2);

    cv::Canny(thresh, thresh, 100, 150, 5, true);

    cv::findContours(thresh, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    if (contours.size() != 0) {
        for (int i = 0; i < contours.size(); i++) {
            int max_area = 50000;
            int area = cv::contourArea(contours[i]);
            if (area > max_area) {
                max_area = area;
                int best_cnt = i;
                Rect rect;
                rect = cv::boundingRect(contours[i]);
                x = rect.x;
                y = rect.y;
                w = rect.width;
                h = rect.height;
                cv::rectangle(img, rect, cv::Scalar(0, 255, 0), 2);
                return x, y, w, h;

            }


        }
    }
    else return 0,0,0,0;
}
//检测结果并且以点的形式输出。第一个分量是位置：键盘九键；第二个是颜色：1黑2白。
//检测结果并且以点的形式输出。第一个分量是位置：键盘九键；第二个是颜色：1黑2白。
void gameScence::getResult(cv::Mat bgr_image) {


    //定义黑色白色检测上下限
    //根据光线可能需要调整。如果这里能设计一个GUI调整就太好了！可惜我不会！不知道希辰能不能帮上忙

    /*const Scalar hsvWhiteLow(0, 0, 120);
    const Scalar hsvWhiteHigh(255, 255, 255);
    const Scalar hsvBlackLow(0, 0, 0);
    const Scalar hsvBlackHigh(255, 255, 50);
    */

    //进行模糊化和hsv颜色转换

    cv::medianBlur(bgr_image, bgr_image, 3);
    cv::Mat hsv_image;
    cv::cvtColor(bgr_image, hsv_image, cv::COLOR_BGR2HSV);

    //建立白色蒙版
    cv::Mat white_hue_image;
    cv::inRange(hsv_image, hsvWhiteLow, hsvWhiteHigh, white_hue_image);
    cv::GaussianBlur(white_hue_image, white_hue_image, cv::Size(15, 15), 1, 1);


    //建立黑色蒙版
    cv::Mat black_hue_image;
    cv::inRange(hsv_image, hsvBlackLow, hsvBlackHigh, black_hue_image);
    cv::GaussianBlur(black_hue_image, black_hue_image, cv::Size(15, 15), 1, 1);

    cv::imshow("White", white_hue_image);
    cv::imshow("Black", black_hue_image);




    x, y, w, h = detectGrid(bgr_image);
    cv::cvtColor(bgr_image, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, gray_blur, Point(15, 15), 0);

    HoughCircles(gray_blur, circles, CV_HOUGH_GRADIENT, 1.5, 50, 100, params2, minR,maxR);
    if (!circles.empty()) {
        for (int i = 0; i < circles.size(); i++) {
            center = Point(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);


            if (white_hue_image.at<uchar>(Point(center.x, center.y)) == 255) {
                cv::circle(bgr_image, center, radius, cv::Scalar(0, 0, 255), 2);
                whitex = center.x;
                whitey = center.y;
                if ( x <= whitex && whitex <= x + w / 3 && y <= whitey && whitey <= y + h / 3) { r[0] = 2; detected[0] = 1; }
                if ( x + w / 3 <= whitex && whitex <= x + 2 * w / 3 && y <= whitey && whitey <= y + h / 3) { r[1] = 2; detected[1] = 1; }
                if ( x + 2 * w / 3 <= whitex && whitex <= x + w && y <= whitey && whitey <= y + h / 3) { r[2] = 2; detected[2] = 1; }
                if ( x <= whitex && whitex <= x + w / 3 && y + h / 3 <= whitey && whitey <= y + 2 * h / 3) { r[3] = 2; detected[3] = 1; }
                if (  x + w / 3 <= whitex && whitex <= x + 2 * w / 3 && y + h / 3 <= whitey && whitey <= y + 2 * h / 3) { r[4] = 2; detected[4] = 1; }
                if ( x + 2 * w / 3 <= whitex && whitex <= x + w && y + h / 3 <= whitey && whitey <= y + 2 * h / 3) { r[5] = 2; detected[5] = 1; }
                if ( x <= whitex && whitex <= x + w / 3 && y + 2 * h / 3 <= whitey && whitey <= y + h) { r[6] = 2; detected[6] = 1; }
                if ( x + w / 3 <= whitex && whitex <= x + 2 * w / 3 && y + h * 2 / 3 <= whitey && whitey <= y + h) { r[7] = 2; detected[7] = 1; }
                if ( x + 2 * w / 3 <= whitex && whitex <= x + w && y + 2 * h / 3 <= whitey && whitey <= y + h) { r[8] = 2; detected[8] = 1; }
                continue;

            }
            else {
                cv::circle(bgr_image, center, radius, cv::Scalar(255, 0, 0), 2);
                blackx = center.x;
                blacky = center.y;
                if ( x <= blackx && blackx <= x + w / 3 && y <= blacky && blacky <= y + h / 3) { r[0] = 1; detected[0] = 1; }
                if (x + w / 3 <= blackx && blackx <= x + 2 * w / 3 && y <= blacky && blacky <= y + h / 3) { r[1] = 1; detected[1] = 1; }
                if ( x + 2 * w / 3 <= blackx && blackx <= x + w && y <= blacky && blacky <= y + h / 3) { r[2] = 1; detected[2] = 1; }
                if (x <= blackx && blackx <= x + w / 3 && y + h / 3 <= blacky && blacky <= y + 2 * h / 3) { r[3] = 1; detected[3] = 1; }
                if ( x + w / 3 <= blackx && blackx <= x + 2 * w / 3 && y + h / 3 <= blacky && blacky <= y + 2 * h / 3) { r[4] = 1; detected[4] = 1; }
                if ( x + 2 * w / 3 <= blackx && blackx <= x + w && y + h / 3 <= blacky && blacky <= y + 2 * h / 3) { r[5] = 1; detected[5] = 1; }
                if ( x <= blackx && blackx <= x + w / 3 && y + 2 * h / 3 <= blacky && blacky <= y + h) { r[6] = 1; detected[6] = 1; }
                if (  x + w / 3 <= blackx && blackx <= x + 2 * w / 3 && y + h * 2 / 3 <= blacky && blacky <= y + h) { r[7] = 1; detected[7] = 1; }
                if ( x + 2 * w / 3 <= blackx && blackx <= x + w && y + 2 * h / 3 <= blacky && blacky <= y + h) { r[8] = 1; detected[8] = 1; }
                continue;
            }

        }
    }
}

Point gameScence:: show2() {
        for (int i = 0; i < 9; i++) {
            if (detected[i] == 1) {
                cout << i + 1 << r[i] << endl;
                continue;
                return Point(i + 1, r[i]);
            }
            else return Point(0, 0);
        }
    }


//这里是最主要的判断函数，两个部分的结合
void gameScence::judge2() {
    cv::VideoCapture cap(0);
    cv::Mat frame;
    Dialog2();
        while (1) {
            cap.read(frame);
            getResult(frame);
            this->show2();
            namedWindow("Parameters Fitting");
            int white_low_v = hsvWhiteLow[2];
            int black_high_v = hsvBlackHigh[2];
            cv::imshow("Parameters Fitting", frame);
            if(char(waitKey(1)) == 'q') {
                return;
            }
//以下是准备绘图
            for (int i=0;i<=8;i++) {
                iii=5;
                qDebug()<<"iii="<<iii;
                this->paintCircle(i+1, r[i]);//这一步代表绘图
                qDebug()<<"grid and color"<<i+1<<r[i];
                iii=this->move(i+1, r[i]);
                qDebug()<<"judge"<<iii;
            }
                if (iii == 1) {
                    this->Dialog(1);
                    return;
                }
                else if (iii == 2)
                {
                    this->Dialog(2);
                    return;
                }
//                else if (iii == 0)
//                {
//                    this->Dialog(0);
//                    return;
//                }
                else
                {
                 qDebug() << "继续游戏";
                }
                step++;
                cv::waitKey(1);
            }
}

void gameScence::changeW(int v, void* )
{
        hsvWhiteLow[2] = v;
}
void gameScence::changeB(int v, void*)
{
        hsvBlackHigh[2] = v;
}
void gameScence::changeparams2(int p, void*)
{
        params2 = p;
}
void gameScence::changeminR(int r, void*)
{
        minR = r;
}
void gameScence::changemaxR(int r, void*)
{
        maxR = r;
}
bool gameScence::isFull(){
    for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (arr[i][j] == 0)
                    return false;
        return true;
}
