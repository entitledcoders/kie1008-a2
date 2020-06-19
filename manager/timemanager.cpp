#include "timemanager.hpp"

timemanager::timemanager()
{
    reset();
    gameDayPerSec = 5;
    run = false;
}

void timemanager::start()
{
    reset();
    startSec = time(0);
    run = true;
}

void timemanager::pause()
{
    if(run)
    {
        tempSeconds += difftime(time(0), startSec);
        run = false;
    }
}

void timemanager::resume()
{
    if(!run)
    {
        startSec = time(0);
        run = true;
    }
}

void timemanager::stop()
{
    run = false;
}

void timemanager::reset()
{
    startSec = 0;
    realSeconds = 0;
    tempSeconds = 0;
}

signed int timemanager::getRealSeconds()
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

signed int timemanager::getGameDay()
{
    return getRealSeconds()/gameDayPerSec;
}
