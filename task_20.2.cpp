#include <iostream>
#include <iterator>
#include <set>

int main() {

    std::set<double> nums = { 1, 2, 3, 4, 5, 6 };
    std::set<double> tmp;

    while (nums.size() != 1) {
        for (auto it = nums.cbegin(); it != nums.cend(); it++) {
            if (std::next(it) != nums.cend())
                tmp.insert(*it + *std::next(it));
        }

        nums = tmp;

        tmp.clear();
    }

    for (auto i : nums)
        std::cout << i << '\n';
}