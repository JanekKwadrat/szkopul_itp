/*  Jan Zakrzewski
    XIX Olimpiada Informatyczna, Etap II
    Zadanie `Tour de Bajtocja (tou)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
int n, m, k;
vector<int> neighbors[N];

int Family[N];
int Size[N];
void Start() {
    for(int u = 1; u <= n; ++u) {
        Family[u] = u;
        Size[u] = 1;
    }
}
int Find(int u) {
    int u0 = u;
    while(Family[u] != u)
        u = Family[u];
    while(u0 != u) {
        int u1 = Family[u0];
        Family[u0] = u;
        u0 = u1;
    }
    return u;
}
void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(Size[u] < Size[v]) swap(u, v);
    Size[u] += Size[v];
    Family[v] = u;
}

vector<pair<int, int>> answer;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    Start();

    for(int u = n; u > k; --u) {
        for(int v : neighbors[u]) {
            if(v <= k) continue;
            Union(u, v);
        }
    }

    for(int u = k; u >= 1; --u) {
        for(int v : neighbors[u]) {
            if(v <= u) continue;
            if(Find(u) == Find(v)) answer.push_back(make_pair(u, v));
            else Union(u, v);
        }
    }

    cout << answer.size() << "\n";
    for(auto el : answer) cout << el.first << " " << el.second << "\n";

    return 0;
}
