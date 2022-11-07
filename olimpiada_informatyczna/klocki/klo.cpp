/*
    Jan Zakrzewski
    XVII Olimpiada Informatyczna, Etap II
    Rozwiązanie zadania Klocki (kol)
    Złożoność czasowa: O(n * m)
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'020;
constexpr long long INF = 2.5e18;
int n, m;
long long k;
long long x[N];
long long sum[N];
long long best[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> x[i];

    while(m--) {
        cin >> k;

        long long S = 0;
        for(int i = 0; i <= n; ++i) {
            sum[i] = S;
            S += x[i] - k;
        }
        
        long long M = -INF;
        for(int i = n; i >= 0; --i) {
            best[i] = M;
            M = max(M, sum[i]);
        }

        //for(int i = 0; i <= n; ++i) cout << sum[i] << " "; cout << "\n";
        //for(int i = 0; i <= n; ++i) cout << best[i] << " "; cout << "\n";

        int p = 0, q = 0;
        int answer = 0;

        while(true) {
            while(best[q] >= sum[p]) q++;
            if(sum[q] - sum[p] >= 0) answer = max(answer, q - p);
            if(q >= n) break;
            if(p <= q) p++, q++;
        }

        cout << answer << " ";
    }
    cout << "\n";

    return 0;
}