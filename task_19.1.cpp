#include <iostream>
#include <queue>

int main() {
    int n;

    std::cout << "Enter number of customers:";
    std::cin >> n;

    std::queue<int> t;
    int time, i;

    for (i = 0; i < n; ++i) {
        std::cout << "Enter time of customer #" << i << ":";
        std::cin >> time;

        t.push(time);
    }

    std::queue<int> c;
    int total_time = 0;
    int k = 0, tmp, t2;

    while (!t.empty()) {
        tmp = t.front();

        t.pop();

        total_time += tmp;
        t2 = (total_time > k) ? (total_time - k) : 0;
        ++k;

        c.push(t2);
    }

    i = 0;

    while (!c.empty()) {
        std::cout << "Customer " << i << " waited " << c.front() << ";\n";

        c.pop();

        ++i;
    }
}