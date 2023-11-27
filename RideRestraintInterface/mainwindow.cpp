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

    ui->trainNumber->setPlainText(QString::number(this->train));

    setStyleSheet("background-color: #3f48cc");

    ui->pushButton->setStyleSheet("background-color: white;");

    //HARD-CODED FILE PATHS, CHANGE
    unReadySeat.load("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/OpenRideSeat.png");
    red.load("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/Red.png");
    logo.load("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/Logo.jpg");
    green.load("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/Green.png");
    readySeat.load("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/GreenRideSeat.png");
    ipSeat.load("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/InProgressRideSeat.png");
    rideRestraintLogo.load("C:/Users/ebwil/OneDrive/Documents/TPED-23-24/RideRestraintSoftware/RideRestraintLogo.png");

    //setting images. setscaledcontents to crop automatically
    ui->seatImage->setPixmap(unReadySeat);
    ui->seatImage->setScaledContents(true);
    ui->seatImage->setStyleSheet("background-color: #3f48cc;");

    ui->info->setPixmap(logo);
    ui->info->setScaledContents(true);

    ui->logo->setPixmap(rideRestraintLogo);
    ui->logo->setScaledContents(true);

    //for text boxes-transparent background, white text
    ui->elapsedTime->setStyleSheet("color: white; background-color: transparent;");
    ui->timeMarker->setStyleSheet("color: white; background-color: transparent;");

    ui->trainMarker->setStyleSheet("color: white; background-color: transparent;");
    ui->trainNumber->setStyleSheet("color: white; background-color: transparent;");

    ui->backMarker->setStyleSheet("color: white; background-color: transparent;");
    ui->midMarker->setStyleSheet("color: white; background-color: transparent;");
    ui->frontMarker->setStyleSheet("color: white; background-color: transparent;");

    ui->overTimeLabel->setStyleSheet("color: white; background-color: transparent;");

    ui->backInfo->setPixmap(logo);
    ui->backInfo->setScaledContents(true);
    ui->middleInfo->setPixmap(logo);
    ui->middleInfo->setScaledContents(true);
    ui->frontInfo->setPixmap(logo);
    ui->frontInfo->setScaledContents(true);

    ui->backStatus->setPixmap(red);
    ui->backStatus->setScaledContents(true);
    ui->backStatus->setStyleSheet("background-color: transparent;");
    ui->frontStatus->setPixmap(red);
    ui->frontStatus->setScaledContents(true);
    ui->frontStatus->setStyleSheet("background-color: transparent");
    ui->midStatus->setPixmap(red);
    ui->midStatus->setScaledContents(true);
    ui->midStatus->setStyleSheet("background-color: transparent");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    //dispatch simulation. when clicked, reset current timer and change train number.
    this->incrementTrain();
    this->resetTimer();
}

void MainWindow::updateSeconds() {
    //continuously update seconds. kept track of using member variable elapsedSeconds
    this->elapsedSeconds++;
    ui->elapsedTime->setPlainText(QString::number(this->elapsedSeconds));
    if (this->elapsedSeconds > 10) {
        ui->overTimeLabel->setPlainText("(OVER)");
    }
}

void MainWindow::resetTimer() {
    //reset elapsed seconds. is called when dispatch is clicked
    this->elapsedSeconds = 0;
    ui->elapsedTime->setPlainText("0");
    ui->overTimeLabel->setPlainText("");
}

void MainWindow::incrementTrain() {
    //increments/updates current train. 4 for now. called when dispatch is clicked/
    if (this->train >= 4) {
        this->train = 1;
        ui->trainNumber->setPlainText(QString::number(this->train));
    } else {
        this->train++;
        ui->trainNumber->setPlainText(QString::number(this->train));
    }
}

