/*
    Jan Zakrzewski
    XVII Olimpiada Informatyczna, Etap I
    Rozwiązanie zadania 'Najdzielniejszy dzielnik (naj)'

    Złożoność czasowa: < O(n * K)
*/

#include <bits/stdc++.h>
using namespace std;

typedef int i32;
typedef unsigned long long u64;
typedef long long i64;
typedef long double f80;
typedef unsigned int u32;

i32 is_prime(u64);
u64 gcd(u64, u64);
u64 sqrt__(u64);

constexpr int Q = 600;
constexpr int K = 1'000'000;

u32 q, k, l, m;
u64 a[Q];
u32 primes[K];
u32 exponents[K];
u64 big_primes[4 * Q * Q];
u32 big_exponents[4 * Q * Q];
u64 two_primes[Q];
u32 two_exponents[Q];

vector<u32> krotnosci;
u32 najlepsza_krotnosc;
u32 ile_tej_krotnosci;

char* wynik(u32 x) {
    constexpr u32 L = 160;
    u32 ans[L] = { 1 };
    while(x > 0) {
        for(int i = 0; i < L; ++i) ans[i] *= 2;
        for(int i = 0; i < L-1; ++i) {
            ans[i+1] += ans[i] / 1'000'000'000;
            ans[i] %= 1'000'000'000;
        }
        x--;
    }
    ans[0] -= 1;
    char* str = new char [L * 9];
    for(int i = 0; i < L; ++i) {
        u32 A = ans[i];
        for(int j = 0; j < 9; ++j) {
            str[i * 9 + j] = '0' + A % 10;
            A /= 10;
        }
    }
    int len = L * 9;
    while(1) {
        len--;
        if(str[len] != '0') break;
    }
    len++;
    reverse(str, str + len);
    str[len] = 0;
    return str;
}

int main() {

    cin >> q;
    for(u32 i = 0; i < q; ++i) cin >> a[i];

    // sieve of Eratosthenes
    primes[0] = 0;
    primes[1] = 0;
    fill(primes + 2, primes + K, 1);
    for(u32 i = 2; i * i < K; ++i) {
        if(!primes[i]) continue;
        for(u32 j = 2 * i; j < K; j += i) primes[j] = 0;
    }
    k = 0;
    for(u32 i = 0; i < K; ++i) {
        if(primes[i]) {
            primes[k] = i;
            ++k;
        }
    }

    // counting p-adic exponents
    fill(exponents, exponents + k, 0);
    for(u32 i = 0; i < q; ++i) {
        for(u32 j = 0; j < k; ++j) {
            u64 p = primes[j];
            while(a[i] % p == 0) {
                a[i] /= p;
                exponents[j]++;
            }
        }
    }
    
    // looking for big primes
    l = 0;
    for(u32 i = 0; i < q; ++i) {
        for(u32 j = i+1; j < q; ++j) {
            if(a[i] == a[j]) continue;
            u32 d = gcd(a[i], a[j]);
            if(d != 1) big_primes[l++] = d;
            else continue;
            if(d != a[i]) big_primes[l++] = a[i] / d;
            if(d != a[j]) big_primes[l++] = a[j] / d;
        }
    }
    for(u32 i = 0; i < q; ++i) {
        if(is_prime(a[i])) big_primes[l++] = a[i];
        u64 s = sqrt__(a[i]);
        if(s != 1 && s * s == a[i]) big_primes[l++] = s;
    }
    sort(big_primes, big_primes + l);
    l = (u32) ( unique(big_primes, big_primes + l) - big_primes );

    //cout << "here1\n";

    // counting p-adic exponents for big primes
    fill(big_exponents, big_exponents + k, 0);
    for(u32 i = 0; i < q; ++i) {
        for(u32 j = 0; j < l; ++j) {
            u64 p = big_primes[j];
            while(a[i] % p == 0) {
                a[i] /= p;
                big_exponents[j]++;
            }
        }
    }

    // looking for semiprimes
    m = 0;
    for(u32 i = 0; i < q; ++i) {
        if(a[i] != 1) two_primes[m++] = a[i];
    }
    sort(two_primes, two_primes + m);
    m = (u32) ( unique(two_primes, two_primes + m) - two_primes );
    
    //for(int i = 0; i < m; ++i) cout << two_primes[i] << " "; cout << "\n";
    
    fill(two_exponents, two_exponents + m, 0);
    for(u32 i = 0; i < q; ++i) {
        for(u32 j = 0; j < m; ++j) {
            u64 p = two_primes[j];
            while(a[i] % p == 0) {
                a[i] /= p;
                two_exponents[j]++;
            }
        }
    }

    //cout << "here2\n";

    for(u32 i = 0; i < k; ++i) krotnosci.push_back(exponents[i]);
    for(u32 i = 0; i < l; ++i) krotnosci.push_back(big_exponents[i]);
    for(u32 i = 0; i < m; ++i) {
        krotnosci.push_back(two_exponents[i]);
        krotnosci.push_back(two_exponents[i]);
    }

    najlepsza_krotnosc = 0;
    ile_tej_krotnosci = 0;
    for(u32 x : krotnosci) {
        if(x < najlepsza_krotnosc) continue;
        if(x > najlepsza_krotnosc) {
            najlepsza_krotnosc = x;
            ile_tej_krotnosci = 1;
        } else ile_tej_krotnosci++;
    }

    //cout << ile_tej_krotnosci << "\n";
    cout << najlepsza_krotnosc << "\n" << wynik(ile_tej_krotnosci) << "\n";

    return 0;
}

