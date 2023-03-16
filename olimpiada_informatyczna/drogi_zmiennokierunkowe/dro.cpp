/* Jan Zakrzewski
   XXIII Olimpiada Informatyczna, Etap II
   Zadanie `Drogi zmiennokierunkowe (dro)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'000 + 20;
int n, m;
vector<int> droga_out[N];
vector<int> droga_in[N];
vector<int> topo;
bool visited[N];
int naj_out[N]; // naj_out[u] = jakie jest największe i takie, że do wierzchołka u da się dojść z każdego z wierzchołków topo[1], topo[2], ..., topo[i] za pomocą dróg droga_out[]
int naj_in[N]; // naj_in[u] = jakie jest najmniejsze i takie, że do wierzchołka u da się dojść z każdego z wierzchołków topo[i], topo[i+1] ..., topo[n] za pomocą dróg droga_in[]
bool ok[N];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        droga_out[u].push_back(v);
        droga_in[v].push_back(u);
    }

    function<void(int)> Topo = [&](int u) {
        if(visited[u]) return;
        visited[u] = true;
        for(int v : droga_out[u]) Topo(v);
        topo.push_back(u);
    };
    for(int u = 1; u <= n; ++u) visited[u] = false;
    for(int u = 1; u <= n; ++u) Topo(u);
    reverse(topo.begin(), topo.end());

    for(int u : topo) cout << u << " "; cout << "\n";

    for(int u = 1; u <= n; ++u) ok[u] = true;

    for(int u = 1; u <= n; ++u) naj_out[u] = 0;
    for(int u : topo) {
        if(topo[naj_out[u]+1 -1] == u) naj_out[u]++;
        else ok[u] = false;
        cout << u << " " << naj_out[u] << "\n";
        for(int v : droga_out[u]) {
            naj_out[v] = max(naj_out[v], naj_out[u]);
            if(topo[naj_out[v]+1 -1] == u) naj_out[v]++;
        }
    }
    reverse(topo.begin(), topo.end());
    for(int u = 1; u <= n; ++u) naj_in[u] = 0;
    for(int u : topo) {
        if(topo[naj_in[u]+1 -1] == u) naj_in[u]++;
        else ok[u] = false;
        cout << u << " " << naj_in[u] << "\n";
        for(int v : droga_in[u]) {
            naj_in[v] = min(naj_in[v], naj_in[u]);
            if(topo[naj_in[v]+1 -1] == u) naj_in[v]++;
        }
    }
    //reverse(topo.begin(), topo.end());

    for(int u = 1; u <= n; ++u) {
        if(ok[u])
            ans.push_back(u);
    }

    cout << ans.size() << "\n";
    for(int u : ans) cout << u << " ";
    cout << "\n";

    return 0;
}