#ifndef GCLED_H
#define GCLED_H

#include <QObject>
#include <QLabel>


typedef enum{
    Open,
    Close
}eState;

class GCLed : public QLabel
{
    Q_OBJECT
public:
    GCLed(QWidget *parent = nullptr);

    void setState(eState state);

protected:

    void paintEvent(QPaintEvent *);

private:
    eState mState;
    QLinearGradient linearGradient;
};

#endif // GCLED_H
