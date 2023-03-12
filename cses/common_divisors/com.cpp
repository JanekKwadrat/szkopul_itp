#include <iostream>

inline int max(int a, int b) {
    return a > b ? a : b;
}

constexpr int max_n = 2e5 + 20;
constexpr int max_x = 1e6 + 20;

int n, x;
int answer = 1;
int numbers[max_x]{};

int main() {

    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> x;
        for(int d = 2; d * d <= x; ++d) {
            if(x % d) continue;
            if(numbers[d]) answer = max(answer, d);
            while(x % d == 0) {
                ++numbers[d];
                x /= d;
            }
        }
        if(x == 1) continue;
        if(numbers[x] > 0) answer = max(answer, x);
        ++numbers[x];
    }
    std::cout << answer << "\n";

    return 0;
}