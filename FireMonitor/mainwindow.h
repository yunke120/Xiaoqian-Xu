#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QChart>
#include <QSplineSeries>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QTimer>
#include <QDate>
#include <QTime>

QT_CHARTS_USE_NAMESPACE


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void chartInit(void);
    void serialInit(void);
    void tablewidgetInit(void);
private slots:
    void slotSerialReadyRead(void);

    void on_btnConnect_clicked();

    void on_btnWindow_clicked();

    void on_btnWater_clicked();

    void on_btnLed_clicked();

    void on_btnBeep_clicked();

private:
    Ui::MainWindow *ui;

    QChart *pChartTemp;
    QSplineSeries *pSplineSeriesTemp;
    QSplineSeries *pSplineSeriesHumi;

    QValueAxis *m_TempY;
    QValueAxis *m_HumiY;
    QDateTimeAxis *m_AxisX;

    QTimer *pTimer;

    QSerialPort *pSerial;
};

#endif // MAINWINDOW_H
