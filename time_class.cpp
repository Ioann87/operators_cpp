#include <time_class.h>

Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(const Time& time)
{
    hour = time.hour;
    minute = time.minute;
    second = time.second;
}

Time::Time(int h, int m, int s)
{
    setter(h, m, s);
}

Time::~Time() { }

void Time::setter(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
    return;
}

int Time::get_h()
{
    return hour;
}

int Time::get_m()
{
    return minute;
}

int Time::get_s()
{
    return second;
}

Time Time::operator+(const Time& time)
{
    Time temp;

    temp.hour = hour + time.hour;
    temp.minute = minute + time.minute;
    temp.second = second + time.second;

    return temp;
}

Time Time::operator-(const Time& time)
{
    Time temp;

    temp.hour = hour - time.hour;
    temp.minute = minute - time.minute;
    temp.second = second - time.second;

    return temp;
}

Time& Time::operator++()
{
    ++hour;
    ++minute;
    ++second;

    return *this;
}

Time Time::operator++(int)
{
    Time temp(hour, minute, second);

    hour++;
    minute++;
    second++;

    return temp;
}

Time& Time::operator--()
{

    --hour;
    --minute;
    --second;
    return *this;
}

Time Time::operator--(int)
{
    Time temp(hour, minute, second);
    hour--;
    minute--;
    second--;

    return temp;
}

ostream& operator<<(ostream& out, const Time& time)
{
    out << time.hour << ":";
    out << time.minute << ":";
    out << time.second << endl;

    return out;
}

istream& operator>>(istream& in, Time& time)
{
    in >> time.hour;
    in >> time.minute;
    in >> time.second;

    return in;
}
