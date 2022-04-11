/********************************************************************************
** Form generated from reading UI file 'difficultty.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTTY_H
#define UI_DIFFICULTTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <mypushbutton1.h>

QT_BEGIN_NAMESPACE

class Ui_Difficultty
{
public:
    QWidget *centralwidget;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    mypushbutton1 *Normal;
    QSpacerItem *verticalSpacer_2;
    mypushbutton1 *Hard;
    mypushbutton1 *SoHard;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    mypushbutton1 *Easy;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *Difficultty)
    {
        if (Difficultty->objectName().isEmpty())
            Difficultty->setObjectName(QString::fromUtf8("Difficultty"));
        Difficultty->resize(800, 600);
        centralwidget = new QWidget(Difficultty);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(250, 140, 271, 281));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        Normal = new mypushbutton1(widget1);
        Normal->setObjectName(QString::fromUtf8("Normal"));

        gridLayout->addWidget(Normal, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        Hard = new mypushbutton1(widget1);
        Hard->setObjectName(QString::fromUtf8("Hard"));

        gridLayout->addWidget(Hard, 4, 1, 1, 1);

        SoHard = new mypushbutton1(widget1);
        SoHard->setObjectName(QString::fromUtf8("SoHard"));

        gridLayout->addWidget(SoHard, 6, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        Easy = new mypushbutton1(widget1);
        Easy->setObjectName(QString::fromUtf8("Easy"));

        gridLayout->addWidget(Easy, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        Difficultty->setCentralWidget(centralwidget);

        retranslateUi(Difficultty);

        QMetaObject::connectSlotsByName(Difficultty);
    } // setupUi

    void retranslateUi(QMainWindow *Difficultty)
    {
        Difficultty->setWindowTitle(QCoreApplication::translate("Difficultty", "MainWindow", nullptr));
        Normal->setText(QCoreApplication::translate("Difficultty", "Normal", nullptr));
        Hard->setText(QCoreApplication::translate("Difficultty", "Hard", nullptr));
        SoHard->setText(QCoreApplication::translate("Difficultty", "Very hard", nullptr));
        Easy->setText(QCoreApplication::translate("Difficultty", "Easy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Difficultty: public Ui_Difficultty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTTY_H
