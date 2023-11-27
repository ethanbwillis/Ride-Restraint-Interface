#ifndef RIDESEAT_H
#define RIDESEAT_H

#endif // RIDESEAT_H

class RideSeat {
    private:
        int elapsedtime = 0;
        int trainNumber = 0;
        bool ready = false;
        int lapBarStatus = 0; // 0 for up, 1 in progress, 2 for down

        //getters
        int getElapsedTime();
        int getTrainNumber();
        bool getReadyStatus();
        int getLapBarStatus();

        //setters
        void setReadyStatus(bool b);
        void setLapBarStatus(int status);

        void resetTime();
    public:
        RideSeat();
        RideSeat(int n);
};
