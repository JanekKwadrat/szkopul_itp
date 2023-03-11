/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap II
   Zadanie `Rajd (raj)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'000 + 100;
int n, m;
vector<int> ulica_fw[N];
int ile[N];
pair<int, int> odp;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        ulica_fw[u].push_back(v);
    }
    
    function<int(int, int)> Ile = [&](int u, int A)->int {
        if(u == A) ile[u] = -1;
        if(ile[u] != -1) return ile[u];
        ile[u] = 0;
        for(int v : ulica_fw[u]) {
            if(v == A) continue;
            ile[u] = max(ile[u], Ile(v, A) + 1);
        }
        return ile[u];
    };

    odp = make_pair(INT32_MAX, -1);
    for(int A = 1; A <= n; ++A) {
        fill(ile+1, ile+1+n, -1);
        int odp1 = 0;
        for(int u = 1; u <= n; ++u) if(u != A) odp1 = max(odp1, Ile(u, A));
        odp = min(odp, make_pair(odp1, A));
    }

    cout << odp.second << " " << odp.first << "\n";

    return 0;
}
