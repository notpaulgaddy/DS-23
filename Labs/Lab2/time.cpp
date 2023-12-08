#include <iostream>
#include "time.h"

Time::Time()
// set all to 0
{
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(int h, int m, int s)
{ // 2nd class constructor
    hour = h;
    minute = m;
    second = s;
}

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

int Time::getSecond() const
{
    return second;
}

void Time::PrintAmPm() const
{
    std::string ampm;
    if (getHour() >= 12)
    {
        ampm = " pm"; // pm determiner
    }
    else
    {
        ampm = " am"; // am determiner
    }

    if (getHour() == 0 || getHour() == 12) // if its 0 or 12, set to 0
    {
        std::cout << 12 << ":";
    }
    else // otherwise, find the remainder when divided by 12
    {
        std::cout << getHour() % 12 << ":";
    }

    if (getMinute() < 10) // add a 0 if its less than 0
    {
        std::cout << "0";
    }
    std::cout << getMinute() << ":";
    if (getSecond() < 10) // same thing for seconds
    {
        std::cout << "0";
    }
    std::cout << getSecond() << ampm << std::endl; // print it all out
}

void Time::setHour(int h)
{
    hour = h;
}

void Time::setMinute(int m)
{
    minute = m;
}

void Time::setSecond(int s)
{
    second = s;
}

bool isEarlierThan(const Time &t1, const Time &t2)
{
    if (t1.getHour() < t2.getHour())
    {
        return true;
    }
    else if (t1.getHour() > t2.getHour())
    {
        return false;
    }

    if (t1.getMinute() < t2.getMinute())
    {
        return true;
    }
    else if (t1.getMinute() > t2.getMinute())
    {
        return false;
    }

    if (t1.getSecond() < t2.getSecond()) // second comparison
    {
        return true;
    }

    return false;
}