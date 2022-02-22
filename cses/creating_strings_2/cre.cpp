#include <iostream>

typedef unsigned long long u64;
typedef unsigned int       u32;

const u32 max_n = 1e6 + 20;
const u64 Mod = 1e9 + 7;

u64 reverse(u64 a, u64 M) {
    if(!a) return 0;
    if(!M) return a == 1;
    return ((M * (a - reverse(M % a, a)) + 1) / a) % M;
}

char str[max_n];
u32 n = 0;
char c;

u64 factorial[max_n];

u64 repeats[26]{};
u64 answer;

int main() {
    factorial[0] = 1;
    for(u32 i = 1; i < max_n; ++i) factorial[i] = factorial[i-1] * i % Mod;

    std::cin >> str;
    while(c = str[n++]) ++repeats[c-'a'];
    --n;
    answer = factorial[n];
    for(u32 i = 0; i < 26; ++i)
        answer = answer * reverse(factorial[repeats[i]] % Mod, Mod) % Mod;
    std::cout << answer << "\n";
    return 0;
}