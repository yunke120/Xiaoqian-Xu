/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QChartView *chartTemp;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_3;
    GCLed *labelWindow;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    GCLed *labelWater;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_5;
    GCLed *labelLed;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_6;
    GCLed *labelBeep;
    QLabel *label_9;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout;
    QComboBox *cBPort;
    QPushButton *btnConnect;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPushButton *btnWindow;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QPushButton *btnWater;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QPushButton *btnLed;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QPushButton *btnBeep;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(966, 657);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        chartTemp = new QChartView(groupBox);
        chartTemp->setObjectName(QString::fromUtf8("chartTemp"));
        chartTemp->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(chartTemp, 0, 0, 1, 1);


        verticalLayout_7->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelWindow = new GCLed(groupBox_3);
        labelWindow->setObjectName(QString::fromUtf8("labelWindow"));

        verticalLayout_3->addWidget(labelWindow);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_7->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelWater = new GCLed(groupBox_3);
        labelWater->setObjectName(QString::fromUtf8("labelWater"));

        verticalLayout_4->addWidget(labelWater);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_7);

        verticalLayout_4->setStretch(0, 2);
        verticalLayout_4->setStretch(1, 1);

        horizontalLayout_7->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        labelLed = new GCLed(groupBox_3);
        labelLed->setObjectName(QString::fromUtf8("labelLed"));

        verticalLayout_5->addWidget(labelLed);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_8);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(1, 1);

        horizontalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        labelBeep = new GCLed(groupBox_3);
        labelBeep->setObjectName(QString::fromUtf8("labelBeep"));

        verticalLayout_6->addWidget(labelBeep);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_9);

        verticalLayout_6->setStretch(0, 2);
        verticalLayout_6->setStretch(1, 1);

        horizontalLayout_7->addLayout(verticalLayout_6);


        gridLayout->addLayout(horizontalLayout_7, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cBPort = new QComboBox(groupBox_2);
        cBPort->setObjectName(QString::fromUtf8("cBPort"));

        verticalLayout->addWidget(cBPort);

        btnConnect = new QPushButton(groupBox_2);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        verticalLayout->addWidget(btnConnect);


        horizontalLayout_9->addLayout(verticalLayout);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_9->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        btnWindow = new QPushButton(groupBox_2);
        btnWindow->setObjectName(QString::fromUtf8("btnWindow"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnWindow->sizePolicy().hasHeightForWidth());
        btnWindow->setSizePolicy(sizePolicy);
        btnWindow->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(btnWindow);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        horizontalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        btnWater = new QPushButton(groupBox_2);
        btnWater->setObjectName(QString::fromUtf8("btnWater"));
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
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_3);

        btnLed = new QPushButton(groupBox_2);
        btnLed->setObjectName(QString::fromUtf8("btnLed"));
        sizePolicy.setHeightForWidth(btnLed->sizePolicy().hasHeightForWidth());
        btnLed->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(btnLed);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        horizontalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_4);

        btnBeep = new QPushButton(groupBox_2);
        btnBeep->setObjectName(QString::fromUtf8("btnBeep"));
        sizePolicy.setHeightForWidth(btnBeep->sizePolicy().hasHeightForWidth());
        btnBeep->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(btnBeep);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        horizontalLayout_8->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_2);

        horizontalLayout_9->setStretch(0, 2);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 3);

        gridLayout_3->addLayout(horizontalLayout_9, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 3);

        verticalLayout_7->addLayout(horizontalLayout);

        verticalLayout_7->setStretch(0, 5);
        verticalLayout_7->setStretch(1, 1);

        gridLayout_2->addLayout(verticalLayout_7, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\270\251\346\271\277\345\272\246\346\230\276\347\244\272\345\214\272", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\230\276\347\244\272\345\214\272", nullptr));
        labelWindow->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\347\252\227\346\210\267", nullptr));
        labelWater->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\260\264\351\230\200", nullptr));
        labelLed->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\347\201\257\345\205\211", nullptr));
        labelBeep->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\345\214\272", nullptr));
        btnConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\252\227\346\210\267", nullptr));
        btnWindow->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\260\264\351\230\200", nullptr));
        btnWater->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\201\257\345\205\211", nullptr));
        btnLed->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246", nullptr));
        btnBeep->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
