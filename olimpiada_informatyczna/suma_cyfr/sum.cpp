/*  Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap II
    Zadanie Suma cyfr (sum)
    Rozwiązanie w złożoności O(K*S*M + q*K*10) */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;

constexpr int MAX_K = 200;
constexpr int MAX_S = 200;
constexpr int MAX_M = 200;
constexpr u64 INF = 1e18 + 100;

int K, S, M, q;

int __pow10_arr[MAX_K];
inline int pow10(int k) {
    return __pow10_arr[k];
}
void __pow10_init() {
    __pow10_arr[0] = 1;
    for(int k = 1; k < K; ++k)
        __pow10_arr[k] = __pow10_arr[k-1] * 10 % M;
}

u64 __phi_arr[MAX_K][MAX_S+1][MAX_M];
inline u64 phi(int k, int s, int c) {
    return __phi_arr[k][s][c];
}
void __phi_init() {
    for(int s = 0; s <= S; ++s)
        for(int c = 0; c < M; ++c)
            __phi_arr[0][s][c] = 0;
    __phi_arr[0][0][0] = 1;
    for(int k = 1; k < K; ++k) {
        for(int s = 0; s <= S; ++s) {
            for(int c = 0; c < M; ++c) {
                __phi_arr[k][s][c] = 0;
                for(int d = 0; d <= 9; ++d) {
                    int k1 = k - 1;
                    int s1 = s - d;
                    int c1 = (c - d * pow10(k-1) + 10 * M) % M;
                    if(s - d < 0) continue;
                    __phi_arr[k][s][c] += __phi_arr[k1][s1][c1];
                }
                if(__phi_arr[k][s][c] > INF) __phi_arr[k][s][c] = INF;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> S >> M >> q;
    K = 200;
    __pow10_init();
    __phi_init();

    while(q--) {
        u64 J;
        int s, c;
        bool ok = true;
        char ans[MAX_K+1];

        cin >> J;
        s = S, c = 0;

        for(int k = K-1; k >= 0; --k) {
            u64 y = 0;
            int D = -1;
            for(int d = 0; d <= 9; ++d) {
                u64 inc = (u64)(s - d >= 0) * phi(k, s - d, (c - d*pow10(k) + 10*M) % M);
                if(y + inc >= J) {
                    J -= y;
                    s -= d;
                    c = (c - d*pow10(k) + 10*M) % M;
                    D = d;
                    break;
                } else y += inc;
            }
            if(D == -1) ok = false;
            else ans[k] = D;
        }

        if(!ok) cout << "NIE\n";
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