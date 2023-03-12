/* Jan Zakrzewski
   XXV Olimpiada Informatyczna, Etap II
   Zadanie `Przelewy (prz)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
int n;
int x[N];
vector<int> neighbors[N];

long long star[N];
long long Min;
bool yes;
unsigned long long ans;

int root;
int parent[N];
vector<int> children[N];

bool visited[N];
queue<int> Queue;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n; ++i) { int y; cin >> y; x[i] -= y; }
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    for(int u = 1; u <= n; ++u) visited[u] = false;
    root = (n / 4 + n / 5 + 3 * n / 2 + 17) % n + 1;
    Queue.push(root);
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        visited[u] = true;
        for(int v : neighbors[u]) {
            if(visited[v]) parent[u] = v;
            else {
                children[u].push_back(v);
                Queue.push(v);
            }
        }
    }

    function<long long(int)> Sum = [&](int u)->long long {
        if(!visited[u]) {
            star[u] = x[u];
            for(int v : children[u]) star[u] += Sum(v);
        }
        return star[u]; 
    };
    for(int u = 1; u <= n; ++u) visited[u] = false;
    Sum(root);

    //for(int u = 1; u <= n; ++u) cout << star[u] << " "; cout << "\n";

    function<long long(int)> Upd = [&](int u)->long long {
        if(!visited[u]) {
            if(u != root)
                star[u] += Upd(parent[u]);
        }
        return star[u];
    };
    for(int u = 1; u <= n; ++u) visited[u] = false;
    for(int u = 1; u <= n; ++u) Upd(u);

    yes = star[root] == 0;
    ans = 0;
    Min = star[1];
    for(int u = 2; u <= n; ++u) Min = min(Min, star[u]);
    for(int u = 1; u <= n; ++u) ans += star[u] - Min;

    //for(int u = 1; u <= n; ++u) cout << star[u] << " "; cout << "\n";

    //for(int u = 1; u <= n; ++u) star[u] -= Min;
    //for(int u = 1; u <= n; ++u) cout << star[u] << " "; cout << "\n";

    /*for(int u = 1; u <= n; ++u) {
        x[u] -= star[u] * neighbors[u].size();
        for(int v : neighbors[u])  x[v] += star[u];
    }
    for(int u = 1; u <= n; ++u) cout << x[u] << " "; cout << "\n";

    cout << "root = " << root << "\n";
    for(int u = 1; u <= n; ++u) {
        cout << u << ": { ";
        for(int v : children[u]) cout << v << " ";
        cout << "}\n";
    }*/

    if(yes) cout << "TAK\n" << ans << "\n";
    else cout << "NIE\n";

    return 0;
}

/*
11
4 3 5 6 -2 -4 3 -7 -5 -1 -2
0 0 0 0 0 0 0 0 0 0 0
10 1
1 2
2 4
1 11
2 3
3 5
3 7
3 6
6 8
6 9
*/
