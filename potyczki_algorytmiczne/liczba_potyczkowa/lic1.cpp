#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;
constexpr u64 M = 1e18;


bool czy_potyczkowa(u64 x) {
    char digits[300];
    int L = 0;
    u64 y = x;
    while(y > 0) {
        digits[L] = y % 10;
        y /= 10;
        L++;
    }
    for(int i = 0; i < L; ++i) {
        if(digits[i] == 0) return false;
        if(x % digits[i] != 0) return false;
    }
    return true;
}

u64 l, r;
u64 ans = 0;

int main() {

    cin >> l >> r;
    for(u64 i = l; i <= r; ++i) {
        if(czy_potyczkowa(i)) ans++;
    }
    cout << ans << "\n";

    return 0;
}