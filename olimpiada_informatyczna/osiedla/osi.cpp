/* Jan Zakrzewski
   XXVI Olimpiada Informatyczna, Etap II
   Zadanie `Osiedla (osi)' */

#include <bits/stdc++.h>
using namespace std;

template <typename T> inline int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

constexpr int N = 1'000'000 + 20;
int n, m;
vector<pair<int, int>> droga[N];
int zwrot[N];
bool visited[N] = {};
bool traversed[N] = {};
vector<int> L;
int family[N];
int ans;
char str[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        droga[u].push_back(make_pair(v, i));
        droga[v].push_back(make_pair(u, -i));
        zwrot[i] = 1;
    }

    function<void(int)> Visit = [&](int u) {
        if(visited[u]) return;
        visited[u] = true;
        for(pair<int, int> elm : droga[u]) {
            int v = elm.first;
            int i = elm.second;
            if(traversed[abs(i)]) continue;
            traversed[abs(i)] = true;
            zwrot[abs(i)] *= sgn(i);
            if(!visited[v]) Visit(v);
        }
        L.push_back(u);
    };
    for(int u = 1; u <= n; ++u) Visit(u);
    reverse(L.begin(), L.end());
    
    function<void(int, int)> Assign = [&](int u, int root) {
        if(family[u] != -1) return;
        family[u] = root;
        for(pair<int, int> elm : droga[u]) {
            int v = elm.first;
            int i = elm.second;
            if(sgn(i) * zwrot[abs(i)] != -1) continue;
            Assign(v, root);
        }
    };
    for(int u = 1; u <= n; ++u) family[u] = -1;
    for(int u : L) Assign(u, u);

    ans = 0;
    for(int u = 1; u <= n; ++u) {
        if(family[u] == u)
            ans++;
    }

    for(int i = 1; i <= m; ++i) {
        if(zwrot[i] == 1) str[i-1] = '>';
        else str[i-1] = '<';
    }
    str[m] = 0;

    cout << ans << "\n" << str << "\n";

    return 0;
}