#include "timemanager.hpp"

Time::timemanager()
{
    reset();
    run = false;
}

void Time::start(unsigned int elapsed)
{
    reset();
    tempSeconds = elapsed;
    startSec = time(0);
    run = true;
}

void Time::pause()
{
    if(run)
    {
        tempSeconds += timeSpeed*difftime(time(0), startSec);
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
        return tempSeconds + timeSpeed*realSeconds;
    }
}

signed int Time::getGameDay()
{
    return getRealSeconds()/15;
}

bool Time::isRun()
{
    return run;
}
