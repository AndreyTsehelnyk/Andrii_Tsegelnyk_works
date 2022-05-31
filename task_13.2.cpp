#include <iostream>
#include <string>


std::string func(std::string line) {
    int firstdot = line.find(".");
    int secdot = line.find(".", firstdot + 1);

    if (firstdot == std::string::npos && secdot == std::string::npos) {
        int spaceend = line.find_first_not_of(" ");
        line.erase(0, spaceend);
        std::cout << "PRINTER1" << '\n';
    }
    else {
        if (firstdot != std::string::npos && secdot == std::string::npos) {
            line.erase(0, firstdot);
            std::cout << "PRINTER2" << '\n';
        }
        else {
            line.erase(firstdot, secdot - 1);
            std::cout << "PRINTER3" << '\n';
        }
    }
    return line;
}

int main() {
    std::string str = "  Today.is a.good day";
    std::cout << func(str) << '\n';
    str = "  Today.is a good day";
    std::cout << std::endl << func(str) << '\n';
    str = "  Today is a good day";
    std::cout << std::endl << func(str) << '\n';
}