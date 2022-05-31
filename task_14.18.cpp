#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int main() {
    int N = 5;
    ofstream F2;
    ifstream F1;
    F1.open("C:\\Users\\Andrii\\Desktop\\учебное\\C\\Project2\\file1.txt", ios::in);
    F2.open("C:\\Users\\Andrii\\Desktop\\учебное\\C\\Project2\\file2.txt", ios::out);

    string min_str;
    string max_str;
    int min_len=1000;
    int max_len=0;
    char value;
    int k = 1;
    while (k<N) {
        string str;
        getline(F1, str);
        int len = str.length();
        if (len > max_len) {
            max_len = len;
            max_str = str;
        }
        if (len < min_len) {
            min_len = len;
            min_str = str;
        }
        k++;
    }
    F2 << "max string: " << max_str << endl;
    F2 << "min string: " << min_str << endl;
    
    F1.close();
    F2.close(); 
}
