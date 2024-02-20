#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "RideSeat.h"
#include <algorithm>
#include <stdlib.h>
#include <QMainWindow>
#include <QCoreApplication>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void updateSeconds();
    void resetTimer();
    void incrementTrain();

    void on_rmvTrainButton_clicked();

private:
    Ui::MainWindow *ui;
    bool ready = false;
    //member variables to keep track of timer and seconds. elapsedSeconds and train subject to change when backend added
    QTimer *timer;
    int elapsedSeconds = 0;
    int train = 1;
    int dispatches = 0;
    std::vector<RideSeat> seats;
    int averageTime;
    std::vector<int> times;
    int findIndex(int x);
    bool nextBlockReady;
    bool gateReady;
    bool isDispatched;
public:
    //pixmap/image objects to be updated on init
    QPixmap unReadySeat;
    QPixmap red;
    QPixmap logo;
    QPixmap green;
    QPixmap readySeat;
    QPixmap ipSeat;
    QPixmap ipSeatTwo;
    QPixmap rideRestraintLogo;
    QPixmap readyGate;
    QPixmap ipGate;
    QPixmap unReadyGate;
};
#endif // MAINWINDOW_H
