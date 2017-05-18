#ifndef MYTIMER_H
#define MYTIMER_H

#include <ctime>
class MyTimer
{
   public:
        MyTimer();
        MyTimer(time_t s);
        void start();
        void setStart(time_t ts);
        time_t getStart();
        int getElapsedTime();
   private:
        time_t start_ts;
};

#endif // MYTIMER_H
