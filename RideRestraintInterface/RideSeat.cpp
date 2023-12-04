#include "RideSeat.h"

RideSeat::RideSeat() {
    this->elapsedtime = 0;
    this->trainNumber = 1;
    this->backReady = false;
    this->midReady = false;
    this->frontReady = false;
    this->lapBarStatus = 0; // 0 for up, 1 in progress, 2 for down
}

RideSeat::RideSeat(int n) {
    this->elapsedtime = 0;
    this->trainNumber = n;
    this->backReady = false;
    this->midReady = false;
    this->frontReady = false;
    this->lapBarStatus = 0; // 0 for up, 1 in progress, 2 for down
}

int RideSeat::getElapsedTime() {
    return this->elapsedtime;
}

int RideSeat::getTrainNumber() {
    return this->trainNumber;
}

int RideSeat::getLapBarStatus() {
    return this->lapBarStatus;
}

void RideSeat::setReadyStatus(bool b, int x) {
    if (x == 1) {
        this->backReady = b;
        return;
    }
    if (x == 2) {
        this->midReady = b;
        return;
    }
    if (x == 3) {
        this->frontReady = b;
        return;
    }

    return;
}

void RideSeat::setLapBarStatus(int status) {
    this->lapBarStatus = status;
}

void RideSeat::resetTime() {
    this->elapsedtime = 0;
}

void RideSeat::setTime(int s) {
    this->elapsedtime = s;
}

int RideSeat::getReadyStatus() {
    std::vector<bool> val;
    if (this->backReady) {
        val.push_back(true);
    }
    if (this->midReady) {
        val.push_back(true);
    }
    if (this->frontReady) {
        val.push_back(true);
    }
    return val.size();
}
