/********************************************************************************
** Form generated from reading UI file 'gamescence2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCENCE2_H
#define UI_GAMESCENCE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameScence2
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gameScence2)
    {
        if (gameScence2->objectName().isEmpty())
            gameScence2->setObjectName(QString::fromUtf8("gameScence2"));
        gameScence2->resize(800, 600);
        centralwidget = new QWidget(gameScence2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gameScence2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gameScence2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        gameScence2->setMenuBar(menubar);
        statusbar = new QStatusBar(gameScence2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        gameScence2->setStatusBar(statusbar);

        retranslateUi(gameScence2);

        QMetaObject::connectSlotsByName(gameScence2);
    } // setupUi

    void retranslateUi(QMainWindow *gameScence2)
    {
        gameScence2->setWindowTitle(QCoreApplication::translate("gameScence2", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameScence2: public Ui_gameScence2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCENCE2_H
