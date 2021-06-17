#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include <iostream>
using namespace std;

class Parallelepiped {
private:
    double a;
    double b;
    double c;
    double area;
    double volume;

public:
    Parallelepiped();
    Parallelepiped(double, double, double);
    Parallelepiped(const Parallelepiped&);
    ~Parallelepiped();

    void set_sides(double, double, double);
    void set_area(double, double, double);
    void set_volume(double, double, double);

    double get_a();
    double get_b();
    double get_c();
    double get_area();
    double get_volume();

    static double calc_area(double a, double b, double c);
    static double calc_volume(double a, double b, double c);

    Parallelepiped operator+(const Parallelepiped&);
    Parallelepiped operator-(const Parallelepiped&);

    Parallelepiped& operator++();
    Parallelepiped operator++(int);

    Parallelepiped& operator--();
    Parallelepiped operator--(int);

    Parallelepiped operator=(const Parallelepiped&);

    friend ostream& operator<<(ostream& out, const Parallelepiped&);

    friend istream& operator>>(istream& in, Parallelepiped&);
};

#endif // PARALLELEPIPED_H
