//class14.4

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const char* fname = "test.txt";

    fstream f;
    f.open(fname, fstream::in);

    if (!f) {
        cerr << "cannot open file" << fname << "!";
        return;
    }

    string tagOpen = "<td>";
    string tagClose = "<\\td>";

    string line;
    int count = 0;
    while (f.is_open()) {
        getline(f, line);

        string::size_type k = 0;
        string::size_type posOpen = line.find(tagOpen);
        string::size_type posClose = line.find(tagClose);

        while (true) {
            posOpen = line.find(tagOpen, k);
            posClose = line.find(tagClose, k);
            if (posOpen == string::npos && posClose == string::npos) {
                break;
            }
            if (posOpen < posClose && posOpen != string::npos) {
                k = posOpen;
            }
            else if (posOpen > posClose && posClose != string::npos) {
                k = posClose + 1;
                count--;
            }
            if (count < 0) {
                isCorrect = false;
                break;
            }
        }
        if (!isCorrect) {
            break;
        }

    }
    f.close();
    std::cout << boolalpha << std::isCorrect && (count == 0);

}
