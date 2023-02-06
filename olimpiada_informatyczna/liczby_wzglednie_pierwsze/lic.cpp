/* Jan Zakrzewski
   XXIX Olimpiada Informatyczna, Etap II
   Zadanie `Liczby względnie pierwsze (lic)' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
i64 n, k;
int c;
i64 N;

int P = 0; // liczba n może mieć maksymalnie 12 dzielników pierwszych
i64 primes[12];
int M; // = 2 ** P
i64 numbers[4096]; // products of respective primes
int mobius[4096];

i64 ile(i64 N) {
    // ile jest takich 1 <= x <= N, że gcd(x, n) = 1
    i64 ans = 0;
    for(i64 i = 0; i < M; ++i)
        ans += N / numbers[i] * mobius[i];
    return ans;
}

i64 znajdz() {
    // jakie jest najmniejsze N takie, że ile(N) >= k
    // w każdym momencie ile(p) < k <= ile(q)
    i64 p = 0, q = 1e18;
    while(q - p > 1) {
        i64 mid = (p + q) / 2;
        if(ile(mid) < k) p = mid;
        else q = mid;
    }
    return q;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k >> c;

    // get prime divisors of the number n
    i64 nn = n;
    for(i64 p = 2; p*p <= nn; ++p) {
        if(nn % p == 0) primes[P++] = p;
        while(nn % p == 0) nn /= p; 
    }
    if(nn > 1) primes[P++] = nn;
    
    // get the arrays numbers[] and mobius[]
    M = 1 << P;
    for(int i = 0; i < M; ++i) {
        numbers[i] = 1;
        mobius[i] = 1;
    }
    for(int i = 0; i < P; ++i) {
        for(int j = 0; j < M; ++j) {
            if(!((1 << i) & j)) continue;
            numbers[j] *= primes[i];
            mobius[j] *= -1;
        }
    }

    // for now on the function ile(i64) can be called
    N = znajdz();
    while(c > 0) {
        if(gcd(N, n) == 1) {
            cout << N << " ";
            c--;
        }
        N++;
    }
    cout << "\n";

    return 0;
}
