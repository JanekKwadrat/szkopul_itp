#include <bits/stdc++.h>
using namespace std;

typedef unsigned int u32;
typedef unsigned long long u64;
constexpr u64 INF = UINT64_MAX;

inline u64 nice(u64 n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

u64 kappa(u64 x, bool g = false) {
    //cout << "kappa(" << x << ")\n";
    if(x < 0) return INF;
    if(x == 0) return 0;
    u64 a = 0, n = 2'090'000;
    while(n - a > 1) {
        u64 m = (a + n) / 2;
        if(x <= nice(m)) n = m;
        else a = m;
    }
    while(n * n <= x) {
        u64 S = nice(n);
        if(S - x < x) {
            if(kappa(S - x) < n) return n;
        } else {
            if(kappa(x - n*n) < n) return n;  
        }
        n++;
        if(g) cout << "przerosniete " << x << "\n";
    }
    return INF;
}

int main() {

    int P, Q;
    cin >> P >> Q;
    for(int x = P; x <= Q; x++) {
        cout << "k(" << x << ") = " << kappa(x, true) << "\n";
    }
        
    return 0;
}
