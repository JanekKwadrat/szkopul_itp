/* Jan Zakrzewski
   XXII Olimpiada Informatyczna, Etap I
   Zadanie `Kwadraty (kwa)' */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;

constexpr u64 INF = 2e18;
constexpr u64 I0 = 1817121; // najmniejsze I0 takie, że squares(I0) >= INF
inline u64 squares(u64 n) {
    // zwraca sumę 1*1 + 2*2 + ... + n*n, musi zachodzić 0 <= n <= INF
    if(n >= I0) return INF;
    else return n * (n + 1) * (2 * n + 1) / 6;
}
u64 znajdz(u64 x) {
    // znajduje najmniejsze takie n, że squares(n) >= x, musi zachodzić 0 <= x <= INF, znajdz(INF) = INF
    if(x == INF) return INF;
    if(x == 0) return 0;
    u64 a = 0, b = I0; // w każdym momencie zachodzi squares(a) < x <= squares(b)
    while(b > a + 1) {
        u64 mid = (a + b) / 2;
        if(squares(mid) >= x) b = mid;
        else a = mid;
    }
    return b;
}
// zachodzi następująca własność, dla dowolnego 0 <= x <= INF, k(x) >= znajdz(x)

// okazuje się, że dla wszystkich x >= 129 zachodzi k(x) < INF
// ponadto dla wszystkich x >= 379 zachodzi k(x) <= znajdz(x) + 1
// maksymalne k(x) < INF na przedziale 0 <= x <= 378 jest 12

constexpr u64 N = 379;

u64 small_k[N];
u64 k(u64 x) {
    // oblicza k(x), musi zachodzić 0 <= x <= INF, k(INF) = INF
    if(x == INF) return INF;
    if(x < N) return small_k[x];
    else {
        u64 n = znajdz(x);
        u64 y = squares(n) - x; // dla x >= N zachodzi y < x
        if(k(y) < n) return n;
        else return n + 1;
    }
}

u64 ile1(u64 n) {
    // oblicza ile jest liczb przerośniętych w przedziale od 1 do n, musi zachodzić 0 <= n <= INF, ile(INF) = INF
    if(n == INF) return INF;
    u64 ans = 0;
    for(u64 x = 1; x <= n; ++x) {

        if(k(x) > znajdz(x)) ans++;
    }
    return ans;
}

u64 ile_przedzial(u64 l, u64 r) {
    u64 ans = 0;
    for(u64 x = l; x <= r; ++x) {
        if(k(x) > znajdz(x)) ans++;
    }
    return ans;
}

// liczba x jest przerośnięta dokładnie wtedy, gdy k(x) > znajdz(x)

constexpr u64 M = 40; // niekoniecznie najmniejsze możliwe
constexpr u64 ILE = 31;
// dla n >= 12, M >= 12 na przedziale squares(n-1) < x <= squares(n) jest 31 = ILE liczb przerośniętych

u64 small_ile[M]; // small_ile[n] = ile jest liczb przerośniętych na przedziale squares(n-1) < x <= squares(n)
u64 ile(u64 X) {
    u64 n = znajdz(X);
    u64 ans = 0;
    for(u64 k = 1; k < M && k < n; ++k)
        ans += small_ile[k];
    ans += ILE * min(n - M, 0ull);
    ans += ile_przedzial(squares(n-1)+1, squares(n));
    return ans;
}

u64 n;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);

    small_k[0] = 0;
    for(u64 x = 1; x < N; ++x) {
        u64 n = znajdz(x);
        u64 y = squares(n) - x;
        small_k[x] = INF;
        if(y < x && small_k[y] < n)
            small_k[x] = n;
        else while(true) {
            n++;
            if(n * n > x) break;
            if(small_k[x - n * n] < n) {
                small_k[x] = n;
                break;
            }
        }
    }
    
    for(u64 k = 1; k < M; ++k) {
        cout << k << " " << (small_ile[k] = ile_przedzial(squares(k-1)+1, squares(k))) << "\n";
    }

    cin >> n;

    pair<u64, u64> odp = make_pair(k(n), ile1(n));
    if(odp.first < INF) cout << odp.first << " ";
    else cout << "- ";
    cout << odp.second << "\n";
    cout << ile(n) << "\n";

    return 0;
}
