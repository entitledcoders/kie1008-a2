#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <ctime>

class timemanager
{
public:
    timemanager();
    void start();
    void pause();
    void resume();
    void stop();
    void reset();
    signed int getRealSeconds();
    signed int getGameDay();

private:
    bool run;
    int gameDayPerSec;
    time_t startSec;
    signed int realSeconds;
    signed int tempSeconds;
};

#endif // TIMEMANAGER_H
