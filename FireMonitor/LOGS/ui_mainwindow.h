/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QSidePanel/PanelLeftSide.hpp>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <gcled.h>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    PanelLeftSide *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *labelLogo;
    QPushButton *btn3;
    QPushButton *btn2;
    QPushButton *btn1;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btnSet;
    QLabel *label_3;
    QStackedWidget *stackedWidget;
    QWidget *page01;
    QWidget *page02;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_7;
    QChartView *chartTemp;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    GCLed *labelWater;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_3;
    GCLed *labelWater_2;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_5;
    GCLed *labelWater_3;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_6;
    GCLed *labelBeep;
    QLabel *label_9;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QPushButton *btnWater;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QPushButton *btnBeep;
    QWidget *page03;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_5;
    QTableWidget *tableWidget;
    QWidget *page04;
    QComboBox *cBPort;
    QPushButton *btnConnect;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(713, 496);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        scrollArea = new PanelLeftSide(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 104, 470));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        labelLogo = new QLabel(scrollAreaWidgetContents);
        labelLogo->setObjectName(QString::fromUtf8("labelLogo"));
        labelLogo->setStyleSheet(QString::fromUtf8("background-color: rgb(190, 84, 255);"));

        verticalLayout_8->addWidget(labelLogo);

        btn3 = new QPushButton(scrollAreaWidgetContents);
        btn3->setObjectName(QString::fromUtf8("btn3"));

        verticalLayout_8->addWidget(btn3);

        btn2 = new QPushButton(scrollAreaWidgetContents);
        btn2->setObjectName(QString::fromUtf8("btn2"));

        verticalLayout_8->addWidget(btn2);

        btn1 = new QPushButton(scrollAreaWidgetContents);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        btn1->setFont(font);

        verticalLayout_8->addWidget(btn1);

        btn4 = new QPushButton(scrollAreaWidgetContents);
        btn4->setObjectName(QString::fromUtf8("btn4"));

        verticalLayout_8->addWidget(btn4);

        btn5 = new QPushButton(scrollAreaWidgetContents);
        btn5->setObjectName(QString::fromUtf8("btn5"));

        verticalLayout_8->addWidget(btn5);

        btn6 = new QPushButton(scrollAreaWidgetContents);
        btn6->setObjectName(QString::fromUtf8("btn6"));

        verticalLayout_8->addWidget(btn6);

        btn7 = new QPushButton(scrollAreaWidgetContents);
        btn7->setObjectName(QString::fromUtf8("btn7"));

        verticalLayout_8->addWidget(btn7);

        btn8 = new QPushButton(scrollAreaWidgetContents);
        btn8->setObjectName(QString::fromUtf8("btn8"));

        verticalLayout_8->addWidget(btn8);

        btn9 = new QPushButton(scrollAreaWidgetContents);
        btn9->setObjectName(QString::fromUtf8("btn9"));

        verticalLayout_8->addWidget(btn9);

        btnSet = new QPushButton(scrollAreaWidgetContents);
        btnSet->setObjectName(QString::fromUtf8("btnSet"));

        verticalLayout_8->addWidget(btnSet);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_8->addWidget(label_3);


        gridLayout_3->addLayout(verticalLayout_8, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_5->addWidget(scrollArea);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page01 = new QWidget();
        page01->setObjectName(QString::fromUtf8("page01"));
        stackedWidget->addWidget(page01);
        page02 = new QWidget();
        page02->setObjectName(QString::fromUtf8("page02"));
        gridLayout = new QGridLayout(page02);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        chartTemp = new QChartView(page02);
        chartTemp->setObjectName(QString::fromUtf8("chartTemp"));
        chartTemp->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(chartTemp);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelWater = new GCLed(page02);
        labelWater->setObjectName(QString::fromUtf8("labelWater"));

        verticalLayout_4->addWidget(labelWater);

        label_7 = new QLabel(page02);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_7);

        verticalLayout_4->setStretch(0, 2);
        verticalLayout_4->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelWater_2 = new GCLed(page02);
        labelWater_2->setObjectName(QString::fromUtf8("labelWater_2"));

        verticalLayout_3->addWidget(labelWater_2);

        label_8 = new QLabel(page02);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_8);

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        labelWater_3 = new GCLed(page02);
        labelWater_3->setObjectName(QString::fromUtf8("labelWater_3"));

        verticalLayout_5->addWidget(labelWater_3);

        label_10 = new QLabel(page02);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_10);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        labelBeep = new GCLed(page02);
        labelBeep->setObjectName(QString::fromUtf8("labelBeep"));

        verticalLayout_6->addWidget(labelBeep);

        label_9 = new QLabel(page02);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_9);

        verticalLayout_6->setStretch(0, 2);
        verticalLayout_6->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_6);


        horizontalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(page02);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        btnWater = new QPushButton(page02);
        btnWater->setObjectName(QString::fromUtf8("btnWater"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnWater->sizePolicy().hasHeightForWidth());
        btnWater->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(btnWater);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        horizontalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(page02);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_4);

        btnBeep = new QPushButton(page02);
        btnBeep->setObjectName(QString::fromUtf8("btnBeep"));
        sizePolicy.setHeightForWidth(btnBeep->sizePolicy().hasHeightForWidth());
        btnBeep->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(btnBeep);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        horizontalLayout_8->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 4);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout_7->addLayout(horizontalLayout_3);

        verticalLayout_7->setStretch(0, 7);
        verticalLayout_7->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);

        stackedWidget->addWidget(page02);
        page03 = new QWidget();
        page03->setObjectName(QString::fromUtf8("page03"));
        gridLayout_4 = new QGridLayout(page03);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_5 = new QLabel(page03);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(13);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_5);

        tableWidget = new QTableWidget(page03);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_9->addWidget(tableWidget);

        verticalLayout_9->setStretch(0, 1);
        verticalLayout_9->setStretch(1, 8);

        gridLayout_4->addLayout(verticalLayout_9, 0, 0, 1, 1);

        stackedWidget->addWidget(page03);
        page04 = new QWidget();
        page04->setObjectName(QString::fromUtf8("page04"));
        cBPort = new QComboBox(page04);
        cBPort->setObjectName(QString::fromUtf8("cBPort"));
        cBPort->setGeometry(QRect(180, 210, 89, 23));
        btnConnect = new QPushButton(page04);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(280, 210, 89, 21));
        stackedWidget->addWidget(page04);

        horizontalLayout_5->addWidget(stackedWidget);

        horizontalLayout_5->setStretch(1, 10);

        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelLogo->setText(QString());
        btn3->setText(QCoreApplication::translate("MainWindow", "\346\200\273\350\247\210", nullptr));
        btn2->setText(QCoreApplication::translate("MainWindow", "\346\225\231\345\256\24402", nullptr));
        btn1->setText(QCoreApplication::translate("MainWindow", "\346\225\231\345\256\24403", nullptr));
        btn4->setText(QCoreApplication::translate("MainWindow", "\346\225\231\345\256\24404", nullptr));
        btn5->setText(QCoreApplication::translate("MainWindow", "\346\225\231\345\256\24405", nullptr));
        btn6->setText(QCoreApplication::translate("MainWindow", "\346\225\231\345\256\24406", nullptr));
        btn7->setText(QCoreApplication::translate("MainWindow", "\346\225\231\345\256\24407", nullptr));
        btn8->setText(QCoreApplication::translate("MainWindow", "\346\225\231\345\256\24408", nullptr));
        btn9->setText(QCoreApplication::translate("MainWindow", "\346\225\231\345\256\24409", nullptr));
        btnSet->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label_3->setText(QString());
        labelWater->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\260\264\351\230\200", nullptr));
        labelWater_2->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\347\203\237\351\233\276", nullptr));
        labelWater_3->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "\344\272\272\345\221\230", nullptr));
        labelBeep->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\260\264\351\230\200", nullptr));
        btnWater->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246", nullptr));
        btnBeep->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\231\272\346\205\247\346\225\231\345\256\244\347\201\253\346\203\205\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
        btnConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
