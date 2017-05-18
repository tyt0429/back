#include "mytimer.h"
MyTimer::MyTimer()
    {
        start_ts=0;
    }
MyTimer::MyTimer(time_t s)
    {
        setStart(s);
    }
void MyTimer::start()
    {
        start_ts = time(NULL);
    }
void MyTimer::setStart(time_t ts)
    {
        start_ts = ts;
    }
time_t MyTimer::getStart()
    {
        return start_ts;
    }
int MyTimer::getElapsedTime()
    {
        return time(NULL)-getStart();
    }
