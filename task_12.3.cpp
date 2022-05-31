#include <iostream>
#include <cmath>


int main() {


    int n = 5;
    std::cout << "n=";
    std::cin >> n;

    double x;
    std::cout.precision(3);
    std::cout.fill(' ');

    for (x = 1.0; x <= n; x++) {
        std::cout << "++++++";
    }
    std::cout << std::endl;

    std::cout.width(3);
    std::cout << 1 << " ";

    for (x = 2.0; x <= n; x++) {
        std::cout.width(5);
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (x = 1.0; x <= n; x++) {
        std::cout << "++++++";
    }

    std::cout << std::endl;

    std::cout.width(3);
    std::cout << 1.0 << " ";

    for (x = 2.0; x <= n; x++) {
        std::cout.width(5);
        std::cout << sqrt(x) << " ";
    }
    std::cout << std::endl;
    for (x = 1.0; x <= n; x++) {
        std::cout << "++++++";
    }
    std::cout << std::endl;

}