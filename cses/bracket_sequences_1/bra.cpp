#include <iostream>

using std::cin, std::cout;
typedef int                 i32;
typedef unsigned long long  u64;

constexpr u64 Mod = 1'000'000'007;

inline u64 mod_reverse(u64 a, u64 M = Mod) {
    u64 x = 1, y = 0;
    while(1) {
        if(a == 0) return y;
        u64 k = a / M;
        a %= M;
        x -= y * k;
        if(M == 0) return x;
        u64 l = M / a;
        M %= a;
        y -= x * l;
    }
}

u64 choose(u64 a, u64 b) {
    u64 c = a - b;
    u64 x = 1, y = 1;
    for(int i = 1; i <= a; ++i) x = x * i % Mod;
    for(int i = 1; i <= b; ++i) y = y * i % Mod;
    for(int i = 1; i <= c; ++i) y = y * i % Mod;
    x *= mod_reverse(y);
    return x;
}

int main() {



    return 0;
}