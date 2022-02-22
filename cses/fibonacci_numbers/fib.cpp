#include <iostream>

typedef unsigned long long u64;
const u64 Mod = 1e9 + 7;
u64 fib(u64, u64);

u64 n;

int main() {

    std::cin >> n;
    std::cout << fib(n, Mod) << "\n";

    return 0;
}

void mov_matrix2d(u64 A[2][2], u64 B[2][2]) {
    A[0][0] = B[0][0];
    A[0][1] = B[0][1];
    A[1][0] = B[1][0];
    A[1][1] = B[1][1];
}

void mul_matrix2d(u64 A[2][2], u64 B[2][2]) {
    u64 Z[2][2];
    Z[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    Z[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    Z[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    Z[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    mov_matrix2d(A, Z);
}

void mod_matrix2d(u64 A[2][2], u64 M) {
    A[0][0] %= M;
    A[0][1] %= M;
    A[1][0] %= M;
    A[1][1] %= M;
}

u64 fib(u64 k, u64 M) {
    u64 ans[2][2] = {{1, 0}, {0, 1}};
    u64 mat[2][2] = {{1, 1}, {1, 0}};
    while(k) {
        if(k % 2) {
            mul_matrix2d(ans, mat);
            mod_matrix2d(ans, M);
        }
        mul_matrix2d(mat, mat);
        mod_matrix2d(mat, M);
        k /= 2;
    }
    return ans[1][0];
}
