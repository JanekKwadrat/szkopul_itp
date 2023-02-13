/* Jan Zakrzewski
   Potyczki Algorytmiczne 2020
   Zadanie `Liczba potyczkowa (lic)' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

constexpr int MAX_N = 18;
constexpr int MAX_D = 504;
constexpr int MOD_C = 2520;
constexpr i64 UNKNOWN = -234;

int pow10(int k, int M) {
    int ans = 1;
    while(k--) ans = ans * 10 % M;
    return ans;
}

i64 arr[MAX_N+1][MOD_C][MAX_D+1];
void ini() {
    for(int n = 1; n <= MAX_N; ++n)
        for(int D = 1; D <= MAX_D; ++D)
            for(int c = 0; c < MOD_C; ++c)
                arr[n][c][D] = UNKNOWN;
}
i64 phi(int n, int c, int D) {
    /*
        1 <= n <= MAX_N
        0 <= c < MOD_C
        1 <= D <= MAX_D
        phi(n, c, D) = ile jest takich x, że
         - liczba x ma dokładnie n cyfr,
         - liczba x + c jest podzielna przez D,
         - liczba x + c jest podzielna przez wszystkie cyfry liczby x.
    */
    if(D % 10 == 0) return 0;
    if(D > MAX_D) return 0;
    c %= MOD_C;
    if(arr[n][c][D] != UNKNOWN) return arr[n][c][D];
    i64 ans = 0;
    if(n == 1) {
        for(int d = 1; d <= 9; ++d) {
            if(D == 0) continue;
            if((d + c) % D != 0) continue;
            if(c % d != 0) continue;
            ans++;
        }
    } else {
        for(int d = 1; d <= 9; ++d) {
            int D1 = lcm(D, d);
            int c1 = (c + d * pow10(n-1, MOD_C)) % MOD_C;
            if(D1 % 10 == 0) continue;
            ans += phi(n-1, c1, D1);
            //cout << d << " " << phi(n-1, c1, D1) << "\n";
        }
    }
    arr[n][c][D] = ans;
    return ans;
}

i64 ile(i64 y) {
    // ile jest liczb Potyczkowa x takich, że 1 <= x <= y
    if(y == 0) return 0;    
    int n = 0;
    char s[30];
    while(y > 0) {
        s[n] = y % 10;
        y /= 10;
        n++;
    }
    i64 ans = 0;
    int c = 0, D = 1;
    for(int i = n-1; i > 0; --i) {
        ans += phi(i, 0, 1);
        for(int d = 1; d < s[i]; ++d) {
            ans += phi(i, (c + d * pow10(i, MOD_C)) % MOD_C, lcm(D, d));
        }
        D = lcm(D, s[i]);
        c = (c + s[i] * pow10(i, MOD_C)) % MOD_C;
    }
    for(int d = 1; d <= s[0]; ++d) {
        if(D == 0) continue;
        if((d + c) % D != 0) continue;
        if(c % d != 0) continue;
        ans++;
    }
    return ans;
}

i64 l, r, ans;

int main() {

    cin >> l >> r;
    
    ini();
    ans = ile(r) - ile(l-1);
    cout << ans << "\n";

    return 0;
}
