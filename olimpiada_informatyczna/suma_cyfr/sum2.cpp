/*  Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap II
    Zadanie Suma cyfr (sum) */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;

constexpr int MAX_K = 200; // maksymalna liczba cyfr
constexpr int MAX_S = 200;
constexpr int MAX_M = 200;
constexpr u64 INF = 1e18 + 20;

int K, S, M, q;

int pow10_arr[MAX_K+1];

void pow10_init() {
    pow10_arr[0] = 1;
    for(int i = 1; i <= K; ++i)
        pow10_arr[i] = pow10_arr[i-1] * 10 % M;
}

inline int pow10(int k) {
    return pow10_arr[k];
}

u64 phi_arr[MAX_K+1][MAX_S+1][MAX_M];

void phi_init() {
    for(int s = 0; s <= S; ++s)
        for(int c = 0; c < M; ++c)
            phi_arr[0][s][c] = 0;
    phi_arr[0][0][0] = 1;
    for(int k = 1; k <= K; ++k) {
        for(int s = 0; s <= S; ++s) {
            for(int c = 0; c < M; ++c) {
                phi_arr[k][s][c] = 0;
                for(int d = 0; d < 10; ++d) {
                    int k1 = k - 1;
                    int s1 = s - d;
                    int c1 = (c - d * pow10(k-1) + 10 * M) % M;
                    if(s1 >= 0) phi_arr[k][s][c] += phi_arr[k1][s1][c1];
                    if(phi_arr[k][s][c] > INF) phi_arr[k][s][c] = INF;
                }
            }
        }
    }
}


// phi(k, s, c) = liczba takich 0 <= x < 10^k, że x = c (mod M) a suma cyfr x jest równa s
// 0 <= k <= K, 0 <= s <= S, 0 <= c < M
inline u64 phi(int k, int s, int c) {
    return phi_arr[k][s][c];
}

// psi(k, s, c, d) = liczba takich x, że d*10^k <= x < (d+1)*10^k, x = c (mod M) a suma cyfr x jest równa s
// 0 <= k <= K, 0 <= s <= S, 0 <= c < M, 0 <= d < 10
u64 psi(int k, int s, int c, int d) {
    if(s - d < 0) return 0;
    else return phi(k, s - d, (c - d*pow10(k) + 10*M) % M);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> S >> M >> q;
    K = 200;
    pow10_init();
    phi_init();

    while(q--) {
        u64 x;
        int s, c;
        char ans[MAX_K] = {};
        bool nie = false;

        cin >> x;
        s = S, c = 0;
        for(int k = K-1; k >= 0; --k) {
            int y = 0, D = -1;
            for(int d = 0; d <= 9; ++d) {
                int inc = psi(k, s, c, d);
                if(y + inc >= x) {
                    s -= d;
                    c = (c - d*pow10(k) + 10*M) % M;
                    x -= y;
                    D = d;
                    break;
                } else y += inc;
            }
            if(D == -1) nie = true;
            ans[k] = D;
            //cout << D << " ";
        }

        //nie = false; // !!!
        if(nie) cout << "NIE\n";
        else {
            int len = K;
            while(ans[len-1] == 0) len--;
            reverse(ans, ans + len);
            for(int i = 0; i < len; ++i) ans[i] += '0';
            ans[len] = 0;
            cout << ans << "\n";
        }
    }

    return 0;
}
