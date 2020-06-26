#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <ctime>

class Time
{
public:
    timemanager();
    void start(unsigned int);
    void pause();
    void resume();
    void stop();
    void reset();
    bool isRun();
    signed int getRealSeconds();
    signed int getGameDay();

    int timeSpeed;


private:
    bool run;
    time_t startSec;
    signed int realSeconds;
    signed int tempSeconds;
};

#endif // TIMEMANAGER_H
