#include <iostream>
#include <string>
#define DEBUG 0
#define N 100
using namespace std;


class Human {

protected:

    string name;
    string sex;
    int age;

public:

    Human(string name, string sex, int age) : name(name), sex(sex), age(age) {
        if (DEBUG) cout << "Create Human " + name << endl;
    }

    virtual ~Human() {
        if (DEBUG) cout << "Delete Human " + name << endl;
    }

    virtual void print() {
        cout << name << ' ' << age << ' ' << sex;
    }

    void hello() {
        print();
        cout << endl;
    }

};


class Student : virtual public Human {

protected:

    int course;
    string group;
    string univ;

public:

    Student(string name, string sex, int age, int course = 1, string group = "stat1", string univ = "NUK") :
        Human(name, sex, age), course(course), group(group), univ(univ) {

        if (DEBUG) cout << "Create Student " + name << endl;
    }

    virtual ~Student() {
        if (DEBUG) cout << "Delete Student " + name << endl;
    }

    virtual void print() {
        Human::print();
        cout << ' ' << univ << ' ' << course << ' ' << group;
    }
};


class Teacher : virtual public Human {

protected:

    string position;
    double salary;
    string univ;

public:

    Teacher(string name, string sex, int age, string position = "Programming Teacher", double salary = 11.1, string univ = "KNUBA") :
        Human(name, sex, age), position(position), salary(salary), univ(univ) {

        if (DEBUG) cout << "Create Teacher " + name << endl;
    }

    virtual ~Teacher() {
        if (DEBUG) cout << "Delete Teacher " + name << endl;
    }

    virtual void print() {
        Human::print();
        cout << ' ' << univ << ' ' << salary << ' ' << position;
    }
};


class PGS : public Student, public Teacher { //, public Teacher

public:

    PGS(string name, string sex, int age, int course = 2, string group = "stat1", string position = "Teacher", double salary = 9.5, string univ = "KPI") : //string position = "Teacher", double salary = 9.5, 
        Human(name, sex, age), Student(name, sex, age, course, group, univ), Teacher(name, sex, age, position, salary, univ) { //, Teacher(name, sex, age, position, salary, univ)

        if (DEBUG) cout << "Create PGS " + Student::name << endl;
    }

    virtual ~PGS() {
        if (DEBUG) cout << "Delete PGS " + Student::name << endl;
    }

    virtual void print() {
        Student::print();
        //cout << ' ' << salary;
    }
};



int main() {
    int n = 4;
    Human* arr[N] = {
        new Human("Alex the Human", "M", 50),
        new Student("Masha the Student", "W", 18),
        new Teacher("Gosha the Teacher", "M", 26),
        new PGS("Liza the PGS", "W", 30)
    };
    for (int i = 0; i < n; i++)
        arr[i]->hello();
    for (int i = 0; i < n; i++)
        delete arr[i];

}