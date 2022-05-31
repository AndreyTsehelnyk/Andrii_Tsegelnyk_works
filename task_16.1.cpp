#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person {
public:
    string name;
    unsigned byear;
    int input();
    void show();
    friend ostream& operator<<(ostream& out, const Person& p);
    friend istream& operator>>(istream& in, const Person& p);
    friend class Contact;
};


int Person::input() {
    cout << "Name: ";
    cin >> name;
    cout << "Birth year: ";
    cin >> byear;
    return 1;
}


void Person::show() {
    cout << name << " - " << byear;
}


ostream& operator<<(ostream& out, Person& p) {
    p.show();
}


istream& operator>>(istream& in, Person& p) {
    p.input();
}


class Contact : protected Person {
    string t_number;
public:
    string getPhone() { return t_number; };
    void changePhone(string number) { t_number = number; };
    friend ostream& operator<<(ostream& out, const Contact& c);
    friend istream& operator>>(istream& in, Contact& c);
    friend class Directory;
};


ostream& operator<<(ostream& out, const Contact& c) {
    cout << c.name << " - " << c.byear;
    cout << "\nPhone number: " << c.t_number;
}


istream& operator>>(istream& in, Contact& c) {
    cout << "\nName: ";
    cin >> c.name;
    cout << "Birth year: ";
    cin >> c.byear;
    cout << "Phone number: ";
    cin >> c.t_number;
}


class Directory {
    Contact contacts[100];
    unsigned n;
public:
    int addContact(const Contact& c);
    Contact findByPhone(string ph_numb);
    int changePhoneNumber(const Contact& c);
    int fin(const char* fname);
    int fout(const char* fname);
    Directory(const char* fname);
    Directory() { n = 0; };
    friend ostream& operator<<(ostream& out, const Directory& d);
};


Directory::Directory(const char* fname) {
    ifstream file(fname);
    file >> n;
    for (unsigned i = 0; i < n; i++) {
        file >> contacts[i].name >> contacts[i].byear >> contacts[i].t_number;
    }
}


int Directory::fin(const char* fname) {
    ifstream file(fname);
    if (!file.is_open()) return 0;
    if (file.eof()) return 1;
    file >> n;
    for (unsigned i = 0; i < n; i++) {
        file >> contacts[i].name >> contacts[i].byear >> contacts[i].t_number;
    }
    return 1;
}

int Directory::fout(const char* fname) {
    ofstream file(fname);
    if (!file.is_open()) return 0;
    file << n;
    for (unsigned i = 0; i < n; i++) {
        file << " " << contacts[i].name << " " << contacts[i].byear << " " << contacts[i].t_number;
    }
    return 1;
}


int Directory::addContact(const Contact& c) {
    contacts[n].name = c.name;
    contacts[n].byear = c.byear;
    contacts[n].t_number = c.t_number;
    return n++;
}


Contact Directory::findByPhone(string ph_numb) {
    for (unsigned i = 0; i < n; i++) {
        if (contacts[i].t_number == ph_numb) return contacts[i];
    }
    return Contact();
}


int Directory::changePhoneNumber(const Contact& c) {
    for (unsigned i = 0; i < n; i++) {
        if (contacts[i].name == c.name && contacts[i].byear == c.byear) {
            contacts[i].t_number = c.t_number;
            return 1;
        }
    }
    return 0;
}


ostream& operator<<(ostream& out, const Directory& d) {
    for (unsigned i = 0; i < d.n; i++) {
        cout << endl << d.contacts[i];
    }
}


int main() {
    Directory dict;
    Contact c[3];
    for (int i = 0; i < 3; i++) {
        cin >> c[i];
        cout << c[i];
        dict.addContact(c[i]);
    }
    cout << endl << dict;
    cout << endl << endl << dict.findByPhone(c[0].getPhone());
    cout << "\nNew phone: ";
    string item;
    cin >> item;
    c[0].changePhone(item);
    dict.changePhoneNumber(c[0]);
    cout << dict;
}