class Time
{

public:
    Time();
    Time(int h, int m, int s);
    // accessors
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void PrintAMPM() const;

    // modifiers
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

private:
    int hour;
    int minute;
    int second;
};

bool isEarlierThan(const Time &t1, const Time &t2);