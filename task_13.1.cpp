#include <iostream>
#include <string>
using namespace std;


string f1(const string& s) {
    int i = s.find(":");
    if (i == -1)
        return string(s);
    int j = s.find(",", i);
    if (j == -1)
        return string(s, i + 1);
    return s.substr(i + 1, j - i - 1);
}


void f2(string& s) {
    int i = s.find(":");
    if (i == -1)
        return;
    int j = s.find(",", i);
    if (j == -1) {
        s.erase(0, i + 1);
        return;
    }
    s.erase(j);
    s.erase(0, i + 1);
}


int main() {
    string s;
    cin >> s;
    cout << f1(s) << endl;
    f2(s);
    cout << s << endl;
    return 0;
}