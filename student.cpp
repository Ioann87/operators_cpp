#include "student.h"
#include <cstring>

Student::Student(int age, char* name, char sex)
{
    set_age(age);
    set_name(name);
    set_sex(sex);
    set_exp();
    set_level(experience);
}
Student::Student(const Student& copy_p)
{
    set_age(copy_p.age);
    set_name(copy_p.name);
    set_sex(copy_p.sex);
    set_exp();
    set_level(copy_p.experience);
}

void Student::set_age(int age)
{
    if (age >= 0)
        this->age = age;
    else
        this->age = -age;
    return;
}

int Student::get_age()
{
    return age;
}
int Student::gen_age()
{
    return (rand() % 70 + 10);
}

void Student::set_sex(char sex)
{

    this->sex = sex;

    return;
}
char Student::get_sex()
{
    return sex;
}

void Student::set_name(char* name)
{
    if (name != nullptr) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    return;
}

void Student::set_exp()
{
    experience = calc_experience(age, sex);
    return;
}

double Student::get_exp()
{
    return experience;
}

double Student::calc_experience(int age, char sex)
{
    double exp = 0.0;

    if (sex == 'm')
        exp = age * 3.14 * 1.3;
    else if (sex == 'f')
        exp = age * 3.14 * 1.3;
    else if (sex == 'c')
        exp = age * 3.14 * 2.57;
    else if (sex == 'x')
        exp = age * 3.14 * 0.01;
    return exp;
}

void Student::set_level(double experience)
{
    level = experience / 13;
}
double Student::get_level()
{
    return level;
}

char* Student::gen_name(size_t length)
{
    char* name = new char[length];
    for (size_t i = 0; i < length - 1; i++) {
        name[i] = 'a' + rand() % ('z' - 'a' + 1);
    }

    *name -= 32;
    name[length - 1] = '\0';

    return name;
}

char* Student::get_name() const
{
    char* copy_name = new char[strlen(this->name) + 1];
    strcpy(copy_name, this->name);
    return copy_name;
}

Student& Student::operator=(const Student& pers)
{
    this->set_age(pers.age);
    this->set_name(pers.name);
    this->set_sex(pers.sex);
    this->set_exp();
    this->set_level(pers.experience);

    return *this;
}

Student Student::operator+(const Student& pers)
{
    Student temp;
    temp.name = name;
    temp.sex = sex;
    temp.age = age + pers.age;
    temp.experience = experience + pers.experience;
    temp.level = temp.experience / 13;
    return temp;
}

Student Student::operator-(const Student& pers)
{
    Student temp;
    temp.name = name;
    temp.sex = sex;
    temp.age = age - pers.age;
    temp.experience = experience - pers.experience;
    temp.level = temp.experience / 13;
    return temp;
}
Student& Student::operator++()
{

    ++age;
    ++experience;

    level = experience / 13;
    return *this;
}
Student Student::operator++(int)
{
    Student temp(age, name, sex);

    age++;
    experience++;

    level = experience / 13;
    return temp;
}
Student& Student::operator--()
{
    --age;
    --experience;

    level = experience / 13;
    return *this;
}
Student Student::operator--(int)
{
    Student temp(age, name, sex);
    age--;
    experience--;

    level = experience / 13;
    return temp;
}

ostream& operator<<(ostream& out, const Student& pers)
{
    out << "Name: " << (pers.name != nullptr ? pers.name : "None") << endl;
    out << "Age: " << pers.age << endl;
    out << "Sex: " << pers.sex << endl;
    out << "Experience: " << pers.experience << endl;
    out << "Level: " << pers.level << endl;

    return out;
}

istream& operator>>(istream& in, Student& pers)
{
    pers.name = new char[80];
    in.getline(pers.name, 80);

    in >> pers.age;

    in >> (pers.sex);

    in.ignore();

    return in;
}
