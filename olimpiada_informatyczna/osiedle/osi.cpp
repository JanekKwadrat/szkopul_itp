/* Jan Zakrzewski
   XXVI Olimpiada Informatyczna, Etap II
   Zadanie `Osiedla (osi)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
int n, m;
vector<pair<int, int>> neighbors[N];
set<pair<int, int>> edges;
char direction[N];
bool visited[N];
vector<int> L;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(make_pair(v, i));
        neighbors[v].push_back(make_pair(u, i));
        direction[i] = 1;
        if(u > v) direction[i] *= -1;
        if(edges.count(make_pair(u, v)) > 0) direction[i] *= -1;
    }

    function<void(int, int)> DFS = [&](int u, int e) {
        if(visited[u]) return;
        visited[u] = true;
        for(auto el : neighbors[u]) {
            int v = el.first;
            int f = el.second;
            if(e == f) continue;
            if(u > v) direction[f] *= -1;
            DFS(v, f);
        }
    };
    for(int u = 1; u <= n; ++u) visited[u] = false;
    for(int u = 1; u <= n; ++u) DFS(u);

    return 0;
}
