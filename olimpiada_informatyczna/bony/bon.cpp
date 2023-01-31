/*  Jan Zakrzewski
    XIX Olimpiada Informatyczna, Etap II
    Zadanie `Bony (bon)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
int m, n;
int a[N];
bool candy[N] = {};
bool taken[N] = {};
vector<long long> ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m;
    for(int i = 1; i <= m; ++i) {
        int b;
        cin >> b;
        candy[b] = true;
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    long long s = 0;
    for(int i = 1; i <= n; ++i) {

        int p = 0;
        for(int j = 1; j <= a[i]; ++j) {
            do p += a[i]; while(p < N && taken[p]);
            if(p >= N) break;
            if(candy[p]) ans.push_back(s + j);
            taken[p] = true;
        }

        s += a[i];
    }

    cout << ans.size() << "\n";
    for(int x : ans) cout << x << "\n";

    return 0;
}
