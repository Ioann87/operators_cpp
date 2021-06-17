#include "parallelepiped.h"

Parallelepiped::Parallelepiped()
{
    a = 0.0;
    b = 0.0;
    c = 0.0;
    area = 0.0;
    volume = 0.0;
}

Parallelepiped::Parallelepiped(double a, double b, double c)
{
    set_sides(a, b, c);
    set_area(a, b, c);
    set_volume(a, b, c);
}

Parallelepiped::Parallelepiped(const Parallelepiped& figure)
{
    a = figure.a;
    b = figure.b;
    c = figure.c;
    area = figure.area;
    volume = figure.volume;
}

Parallelepiped::~Parallelepiped() {};

void Parallelepiped::set_sides(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    set_area(a, b, c);
    set_volume(a, b, c);
    return;
}
void Parallelepiped::set_area(double, double, double)
{
    area = calc_area(a, b, c);
    return;
}
void Parallelepiped::set_volume(double, double, double)
{
    volume = calc_volume(a, b, c);
    return;
}

double Parallelepiped::calc_area(double a, double b, double c)
{
    double area = 0.0;
    area = 2 * (a * b + b * c + c * a);
    return area;
}

double Parallelepiped::calc_volume(double a, double b, double c)
{
    double volume = 0.0;
    volume = a * b * c;
    return volume;
}

double Parallelepiped::get_a()
{
    return a;
}
double Parallelepiped::get_b()
{
    return b;
}
double Parallelepiped::get_c()
{
    return c;
}
double Parallelepiped::get_area()
{
    return area;
}
double Parallelepiped::get_volume()
{
    return volume;
}

Parallelepiped Parallelepiped::operator+(const Parallelepiped& figure)
{
    Parallelepiped temp;
    temp.a = a + figure.a;
    temp.b = b + figure.b;
    temp.c = c + figure.c;
    temp.area = calc_area(temp.a, temp.b, temp.c);
    temp.volume = calc_volume(temp.a, temp.b, temp.c);
    return temp;
}

Parallelepiped Parallelepiped::operator-(const Parallelepiped& figure)
{
    Parallelepiped temp;
    temp.a = a - figure.a;
    temp.b = b - figure.b;
    temp.c = c - figure.c;
    temp.area = calc_area(temp.a, temp.b, temp.c);
    temp.volume = calc_volume(temp.a, temp.b, temp.c);
    return temp;
}
Parallelepiped& Parallelepiped::operator++()
{

    ++a;
    ++b;
    ++c;
    area = calc_area(a, b, c);
    volume = calc_volume(a, b, c);
    return *this;
}
Parallelepiped Parallelepiped::operator++(int)
{
    Parallelepiped temp(a, b, c);
    a++;
    b++;
    c++;
    area = calc_area(a, b, c);
    volume = calc_volume(a, b, c);
    return temp;
}
Parallelepiped& Parallelepiped::operator--()
{

    --a;
    --b;
    --c;
    area = calc_area(a, b, c);
    volume = calc_volume(a, b, c);
    return *this;
}
Parallelepiped Parallelepiped::operator--(int)
{
    Parallelepiped temp(a, b, c);
    a--;
    b--;
    c--;
    area = calc_area(a, b, c);
    volume = calc_volume(a, b, c);
    return temp;
}

Parallelepiped Parallelepiped::operator=(const Parallelepiped& figure)
{
    a = figure.a;
    b = figure.b;
    c = figure.c;
    area = calc_area(a, b, c);
    volume = calc_volume(a, b, c);
    return *this;
}

ostream& operator<<(ostream& out, const Parallelepiped& figure)
{
    out << "a: " << figure.a << endl;
    out << "b: " << figure.b << endl;
    out << "c: " << figure.c << endl;
    out << "area: " << figure.area << endl;
    out << "volume: " << figure.volume << endl;
    return out;
}

istream& operator>>(istream& in, Parallelepiped& figure)
{
    cout << "a: ";
    in >> figure.a;
    cout << "b: ";
    in >> figure.b;
    cout << "c: ";
    in >> figure.c;
    return in;
}
