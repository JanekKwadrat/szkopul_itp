/*
    Jan Zakrzewski
    XXVIII Olimpiada Informatyczna, Etap II
    Zadanie Plażowicze
    Podzadanie 2
*/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;

u64 ilog2(u64 xx) {
    u64 ans = 0;
    while(xx > 1) {
        xx /= 2;
        ans++;
    }
    return ans;
}

constexpr int N = 1'000'010;
int n, X, z, k;
u64 x[N];

int main() {

    cin >> n >> X >> z;
    for(u64 i = 1; i <= n; ++i) cin >> x[i];
    while(z--) {
        cin >> k;
        u64 p = 1 << ilog2(k);
        u64 a = 2 * (k - p) + 1;
        u64 b = 2 * p;
        a *= X;
        while(a % 2 == 0 && b % 2 == 0) {
            a /= 2;
            b /= 2;
        }
        cout << a << "/" << b << "\n";
    }

    return 0;
}