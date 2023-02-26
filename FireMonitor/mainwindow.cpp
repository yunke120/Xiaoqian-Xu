#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QPen>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chartInit();
    serialInit();


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
        temp = QRandomGenerator::global()->bounded(10,30) + QRandomGenerator::global()->bounded(0.5);
        pSplineSeriesHumi->append(curDateTime.toMSecsSinceEpoch(), temp);

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
    pSplineSeriesHumi = new QSplineSeries(this);
    pSplineSeriesTemp->setName("Temperature");
    pSplineSeriesHumi->setName("Humidity");

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

    m_HumiY = new QValueAxis(this);
    m_HumiY->setRange(0,100);
    m_HumiY->setTickCount(15);
    m_HumiY->setTitleText("RH");
    m_HumiY->setLabelFormat("%4.2f");
    m_HumiY->setLinePenColor(Qt::red);
    m_HumiY->setTitleBrush(Qt::red);
    QPen pen2(Qt::red, 1, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    pSplineSeriesTemp->setPen(pen2);

    pChartTemp->setAnimationOptions(QChart::SeriesAnimations);
    pChartTemp->setTitle("Temperature & Humidity");
    pChartTemp->setTheme(QChart::ChartTheme::ChartThemeDark);

    pChartTemp->addAxis(m_AxisX, Qt::AlignBottom);
    pChartTemp->addAxis(m_TempY, Qt::AlignLeft);
    pChartTemp->addAxis(m_HumiY, Qt::AlignRight);
    pChartTemp->legend()->hide();

    pChartTemp->addSeries(pSplineSeriesTemp);
    pChartTemp->addSeries(pSplineSeriesHumi);

    pSplineSeriesTemp->attachAxis(m_AxisX);
    pSplineSeriesTemp->attachAxis(m_TempY);

    pSplineSeriesHumi->attachAxis(m_AxisX);
    pSplineSeriesHumi->attachAxis(m_HumiY);

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
