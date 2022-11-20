/*
    Jan Zakrzewski
    XXX Olimpiada Informatyczna, Etap I
    Rozwiązanie podzadań 1 i 2 zadania 'Wyprzedzanie (wyp)'
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef int i32;

constexpr int N = 100'050;

int n;
i64 D;
i64 W, M;

i64 x[N], d[N];
i64 w[N], m[N];

int ans = 0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> D >> W >> M;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i] >> d[i];
        cin >> w[i] >> m[i];
    }

    for(int i = 1; i <= n-1; ++i) {
        if( w[i+1] * m[i] - m[i+1] * w[i] < 0 ) {
            cout << "NIE_TO_PODZADANIE\n";
            return 0;
        }
    }

    for(int i = 1; i <= n-1; ++i) {
        ans += ( m[i+1] * (x[i+1]-d[i+1]) * (W*m[i]-M*w[i]) ) / ( (W*m[i+1]-M*w[i+1]) * m[i] ) >= D + x[i];
    }

    cout << ans + 1 << "\n";

    return 0;
}