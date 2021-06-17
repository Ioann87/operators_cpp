#include <cstring>
#include <ctime>
#include <iostream>
#include <parallelepiped.h>
#include <student.h>
#include <time_class.h>
#include <vector>

using namespace std;

const char* sex_var = "mfcx";

int main()
{
    srand(time(NULL));
       Time start(rand() % 24, rand() % 60, rand() % 60);
       Time finish(rand() % 24, rand() % 60, rand() % 60);
       Time result;

       cout << start << endl;
       cout << finish << endl;

       cout << start << endl;
       cout << finish << endl;

       result = finish - start;
       cout << "res - : " << result;
       result = start + finish;
       cout << "res + : " << result;

       cout << result-- << endl;
       cout << --result << endl;
       cout << result++ << endl;
       cout << ++result << endl;

       Parallelepiped* figures = new Parallelepiped[13];

       for (int i = 0; i < 13; i++) {
           figures[i].set_sides(
               rand() % 100 * 0.1 + 0.1,
               rand() % 100 * 0.1 + 0.1,
               rand() % 100 * 0.1 + 0.1);
           cout << "Parallelipiped " << i + 1 << endl;
           cout << figures[i];
       }

       Parallelepiped sum;

       sum = figures[rand() % 13]
           + figures[rand() % 13]
           + figures[rand() % 13]
           + figures[rand() % 13]
           + figures[rand() % 13];
       cout << "sum of five random parallelepipeds: " << endl;
       cout << sum;

       delete[] figures;
    int size = rand() % 86 + 13;
    Student* persons = new Student[size];

    char* pers_name = nullptr;

    for (int i = 0; i < size; i++) {
        pers_name = Student::gen_name(5 + rand() % 13);
        persons[i].set_age(rand() % 25 + 18);
        persons[i].set_name(pers_name);
        persons[i].set_sex(sex_var[rand() % strlen(sex_var)]);
        persons[i].set_exp();
        persons[i].set_level(persons[i].get_exp());

        delete[] pers_name;

        cout << persons[i] << endl;
    }

    vector<Student> females;
    vector<Student> males;
    vector<Student> old;
    vector<Student> level;

    for (int i = 0; i < size; i++) {
        if (persons[i].get_sex() == 'f') {
            females.push_back(persons[i]);
        }
        if (17 <= persons[i].get_age() && persons[i].get_age() <= 59) {
            old.push_back(persons[i]);
        }
        if (persons[i].get_sex() == 'm') {
            males.push_back(persons[i]);
        }
        if (persons[i].get_level() >= 14) {
            level.push_back(persons[i]);
        }
    }

    cout << "Female: " << endl;
    for (size_t i = 0; i < females.size(); i++) {
        cout << females[i];
    }
    cout << endl;

    cout << "Male: " << endl;
    for (size_t i = 0; i < males.size(); i++) {
        cout << males[i];
    }
    cout << endl;

    cout << "17 - 59 years old: " << endl;
    for (size_t i = 0; i < old.size(); i++) {
        cout << old[i];
    }
    cout << endl;

    cout << "Level >= 14: " << endl;
    for (size_t i = 0; i < level.size(); i++) {
        cout << level[i];
    }
    cout << endl;

    cout << "plus" << endl;
    cout << males[1] + males[2];
    cout << "++M" << endl;
    ++males[1];
    cout << males[1];
    cout << "minus" << endl;
    cout << males[2] - males[3];
    cout << "--M" << endl;
    --males[2];
    cout << males[2];

    delete[] persons;

    system("pause");
    return 0;
}
