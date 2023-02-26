#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QPen>
#include <QDebug>
#include <QButtonGroup>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chartInit();
    serialInit();
    tablewidgetInit();

    ui->scrollArea->initialHandlerSize = []() -> QSize
    {
        return {15, 30};
    };
    ui->scrollArea->setOpenEasingCurve(QEasingCurve::Type::OutElastic);
    ui->scrollArea->setCloseEasingCurve(QEasingCurve::Type::InElastic);
    ui->scrollArea->init();

    QButtonGroup *pbtnGroup = new QButtonGroup(this);
    pbtnGroup->addButton(ui->btn1, 0);
    pbtnGroup->addButton(ui->btn2, 1);
    pbtnGroup->addButton(ui->btn3, 2);
    pbtnGroup->addButton(ui->btnSet, 3);
    connect(pbtnGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
            [=](int id)
            {
                ui->stackedWidget->setCurrentIndex(id);
            });
    ui->btn4->setEnabled(false);
    ui->btn5->setEnabled(false);
    ui->btn6->setEnabled(false);
    ui->btn7->setEnabled(false);
    ui->btn8->setEnabled(false);
    ui->btn9->setEnabled(false);

//    ui->btnWindow->setStyleSheet("QPushButton{border-image:url(:/imgs/off.png);}");

    pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, this, [=](){

        QDateTime curDateTime = QDateTime::currentDateTime();
        qint64 startTimeT = curDateTime.toSecsSinceEpoch() -55;
        qint64 endTimeT = curDateTime.toSecsSinceEpoch() + 5;
        QDateTime startDateTime = QDateTime::fromSecsSinceEpoch(startTimeT);
        QDateTime endDateTime = QDateTime::fromSecsSinceEpoch(endTimeT);
        m_AxisX->setRange(startDateTime, endDateTime);

        double temp = QRandomGenerator::global()->bounded(20,45) + QRandomGenerator::global()->bounded(0.5);
        pSplineSeriesTemp->append(curDateTime.toMSecsSinceEpoch(), temp);

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::chartInit()
{
    pChartTemp = new QChart;
    pSplineSeriesTemp = new QSplineSeries(this);
    pSplineSeriesTemp->setName("Temperature");

    QDateTime curDateTime = QDateTime::currentDateTime();
    qint64 startTimeT = curDateTime.toSecsSinceEpoch() -55;
    qint64 endTimeT = curDateTime.toSecsSinceEpoch() + 5;
    QDateTime startDateTime = QDateTime::fromSecsSinceEpoch(startTimeT);
    QDateTime endDateTime = QDateTime::fromSecsSinceEpoch(endTimeT);


    m_AxisX = new QDateTimeAxis(this);
    m_AxisX->setFormat("HH:mm:ss");
    m_AxisX->setTickCount(15);
    m_AxisX->setTitleText("t/s");
    m_AxisX->setRange(startDateTime, endDateTime);

    m_TempY = new QValueAxis(this);
    m_TempY->setRange(-10,50);
    m_TempY->setTickCount(15);
    m_TempY->setTitleText("℃");
    m_TempY->setLabelFormat("%4.2f");
    m_TempY->setLinePenColor(Qt::green);
    m_TempY->setTitleBrush(Qt::green);
    QPen pen(Qt::green, 1, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    pSplineSeriesTemp->setPen(pen);

    pChartTemp->setAnimationOptions(QChart::SeriesAnimations);
    pChartTemp->setTitle("Temperature");
    pChartTemp->setTheme(QChart::ChartTheme::ChartThemeDark);

    pChartTemp->addAxis(m_AxisX, Qt::AlignBottom);
    pChartTemp->addAxis(m_TempY, Qt::AlignLeft);
    pChartTemp->legend()->hide();

    pChartTemp->addSeries(pSplineSeriesTemp);

    pSplineSeriesTemp->attachAxis(m_AxisX);
    pSplineSeriesTemp->attachAxis(m_TempY);

    ui->chartTemp->setRenderHint(QPainter::Antialiasing);
    ui->chartTemp->setChart(pChartTemp);
}

void MainWindow::serialInit()
{
    pSerial = new QSerialPort(this);
    pSerial->setBaudRate(QSerialPort::Baud115200);
    pSerial->setDataBits(QSerialPort::Data8);
    pSerial->setStopBits(QSerialPort::OneStop);
    pSerial->setParity(QSerialPort::NoParity);
    pSerial->setFlowControl(QSerialPort::NoFlowControl);
    connect(pSerial, &QSerialPort::readyRead, this, &MainWindow::slotSerialReadyRead);

    ui->cBPort->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->cBPort->addItem(info.portName());
    }
}

void MainWindow::slotSerialReadyRead()
{

}

#include <QMessageBox>
void MainWindow::on_btnConnect_clicked()
{
    if(ui->btnConnect->text() == "连接")
    {
        if(ui->cBPort->currentText() == nullptr)
        {
            ui->cBPort->clear();
            foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            {
                ui->cBPort->addItem(info.portName());
            }
            return;
        }

        pSerial->setPortName(ui->cBPort->currentText());
        if(!pSerial->open(QIODevice::ReadWrite))
        {
            QMessageBox::warning(this, "警告", pSerial->errorString());
            return;
        }
        ui->btnConnect->setText("断开");
    }
    else
    {
        if(!pSerial->isOpen()) return;
        pSerial->close();
        ui->btnConnect->setText("连接");
    }
}

void MainWindow::on_btnWindow_clicked()
{

}

void MainWindow::on_btnWater_clicked()
{

}

void MainWindow::on_btnLed_clicked()
{

}

void MainWindow::on_btnBeep_clicked()
{
    pTimer->start(1000);
}


void MainWindow::tablewidgetInit()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(10);
    QHeaderView *headerViewLie = ui->tableWidget->verticalHeader();
    headerViewLie->setHidden(1); /* 不显示tableWidget自带序号 */
    QStringList headerHeng;
    headerHeng << QStringLiteral("教室")
               << QStringLiteral("通信地址")
               << QStringLiteral("通信通道")
               << QStringLiteral("温度值")
               << QStringLiteral("烟雾")
               << QStringLiteral("火焰")
               << QStringLiteral("报警")
               << QStringLiteral("人员");
    ui->tableWidget->setColumnCount(headerHeng.size());
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(headerHeng);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:lightgreen;}");
    ui->tableWidget->horizontalHeader()->setMinimumHeight(50);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    ui->tableWidget->verticalHeader()->setDefaultSectionSize(30);
    for (int i = 0; i < headerHeng.size(); i++)
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}
