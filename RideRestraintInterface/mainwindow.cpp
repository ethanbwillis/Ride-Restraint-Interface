#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QTimer>
#include <QDateTime>
#include <iostream>

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

    ui->totalTrainsMarker->setStyleSheet("color: white; background-color: transparent;");
    ui->totalTrains->setStyleSheet("color: white; background-color: transparent;");
    ui->totalTrains->setPlainText(QString::number(seats.size()));

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

    ui->rmvTrainButton->setStyleSheet("color: white");
    ui->addTrainButton->setStyleSheet("color: white");


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
    if (this->elapsedSeconds > 1) {
        this->seats[this->train - 1].setReadyStatus(true, 1);
        ui->backStatus->setPixmap(green);
        ui->seatImage->setPixmap(ipSeat);
    }
    if (this->elapsedSeconds > 2) {
        this->seats[this->train - 1].setReadyStatus(true, 2);
        ui->midStatus->setPixmap(green);
    }
    if (this->elapsedSeconds > 3) {
        this->seats[this->train - 1].setReadyStatus(true, 3);
        ui->frontStatus->setPixmap(green);
    }
    if (this->elapsedSeconds > 4) {
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
    for (size_t i = 0; i < seats.size(); i++) {
        trainNumbers.push_back(seats[i].getTrainNumber());
    }
    auto it = std::find(trainNumbers.begin(), trainNumbers.end(), this->train);
    if (it == trainNumbers.end() || std::next(it) == trainNumbers.end()){
        this->train = trainNumbers.front();
        this->seats[findIndex(this->train)].setReadyStatus(false, 1);
        this->seats[findIndex(this->train)].setReadyStatus(false, 2);
        this->seats[findIndex(this->train)].setReadyStatus(false, 3);
        ui->trainNumber->setPlainText(QString::number(this->train));
        return;
    }

    for (int num : trainNumbers) {
        if (num > this->train) {
            // Found the next available number
            this->train = num;
            this->seats[findIndex(this->train)].setReadyStatus(false, 1);
            this->seats[findIndex(this->train)].setReadyStatus(false, 2);
            this->seats[findIndex(this->train)].setReadyStatus(false, 3);

            //visual change
            ui->trainNumber->setPlainText(QString::number(this->train));
            return;
        }
    }

    // If no next available number is found, return the first element
    this->train = trainNumbers.front();
    this->seats[findIndex(this->train)].setReadyStatus(false, 1);
    this->seats[findIndex(this->train)].setReadyStatus(false, 2);
    this->seats[findIndex(this->train)].setReadyStatus(false, 3);
    ui->trainNumber->setPlainText(QString::number(this->train));
    return;
}

int MainWindow::findIndex(int x) {
    for (size_t i = 0; i < this->seats.size(); i++) {
        if (this->seats[i].getTrainNumber() == x) {
            return i;
        }
    }
    return -1;
}

void MainWindow::on_rmvTrainButton_clicked() {
    //make sure all of the seats aren't deleted
    if (trainNumbers.size() <= 1) {
        return;
    }

    //removing the seat from the vector
    int previousSeat = this->train;
    this->incrementTrain();
    trainNumbers.erase(trainNumbers.begin() + findIndex(previousSeat));
    this->resetTimer();

    //visual changes
    ui->seatImage->setPixmap(unReadySeat);
    ui->backStatus->setPixmap(red);
    ui->midStatus->setPixmap(red);
    ui->frontStatus->setPixmap(red);
    ui->trainNumber->setPlainText(QString::number(this->train));
    ui->totalTrains->setPlainText(QString::number(trainNumbers.size()));
}

void MainWindow::on_addTrainButton_clicked() {
    //make sure we don't add too many seats
    if (this->seats.size() > 4) {
        return;
    }

    //add a new seat onto the end of the vector
    RideSeat newSeat(seats.size());
    this->seats.push_back(newSeat);

    //visual changes
    this->resetTimer();
    ui->seatImage->setPixmap(unReadySeat);
    ui->backStatus->setPixmap(red);
    ui->midStatus->setPixmap(red);
    ui->frontStatus->setPixmap(red);
    ui->trainNumber->setPlainText(QString::number(this->train));
    ui->totalTrains->setPlainText(QString::number(seats.size()));
}

void MainWindow::on_resetButton_clicked() {
    //reset time data
    this->times.clear();
    this->averageTime = 0;
    this->resetTimer();

    //reset number of dispatch data
    this->dispatches = 0;

    //reset seats vector
    seats.clear();
    RideSeat seat1(1);
    RideSeat seat2(2);
    RideSeat seat3(3);
    RideSeat seat4(4);
    seats.push_back(seat1); seats.push_back(seat2); seats.push_back(seat3); seats.push_back(seat4);

    for(RideSeat seat: seats) {
        std::cout << seat.getTrainNumber() << " ";
    }
    std::cout << std::endl;

    //reset trainNumbers vector
    trainNumbers.clear();
    for (size_t i = 0; i < seats.size(); i++) {
        trainNumbers.push_back(seats[i].getTrainNumber());
    }
    this->train = 1;

    for(int trainNumber: trainNumbers) {
        std::cout << trainNumber << " ";
    }
    std::cout << std::endl;

    //visual changes
    ui->trainNumber->setPlainText(QString::number(this->train));
    ui->seatImage->setPixmap(unReadySeat);
    ui->backStatus->setPixmap(red);
    ui->midStatus->setPixmap(red);
    ui->frontStatus->setPixmap(red);
}

