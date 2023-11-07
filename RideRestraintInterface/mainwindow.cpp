#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(updateSeconds()));
    this->timer->setInterval(1000);
    this->timer->start();

    QPixmap seat("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/RideSeat.png");
    QPixmap red("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/Redsq.jpg");
    QPixmap green("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/Greensq.jpg");
    ui->label->setPixmap(seat);
    ui->backLabel->setPixmap(red);
    ui->midLabel->setPixmap(red);
    ui->frontLabel->setPixmap(red);
    ui->trainLabel->setText(QString::number(this->train));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QPixmap red("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/Redsq.jpg");
    QPixmap green("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/Greensq.jpg");
    if (this->ready == false) {
        this->ready = true;
        ui->backLabel->setPixmap(green);
        ui->midLabel->setPixmap(green);
        ui->frontLabel->setPixmap(green);
        //wait for dispatch
        //reset back to red, increment train counter
        //QTimer::singleShot(3000, this, SLOT(this->on_pushButton_clicked()));
        this->incrementTrain();
    } else {
        this->ready = false;
        ui->backLabel->setPixmap(red);
        ui->midLabel->setPixmap(red);
        ui->frontLabel->setPixmap(red);
    }
    this->resetTimer();
}

void MainWindow::updateSeconds() {
    this->elapsedSeconds++;
    ui->timerLbl->setText(QString::number(this->elapsedSeconds));
    if (this->elapsedSeconds > 60) {
        ui->overTimeLabel->setText("OVER");
    }
}

void MainWindow::resetTimer() {
    this->elapsedSeconds = 0;
    ui->timerLbl->setText("0");
    ui->overTimeLabel->setText("");
}

void MainWindow::incrementTrain() {
    if (this->train >= 4) {
        this->train = 1;
        ui->trainLabel->setText(QString::number(this->train));
    } else {
        this->train++;
        ui->trainLabel->setText(QString::number(this->train));
    }
}

