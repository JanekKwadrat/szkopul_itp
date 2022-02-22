#include <iostream>

typedef unsigned long long u64;
typedef unsigned int u32;

const u64 Mod = 1e9 + 7;
const u32 MaxN = 1e6 + 20;

u64 reverse(u64 a, u64 M) {
    if(!a) return 0;
    if(!M) return a == 1;
    return ((M * (a - reverse(M % a, a)) + 1) / a) % M;
}

u64 factorial[MaxN];

u32 t;
u64 a, b;

int main() {

    factorial[0] = 1;
    for(u32 i = 1; i < MaxN; ++i)
        factorial[i] = factorial[i-1] * i % Mod;

    std::cin >> t;
    while(t--) {
        std::cin >> a >> b;
        std::cout << factorial[a] * reverse(factorial[b] * factorial[a - b] % Mod, Mod) % Mod << "\n";
    }

    return 0;
}