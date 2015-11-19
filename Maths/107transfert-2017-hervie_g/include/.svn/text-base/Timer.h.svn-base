#ifndef TIMER_H_
#define TIMER_H_

#include <sys/time.h>
#include <stdlib.h>

class Timer
{
public:
    inline void start()
    {
        gettimeofday(&mStart, NULL);
    }

    inline void stop()
    {
        gettimeofday(&mEnd, NULL);
    }

    inline long diff()
    {
        long millis, seconds, useconds;

        seconds = mEnd.tv_sec - mStart.tv_sec;
        useconds = mEnd.tv_usec - mStart.tv_usec;

        millis = seconds * 1000 + (useconds / 1000);
        return millis;
    }

private:
    struct timeval mStart, mEnd;
};

#endif /* TIMER_H_ */
