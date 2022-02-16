#include <iostream>
#include <random>
#include <cstdlib>

int main() {
    srand(time(nullptr));
    rand();
    rand();
    rand();
    //std::cout << "0.." << RAND_MAX << "\n";
    const int mod = 1e5;
    std::cout << rand() % mod + 2 << " " << rand() % mod + 1 << " " << rand() % 10 << "\n";

    return 0;
}