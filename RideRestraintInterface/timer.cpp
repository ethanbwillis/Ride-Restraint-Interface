#include "timer.h"

Timer::Timer() {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    timer->setInterval(1000);
    timer->start();
}

void Timer::handleTimeout()
{
    //unused, for when timer runs out, maybe update later
}
