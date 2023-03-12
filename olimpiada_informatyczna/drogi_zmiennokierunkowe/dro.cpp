/* Jan Zakrzewski
   XXIII Olimpiada Informatyczna, Etap II
   Zadanie `Drogi zmiennokierunkowe (dro)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 20;
int n, m;
vector<int> out_neighbors[N];
vector<int> in_neighbors[N];

vector<int> topological;
bool visited[N];
int family[N];
int Count[N];

int ile;
bool ok[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        out_neighbors[u].push_back(v);
        in_neighbors[v].push_back(u);
    }

    for(int u = 1; u <= n; ++u) {
        out_neighbors[u].push_back(n+1);
        in_neighbors[n+1].push_back(u);

        out_neighbors[n+2].push_back(u);
        in_neighbors[u].push_back(n+2);
    }
    n += 2;

    function<void(int)> DFS = [&](int u) {
        if(visited[u]) return;
        visited[u] = true;
        for(int v : out_neighbors[u]) DFS(v);
        topological.push_back(u);
    };
    for(int u = 1; u <= n; ++u) visited[u] = false;
    for(int u = 1; u <= n; ++u) DFS(u);
    reverse(topological.begin(), topological.end());

    function<void(int, int)> Assign = [&](int u, int r) {
        if(family[u] != -1) return;
        family[u] = r;
        for(int v : in_neighbors[u]) Assign(v, r);
    };
    for(int u = 1; u <= n; ++u) family[u] = -1;
    for(int u : topological) Assign(u, u);

    /// !!!
    for(int u : topological) cout << u << " "; cout << "\n";

    for(int u = 1; u <= n; ++u) ok[u] = true;

    for(int u = 1; u <= n; ++u) Count[u] = 0;
    for(int u = 1; u <= n; ++u) {
        for(int v : out_neighbors[u]) {
            if(family[u] == family[v]) continue;
            Count[family[v]]++;
        }
    }
    for(int i = 0; i < n; ++i) {
        int u = topological[i], u1;
        if(i+1 < n) u1 = topological[i+1];
        else u1 = -1;
        for(int v : out_neighbors[u]) {
            if(family[u] == family[v]) continue;
            Count[family[v]]--;
            if(Count[family[v]] == 0) {
                if(family[v] != family[u1]) ok[family[v]] = false;
            }
        }
    }
    
    for(int u = 1; u <= n; ++u) Count[u] = 0;
    for(int u = 1; u <= n; ++u) {
        for(int v : in_neighbors[u]) {
            if(family[u] == family[v]) continue;
            Count[family[v]]++;
        }
    }
    for(int i = n-1; i >= 0; --i) {
        int u = topological[i], u1;
        if(i-1 >= 0) u1 = topological[i-1];
        else u1 = -1;
        for(int v : in_neighbors[u]) {
            if(family[u] == family[v]) continue;
            Count[family[v]]--;
            if(Count[family[v]] == 0) {
                if(family[v] != family[u1]) ok[family[v]] = false;
            }
        }
    }

    //for(int u = 1; u <= n; ++u) ok[family[u]] = ok[family[u]] || ok[u];
    //for(int u = 1; u <= n; ++u) ok[u] = ok[family[u]] || ok[u];

    ile = 0;
    for(int u = 1; u <= n; ++u) if(ok[family[u]]) ile++;
    
    cout << ile-2 << "\n";
    for(int u = 1; u <= n-2; ++u) if(ok[family[u]]) cout << u << " ";
    cout << "\n";

    return 0;
}
