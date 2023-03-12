#include <bits/stdc++.h>
using namespace std;

typedef unsigned int u32;
typedef unsigned long long u64;

u32 solve(u64 n) {
    constexpr u64 M = 1e9 + 7;
    u64 ans = 1;
    u64 a = 10;
    while(n > 0) {
        if(n % 2) ans = ans * (a + 1) % M;
        a = a * a % M;
        n /= 2;
    }
    return (u32) ans;
};

int main() {

    while(true) {
        u64 x;
        cin >> x;
        cout << solve(x) << "\n";
    }

    return 0;
}