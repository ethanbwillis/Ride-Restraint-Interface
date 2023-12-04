#ifndef RIDESEAT_H
#define RIDESEAT_H
#include <vector>

#endif // RIDESEAT_H

class RideSeat {
    private:
        int elapsedtime = 0;
        int trainNumber = 0;
        bool backReady = false;
        bool midReady = false;
        bool frontReady = false;
        int lapBarStatus = 0; // 0 for up, 1 in progress, 2 for down
        int avgTime;
    public:
        RideSeat();
        RideSeat(int n);

        //getters
        int getElapsedTime();
        int getTrainNumber();
        int getReadyStatus();
        int getLapBarStatus();
        int getAvgTime();

        //setters
        void setReadyStatus(bool b, int x);
        void setLapBarStatus(int status);
        void setTime(int s);
        void setAvgTime();

        void resetTime();
};
