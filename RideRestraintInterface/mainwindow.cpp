#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    RideSeat seat1(1);
    RideSeat seat2(2);
    RideSeat seat3(3);
    RideSeat seat4(4);

    seats.push_back(seat1); seats.push_back(seat2); seats.push_back(seat3); seats.push_back(seat4);
    ui->setupUi(this);
    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(updateSeconds()));
    this->timer->setInterval(1000);
    this->timer->start();

    ui->trainNumber->setPlainText(QString::number(this->train));

    setStyleSheet("background-color: #3f48cc");

    ui->pushButton->setStyleSheet("background-color: white;");

    unReadySeat.load("../OpenRideSeat.png");
    red.load("../Red.png");
    logo.load("../Logo.jpg");
    green.load("../Green.png");
    readySeat.load("../GreenRideSeat.png");
    ipSeat.load("../InProgressRideSeat.png");
    rideRestraintLogo.load("../RideRestraintLogo.png");

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
    ui->averageTime->setStyleSheet("color: white; background-color: transparent");

    ui->timeMarker_2->setStyleSheet("color: white; background-color: transparent");

    ui->pushButton_2->setStyleSheet("color: white");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    if (this->seats[this->train - 1].getReadyStatus() == 3) {
        //dispatch simulation. when clicked, reset current timer and change train number.
        this->seats[this->train - 1].setTime(this->elapsedSeconds);
        this->times.push_back(this->elapsedSeconds);
        int sum = 0;
        for (std::size_t i = 0; i < this->times.size(); i++) {
            sum += this->times[i];
        }
        this->dispatches++;
        this->averageTime = sum / dispatches;
        //display it
        ui->averageTime->setPlainText(QString::number(averageTime));
        this->incrementTrain();
        this->resetTimer();
        ui->seatImage->setPixmap(unReadySeat);
        ui->backStatus->setPixmap(red);
        ui->midStatus->setPixmap(red);
        ui->frontStatus->setPixmap(red);
    }

}

void MainWindow::updateSeconds() {
    //continuously update seconds. kept track of using member variable elapsedSeconds
    this->elapsedSeconds++;
    ui->elapsedTime->setPlainText(QString::number(this->elapsedSeconds));
    if (this->elapsedSeconds > 10) {
        this->seats[this->train - 1].setReadyStatus(true, 1);
        ui->backStatus->setPixmap(green);
        ui->seatImage->setPixmap(ipSeat);
    }
    if (this->elapsedSeconds > 15) {
        this->seats[this->train - 1].setReadyStatus(true, 2);
        ui->midStatus->setPixmap(green);
    }
    if (this->elapsedSeconds > 20) {
        this->seats[this->train - 1].setReadyStatus(true, 3);
        ui->frontStatus->setPixmap(green);
    }
    if (this->elapsedSeconds > 40) {
        ui->overTimeLabel->setPlainText("(OVER)");
    }
    if (this->seats[train - 1].getReadyStatus() == 3) {
        ui->seatImage->setPixmap(readySeat);
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
        this->seats[3].setReadyStatus(false, 1);
        this->seats[3].setReadyStatus(false, 1);
        this->seats[3].setReadyStatus(false, 1);
        ui->trainNumber->setPlainText(QString::number(this->train));
    } else {
        this->train++;
        this->seats[this->train - 2].setReadyStatus(false, 1);
        this->seats[this->train - 2].setReadyStatus(false, 1);
        this->seats[this->train - 2].setReadyStatus(false, 1);
        ui->trainNumber->setPlainText(QString::number(this->train));
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    auto text = ui->lineEdit->text();
    int num = 0;
    int previousSeat = this->train;

    if(text == "1") {
        this->train = 1;
        num = 1;
    }
    else if(text == "2") {
        this->train = 2;
        num = 2;
    }
    else if(text == "3") {
        this->train = 3;
        num = 3;
    }
    else if(text == "4") {
        this->train = 4;
        num = 4;
    }
    if (num == 0) {
        return;
    }
    if (this->seats[previousSeat - 1].getReadyStatus() != 3) {
        this->resetTimer();
        ui->trainNumber->setPlainText(QString::number(num));
        return;
    }
    this->seats[previousSeat - 1].setTime(elapsedSeconds);
    ui->trainNumber->setPlainText(QString::number(num));
    this->times.push_back(this->elapsedSeconds);
    this->resetTimer();
    int sum = 0;
    for (std::size_t i = 0; i < this->times.size(); i++) {
        sum += this->times[i];
    }
    this->dispatches++;
    this->averageTime = sum / dispatches;
    //display it
    ui->averageTime->setPlainText(QString::number(averageTime));
    this->resetTimer();
}

