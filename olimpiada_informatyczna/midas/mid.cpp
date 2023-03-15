/* Jan Zakrzewski
   XXIV Olimpiada Informatyczna, Etap III
   Zadanie `Midas (mid)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'000 + 50;
int n, z;
int root;
int l[N], r[N];
int D;
int dukaty[N];

queue<vector<int>> Queue;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int u = 1; u <= n; ++u) cin >> l[u] >> r[u];
    root = 1;

    for(int u = 1; u <= n; ++u) dukaty[u] = -1;

    do {
        int u = root;
        vector<int> U;
        while(true) {
            dukaty[u] = 0;
            if(r[u] != 0) U.push_back(r[u]);
            u = l[u];
            if(u == 0) break;
        }
        Queue.push(U);
        D = 0;
    } while(false);

    while(Queue.size() > 0) {
        vector<int> U = Queue.front();
        Queue.pop();
        vector<int> L, R;
        D++;
        for(int u : U) {
            dukaty[u] = D;
            if(l[u] != 0) L.push_back(l[u]);
            if(r[u] != 0) R.push_back(r[u]);
        }
        if(L.size() > 0) Queue.push(L);
        if(R.size() > 0) Queue.push(R);
    }

    cin >> z;
    while(z--) {
        int x, y;
        cin >> x >> y;
        if(dukaty[x] >= dukaty[y]) cout << "TAK\n";
        else cout << "NIE\n";
    }

    return 0;
}
