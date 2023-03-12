/*  Jan Zakrzewski
    XXVIII Olimpiada Informatyczna, Etap III
    Zadanie Kolekcjoner bajtemonów 2 (kol) */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;
typedef unsigned long u32;
constexpr int N = 1e6+20;
constexpr int K = 5e5+20;
int n;
u32 a[N];
u64 b[N];
bool d[K];
u64 ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    
    ans = 0;
    for(int i = 0; i < n; ++i) ans = gcd(ans, b[i]);

    for(int i = 0; i < K; ++i) d[i] = true;
    for(u32 p = 2; p < K; ++p) {
        if(!d[p]) continue;
        bool ok = true;
        for(int i = 0; i < n; ++i) {
            if(a[i] % p != 0 && b[i] % p != 0) {
                ok = false;
                break;
            }
        }
        if(ok) ans = max(ans, (u64)p);
        else for(int j = 2*p; j < K; j += p) d[j] = false;
    }

    cout << ans << "\n";

    return 0;
}
