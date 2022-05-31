#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <iterator>
#include <set>
#include <map>

int main() {
    std::fstream in("text.txt");
    std::string s;
    std::map<std::string, unsigned> counter;

    while (!in.eof()) {
        in >> s;

        ++counter[s];
    }

    for (const auto& [word, count] : counter)
        std::cout << word << '\t' << count << '\n';

    in.close();
}