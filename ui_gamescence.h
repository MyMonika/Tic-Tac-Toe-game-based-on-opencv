/********************************************************************************
** Form generated from reading UI file 'gamescence.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCENCE_H
#define UI_GAMESCENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameScence
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gameScence)
    {
        if (gameScence->objectName().isEmpty())
            gameScence->setObjectName(QString::fromUtf8("gameScence"));
        gameScence->resize(800, 600);
        centralwidget = new QWidget(gameScence);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gameScence->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gameScence);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        gameScence->setMenuBar(menubar);
        statusbar = new QStatusBar(gameScence);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        gameScence->setStatusBar(statusbar);

        retranslateUi(gameScence);

        QMetaObject::connectSlotsByName(gameScence);
    } // setupUi

    void retranslateUi(QMainWindow *gameScence)
    {
        gameScence->setWindowTitle(QCoreApplication::translate("gameScence", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameScence: public Ui_gameScence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCENCE_H
