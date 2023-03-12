/*  Jan Zakrzewski
    XXVI Olimpiada Informatyczna, Etap I
    Zadanie `Klubowicze 2 (klu)' */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned int u32;
constexpr int N = 2e6 + 20;
int n, m;
u32 a[N];

u32 zeros[32];
u32 ones[32];

int ans = 0;
int p, q;

inline int bit(const u32& x, const int& i) {
    return (x >> i) % 2;
}

int main() {

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) cin >> a[i];

    for(int i = 1; i <= m; ++i) {
        for(int j = 0; j < 32; ++j) {
            zeros[j] += (bit(a[i], j) == 0);
            ones[j]  += (bit(a[i], j) == 1);
        }
    }

    for(int i = 0; i < 32; ++i) {
        zeros[i] = !zeros[i];
        ones[i]  = !ones[i];
    }

    p = 0;
    q = -1;

    while(true) {
        q++;
        if(q > m) break;
        bool ok = true;
        for(int i = 0; i < 32; ++i) {
            zeros[i] += (bit(a[q], i) == 0);
            ones[i]  += (bit(a[q], i) == 1);
            ok = ok && zeros[i];
            ok = ok && ones[i];
        }
        if(ok) {
            cout << p << " " << q << "\n";
            ans += m - q + 1;
            for(int i = 0; i < 32; ++i) {
                zeros[i] -= (bit(a[p], i) == 0);
                ones[i]  -= (bit(a[p], i) == 1);
            }
            p++;
            if(p > m) break;
        }
    }

    cout << ans << "\n";

    return 0;
}
