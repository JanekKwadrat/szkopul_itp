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
int PODZADANIE = 0;

int n;
i64 D;
i64 W, M;

i64 x[N], d[N];
i64 w[N], m[N];

// fuck implementation defined shit
i64 floordiv(i64 a, i64 b) {
    if(b < 0) {
        a *= -1;
        b *= -1;
    }
    if(a >= 0) return a / b;
    else if(a % b == 0) return a / b;
    else return ( (-a) / b ) * -1 - 1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> D >> W >> M;    
    for(int i = 1; i <= n; ++i) {
        cin >> x[i] >> d[i];
        cin >> w[i] >> m[i];
    }

    PODZADANIE = 2;
    for(int i = 1; i <= n-1; ++i) {
        if( w[i+1] * m[i] - m[i+1] * w[i] < 0 ) {
            PODZADANIE = 0;
            break;
        }
    }
    if(PODZADANIE == 0 && n <= 1000) PODZADANIE = 3;

    if(PODZADANIE == 1 || PODZADANIE == 2) {

        int ans = 0;
        for(int i = 1; i <= n-1; ++i) {
            ans += floordiv( ( m[i+1] * (x[i+1]-d[i+1]) * (W*m[i]-M*w[i]) ) , ( (W*m[i+1]-M*w[i+1]) * m[i] ) ) >= D + x[i];
        }
        cout << ans + 1 << "\n";

    } else if(PODZADANIE == 3 || true) { // to podzadanie zawsze działa, ale nie zawsze szybko

        int ans = 0;
        for(int i = 1; i <= n; ++i) x[i] += D;
        for(int i = 1; i <= n; ++i) {
            i64 sum = 0;
            int good = 1;
            for(int k = 1; i+k <= n; ++k) {
                //cerr << n << " " << i << " " << k << "\n";
                sum += d[i+k];
                good = good && floordiv( ( x[i] * M * (w[i+k] * m[i] - m[i+k] * w[i]) ) , ( (W * m[i] - M * w[i]) * m[i+k] ) ) + (x[i+k] - x[i]) >= D + sum;
            }
            if(good) ans++;
            //if(good) cerr << "    " << i << "\n";
        }
        cout << ans << "\n";

    } else cout << "NIE_TO_PODZADANIE\n";

    return 0;
}