// from ntlib.c

//modmul by kactl, adapted for primality testing
//note: M can be max 7'268'999'999'999'999'999
//note: 0 <= a, b < M shall hold
inline u64 __modmul2(u64 a, u64 b, u64 M, f80 r) {
	i64 ret = a * b - M * (u64)(r * a * b);
	return ret + M * (ret < 0) - M * (ret >= (i64)M);
}

i32 miller_rabin_single(u64 x, u64 a, f80 r) {
    u64 y = x - 1, aa = a;
    u64 u = 1; u32 k = 0;
    while(y) {
        if(y % 2) break;
        ++k;
        y /= 2;
    }
    while(y) {
        u = (y % 2) * (__modmul2(u, aa, x, r) - u) + u;
        aa = __modmul2(aa, aa, x, r);
        y /= 2;
    }

    if(u == 1) return 1;
    while(k--) {
        if(u + 1 == x) return 1;
        u = __modmul2(u, u, x, r);
    }
    return 0;
}

i32 is_prime(u64 x) {
    //note: x can be max 7'267'999'999'999'999'999
    if(x < 2) return 0;
    f80 r = 1.L / x;
    if(x !=  2 && !miller_rabin_single(x,  2, r)) return 0;
    if(x !=  3 && !miller_rabin_single(x,  3, r)) return 0;
    if(x !=  5 && !miller_rabin_single(x,  5, r)) return 0;
    if(x !=  7 && !miller_rabin_single(x,  7, r)) return 0;
    if(x != 11 && !miller_rabin_single(x, 11, r)) return 0;
    if(x < 2'152'302'898'747ULL) return 1;
    if(x != 13 && !miller_rabin_single(x, 13, r)) return 0;
    if(x != 17 && !miller_rabin_single(x, 17, r)) return 0;
    if(x != 19 && !miller_rabin_single(x, 19, r)) return 0;
    if(x != 23 && !miller_rabin_single(x, 23, r)) return 0;
    if(x < 3'825'123'056'546'413'051ULL) return 1;
    if(x != 29 && !miller_rabin_single(x, 29, r)) return 0;
    if(x != 31 && !miller_rabin_single(x, 31, r)) return 0;
    if(x != 37 && !miller_rabin_single(x, 37, r)) return 0;
    return 1;
}

u64 gcd(u64 a, u64 b) {
    while(1) {
        if(b == 0) return a;
        a %= b;
        if(a == 0) return b;
        b %= a;
    }
}

u64 sqrt__(u64 n) {
    u64 p = 0, q = (u32)0xffffffff;
    while(q - p > 1) {
        u64 mid = (p + q) / 2;
        if(mid * mid > n) q = mid;
        else p = mid;
    }
    return p;
}