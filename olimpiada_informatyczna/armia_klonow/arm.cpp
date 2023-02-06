/* Jan Zakrzewski
   XXIX Olimpiada Informatyczna, Etap II
   Zadanie `Armia klonów (arm)' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

constexpr i64 INF = 1e18 + 100;
inline i64 Cap(i64 x) {
    if(x > INF) return INF;
    else return x;
}

inline i64 Mul(i64 x, i64 y) {
    // for x, y in [0, INF] returns their product clamped to [0, INF]
    if(y > (2 * INF) / x) return INF;
    else return Cap(x * y);
}

i64 Pow(i64 x, i64 k) {
    // for x, k in [0, INF] returns the power clamped to [0, INF]
    i64 ans = 1;
    while(k > 0) {
        if(k % 2 == 1) ans = Mul(ans, x);
        x = Mul(x, x);
        k /= 2;
    }
    return ans;
}

i64 n, a, b;

// faktyczna odpowiedż na pewno nie przekracza 70 * (a + b) <= 1.4 * 10^11

i64 najlepszy(i64 ile_a, i64 ile_b) {
    // jaką największą liczebność armii można osiągnąć przeprowadzając odpowiednią liczbę każdej z operacji
    // a in [1, 100], b in [0, 1e12)
    i64 k1 = ile_b / ile_a;
    i64 k2 = k1 + 1;
    i64 C2 = ile_b % ile_a;
    i64 C1 = ile_a - C2;

    return Mul(Pow(k1 + 1, C1), Pow(k2 + 1, C2));
}

i64 phi(i64 ile_a) {
    // zwraca najmniejsze ile_b takie, że najlepszy(ile_a, ile_b) > n
    i64 p = 0, q = 1e12; // w każdym momencie prawdą jest, że najlepszy(ile_a, p) <= n < najlepszy(ile_b, q)
    while(q - p > 1) {
        i64 mid = (p + q) / 2;
        if(najlepszy(ile_a, mid) <= n) p = mid;
        else q = mid;
    }
    return q;
}

i64 rozwiaz() {
    i64 odp = INF;
    for(i64 ile_a = 1; ile_a <= 100; ++ile_a) {
        i64 ile_b = phi(ile_a);
        i64 nowa = Cap(Mul(a, ile_a) + Mul(b, ile_b));
        odp = min(odp, nowa);
    }
    return odp;
}

int main() {

    cin >> n >> a >> b;

    cout << rozwiaz() << "\n";

    return 0;
}
