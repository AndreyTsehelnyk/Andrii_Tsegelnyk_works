//class14.2

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    const char* filename = "test.txt";
    fstream f(filename, fstream::in);
    string buff, word(""), res("");

    while (!f.eof()) {
        getline(f, buff);
        for (size_t i = 0; i < buff.size(); i++) {
            if (isalpha(buff[i])) {
                word += buff[i];
            }
            else if (buff[i] == ' ' || buff[i] == ',' || buff[i] == '?' || buff[i] == '!' || buff[i] == ';') {
                for (int i = 0; i < word.length() / 2; i++)
                    swap(word[i], word[word.length() - i - 1]);
                res += word + buff[i];
                word = "";
            }
        }
        for (int i = 0; i < word.length() / 2; i++)
            swap(word[i], word[word.length() - i - 1]);
        res += word + '\n';
    }
    cout << res << '\n';
    f.close();
}