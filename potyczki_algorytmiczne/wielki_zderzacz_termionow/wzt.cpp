/*  Jan Zakrzewski
    Potyczki Algorytmiczne 2022
    Zadanie Wielki Zderzacz Termionów
    Rozwiązanie w złożoności ~ 49n * 49q*log2(n) */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;
typedef unsigned int u32;

constexpr u32 MOD = 1e9 + 7;
constexpr int N = 200'020;
int n, q;

constexpr int Delta = 262'144; // = 2^18

struct U {
    u32 a, b, ab, ba;
    u32 A, B, AB;
    bool eps;
};

char str[N];
U arr[2 * Delta];

inline U circle(U, U);

inline U charToU(char c) {
    U ans;
    switch(c) {
        case 'C': ans = {1, 0}; break;
        case 'Z': ans = {0, 1}; break;
        case 'N': ans = {1, 1}; break;
        case '.': ans.eps = true; break;
    }
    return ans;
}

inline u32 Answer(U x) {
    if(x.eps) return 0;
    u32 ans = 0;
    if(n == 1) ans = (ans + x.a) % MOD;
    if(n == 1) ans = (ans + x.b) % MOD;
    ans = (ans + x.A) % MOD;
    ans = (ans + x.B) % MOD;
    return ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    cin >> str;

    for(int i = 0; i < n;     ++i) arr[i+Delta] = charToU(str[i]);
    for(int i = n; i < Delta; ++i) arr[i+Delta] = charToU('.');

    for(int i = Delta-1; i >= 1; --i) arr[i] = circle(arr[2 * i], arr[2 * i + 1]);

    cout << Answer(arr[1]) << "\n";
    while(q--) {
        int k; char c; 
        cin >> k >> c;
        k = k - 1 + Delta;
        arr[k] = charToU(c);
        while(1) {
            k /= 2;
            if(k < 1) break;
            arr[k] = circle(arr[2 * k], arr[2 * k + 1]);
        }
        cout << Answer(arr[1]) << "\n";
    }

    return 0;
}

inline void func(u32 x, u32 y, u32 &z) {
    z = ((u64) x * y + z) % MOD;
}

inline U circle(U x, U y) {
    U z = {};
    
    if(x.eps) return y;
    if(y.eps) return x;

    func(x.a,  y.a,  z.B );
    func(x.a,  y.b,  z.ab);
    func(x.a,  y.ab, z.A );
    func(x.a,  y.ba, z.a );
    func(x.a,  y.A,  z.B );
    func(x.a,  y.B,  z.AB);
    func(x.a,  y.AB, z.A );

    func(x.b,  y.a,  z.ba);
    func(x.b,  y.b,  z.A );
    func(x.b,  y.ab, z.b );
    func(x.b,  y.ba, z.B );
    func(x.b,  y.A,  z.AB);
    func(x.b,  y.B,  z.A );
    func(x.b,  y.AB, z.B );

    func(x.ab, y.a,  z.a );
    func(x.ab, y.b,  z.B );
    func(x.ab, y.ab, z.ab);
    func(x.ab, y.ba, z.AB);
    func(x.ab, y.A,  z.A );
    func(x.ab, y.B,  z.B );
    func(x.ab, y.AB, z.AB);

    func(x.ba, y.a,  z.A );
    func(x.ba, y.b,  z.b );
    func(x.ba, y.ab, z.AB);
    func(x.ba, y.ba, z.ba);
    func(x.ba, y.A,  z.A );
    func(x.ba, y.B,  z.B );
    func(x.ba, y.AB, z.AB);

    func(x.A,  y.a,  z.B );
    func(x.A,  y.b,  z.AB);
    func(x.A,  y.ab, z.A );
    func(x.A,  y.ba, z.A );
    func(x.A,  y.A,  z.B );
    func(x.A,  y.B,  z.AB);
    func(x.A,  y.AB, z.A );

    func(x.B,  y.a,  z.AB);
    func(x.B,  y.b,  z.A );
    func(x.B,  y.ab, z.B );
    func(x.B,  y.ba, z.B );
    func(x.B,  y.A,  z.AB);
    func(x.B,  y.B,  z.A );
    func(x.B,  y.AB, z.B );

    func(x.AB, y.a,  z.A );
    func(x.AB, y.b,  z.B );
    func(x.AB, y.ab, z.AB);
    func(x.AB, y.ba, z.AB);
    func(x.AB, y.A,  z.A );
    func(x.AB, y.B,  z.B );
    func(x.AB, y.AB, z.AB);

    return z;
}