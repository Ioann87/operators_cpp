#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student {
private:
    int age;
    char* name;
    char sex;
    double experience;
    double level;

public:
    Student() {};
    Student(int, char*, char);
    Student(const Student&);
    ~Student() { delete[] name; };
    void set_age(int);
    int get_age();
    void set_sex(char);
    char get_sex();
    void set_name(char*);
    char* get_name() const;
    void set_exp();
    double get_exp();
    void set_level(double);
    double get_level();

    static char* gen_name(size_t);
    static double calc_experience(int, char);
    static int gen_age();

    Student& operator=(const Student& pers);

    Student operator+(const Student&);
    Student operator-(const Student&);

    Student& operator++();
    Student operator++(int);

    Student& operator--();
    Student operator--(int);

    friend ostream& operator<<(ostream& out, const Student& pers);

    friend istream& operator>>(istream& in, Student& pers);
};

#endif // STUDENT_H
