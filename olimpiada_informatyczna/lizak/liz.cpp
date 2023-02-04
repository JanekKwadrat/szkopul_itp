/*  Jan Zakrzewski
    XVIII Olimpiada Informatyczna, Etap I
    Zadanie `Lizak (liz)' */

#include <bits/stdc++.h>
using namespace std;

// waniliowy - 1 bajtalar
// truskawkowy - 2 bajtalary

constexpr int N = 1e6 + 20;
int n, m;
char lizak[N];
int sum[N];
pair<int, int> ans[2*N];

void add(int l, int r) {
    if(l > r) return;
    if(l < 1 || r < 1) return;
    if(l > n || r > n) return;
    int s = sum[r] - sum[l-1];
    ans[s] = make_pair(l, r);
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    cin >> lizak+1;

    for(int i = 1; i <= n; ++i) {
        switch(lizak[i]) {
            case 'W': lizak[i] = 1; break;
            case 'T': lizak[i] = 2; break;
        }
    }

    sum[0] = 0;
    for(int i = 1; i <= n; ++i)
        sum[i] = sum[i-1] + lizak[i];

    for(int i = 1; i <= 2*n; ++i) ans[i] = make_pair(-1, -1);

    int p = 0, q = 0;
    for(int i = 1; i <= n; ++i) if(lizak[i] == 1) { p = i; break; }
    for(int i = n; i >= 1; --i) if(lizak[i] == 1) { q = i; break; }

    for(int i = p; i <= n; ++i) add(p, i);
    for(int i = p; i <= n; ++i) add(p+1, i);

    for(int i = q; i >= 1; --i) add(i, q);
    for(int i = q; i >= 1; --i) add(i, q-1);

    for(int i = 1; i < p; ++i) add(i, n);
    for(int i = n; i > q; --i) add(0, i);

    while(m--) {
        int k;
        cin >> k;
        
        if(k <= 2*n && ans[k].first != -1) cout << ans[k].first << " " << ans[k].second << "\n";
        else cout << "NIE\n";
    }

    return 0;
}
