#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
#include "time.h"

Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
}
Time::Time(int h, int m, int s)
{
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
void Time::PrintAMPM() const
{
    string ampm;
    int newHour;
    if (getHour() <= 12)
    {
        ampm = "am";
    }
    else if (getHour() >= 12)
    {
        ampm = "pm";
    }
    if (getHour() > 12)
    {
        newHour = getHour() - 12;
    }
    cout << newHour << ":" << getMinute() << ":" << getSecond() << ampm << endl;
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