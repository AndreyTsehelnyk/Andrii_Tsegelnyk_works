#include <iostream>
#include <queue>
#include <vector>
#include <iterator>
#include <numeric>

int main() {
    unsigned n, dim;

    std::cout << "Enter count of vectors: ";
    std::cin >> n;
    std::cout << "Enter dimension for each vector: ";
    std::cin >> dim;

    std::vector<std::vector<double>> vectors;
    std::vector<double> v(n), norms;
    size_t i, j;

    for (i = 0; i < n; i++) {
        std::cout << "\nEntering vector #" << i + 1 << ":\n";

        for (j = 0; j < dim; j++) {
            std::cout << "Enter coord #" << j + 1 << ": ";
            std::cin >> v[j];
        }

        norms.push_back(sqrt(std::inner_product(v.begin(), v.end(), v.begin(), 0)));
    }

    for (i = 0; i < n; i++)
        std::cout << "Norm of vector #" << i + 1 << ": " << std::defaultfloat << norms[i] << '\n';
}