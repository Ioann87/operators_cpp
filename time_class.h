#pragma once
#include <iostream>

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time();
    Time(int h, int m, int s);
    Time(const Time& time);
    ~Time();
    void setter(int h, int m, int s);
    int get_h();
    int get_m();
    int get_s();

    Time operator+(const Time& time);
    Time operator-(const Time& time);
    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);

    friend ostream& operator<<(ostream& out, const Time& time);

    friend istream& operator>>(istream& in, Time& time);
};
