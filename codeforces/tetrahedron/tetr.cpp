#include <iostream>

typedef unsigned long long ull;
const ull M = 1e9 + 7;

struct Matrix {
    ull a, b;
    ull c, d;
    Matrix(ull a, ull b, ull c, ull d) {
        this->a = a, this->b = b;
        this->c = c, this->d = d;
    }
    Matrix operator*(Matrix oth) {
        return Matrix(
            (a * oth.a + b * oth.c) % M, (a * oth.b + b * oth.d) % M,
            (c * oth.a + d * oth.c) % M, (c * oth.b + d * oth.d) % M
        );
    }
};

Matrix solve(int k) {
    Matrix ans(
        1, 0,
        0, 1
    );
    Matrix nmb(
        0, 3,
        1, 2
    );
    while(k) {
        if(k % 2) ans = nmb * ans;
        nmb = nmb * nmb;
        k /= 2;
    }
    return ans;
}

int main() {

    int n;
    std::cin >> n;
    Matrix sth = solve(n);
    std::cout << sth.a << "\n";

    return 0;
}