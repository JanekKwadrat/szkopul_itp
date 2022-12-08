/*  Jan Zakrzewski
    XXV Olimpiada Informatyczna, Etap II
    Zadanie Drogi rowerowe (dro) */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e4 + 20;
int n, m;
vector<int> out_neighbor[N];
vector<int> in_neighbor[N];
bool visited[N];
int family[N];
int family_size[N];
vector<int> L;
set<int> out_family_neighbor[N];
int ans[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        out_neighbor[a].push_back(b);
        in_neighbor[b].push_back(a);
    }

    for(int u = 1; u <= n; ++u) visited[u] = false;
    for(int u = 1; u <= n; ++u) family[u] = -1;

    function<void(int)> Visit = [&](int u) {
        if(visited[u]) return;
        visited[u] = true;
        for(int v : out_neighbor[u])
            if(!visited[v]) Visit(v);
        L.push_back(u);
    };
    for(int u = 1; u <= n; ++u) Visit(u);
    reverse(L.begin(), L.end());

    function<void(int, int)> Assign = [&](int u, int r) {
        if(family[u] != -1) return;
        family[u] = r;
        for(int v : in_neighbor[u])
            Assign(v, r);
    };
    for(int u : L) Assign(u, u);

    for(int u = 1; u <= n; ++u) family_size[u] = 0;
    for(int u = 1; u <= n; ++u) family_size[family[u]]++;

    for(int u = 1; u <= n; ++u) {
        for(int v : out_neighbor[u]) {
            if(family[u] == family[v]) continue;
            out_family_neighbor[family[u]].insert(family[v]);
        }
    }
    for(int u = 1; u <= n; ++u) ans[u] = -1;

    function<int(int)> Answer = [&](int u)->int {
        if(ans[u] != -1) return ans[u];
        ans[u] = family_size[family[u]] - 1;
        for(int v : out_family_neighbor[u]) ans[u] += Answer(v) + 1;
        return ans[u];
    };
    for(int u = 1; u <= n; ++u) Answer(u);

    for(int u = 1; u <= n; ++u) cout << ans[family[u]] << "\n";

    return 0;
}