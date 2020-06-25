#include "timemanager.hpp"

Time::timemanager()
{
    reset();
    run = false;
}

void Time::start()
{
    reset();
    startSec = time(0);
    run = true;
}

void Time::pause()
{
    if(run)
    {
        tempSeconds += difftime(time(0), startSec);
        run = false;
    }
}

void Time::resume()
{
    if(!run)
    {
        startSec = time(0);
        run = true;
    }
}

void Time::stop()
{
    run = false;
}

void Time::reset()
{
    startSec = 0;
    realSeconds = 0;
    tempSeconds = 0;
}

signed int Time::getRealSeconds()
{
    if(!run)
    {
        return tempSeconds;
    }
    else
    {
        realSeconds = difftime(time(0), startSec);
        return tempSeconds + realSeconds;
    }
}

signed int Time::getGameDay()
{
    return getRealSeconds()/3;
}

bool Time::isRun()
{
    return run;
}
