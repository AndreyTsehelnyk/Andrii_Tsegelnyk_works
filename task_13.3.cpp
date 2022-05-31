#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string removelast(string str) {
    str += " ";

    string res = "", w = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && str[i - 1] != ' ') {
            res += w.substr(0, w.length() - 1) + " ";
            w = "";
        }
        else {
            w += str[i];
        }
    }
    return res;
}


int main() {
    string str = "dfhf  dsjfjdkfewlfal   ";
    int space1 = str.find(' ');
    if (space1 == -1) {
        str.erase(str.length() - 1, str.length());
        cout << str;
    }
    else {
        cout << removelast(str);
    }

}