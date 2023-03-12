/*  Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap II
    Zadanie Przelewy (prz) */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
constexpr int N = 1e6 + 20;
int n;
int x[N];
i64 s[N], c[N], z;
bool yes;
i64 ans;

int parent[N];
vector<int> children[N];
vector<int> neighbor[N];
bool visited[N] = {};
queue<int> my_queue;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int u = 1; u <= n; ++u) cin >> x[u];
    for(int u = 1; u <= n; ++u) {
        int y;
        cin >> y;
        x[u] -= y;
    }

    for(int i = 1; i <= n-1; ++i) {
        int a, b;
        cin >> a >> b;
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }
    for(int u = 1; u <= n; ++u) neighbor[u].shrink_to_fit();

    my_queue.push(1);
    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        visited[u] = true;
        for(int v : neighbor[u]) {
            if(visited[v]) parent[u] = v;
            else {
                children[u].push_back(v);
                my_queue.push(v);
            }
        }
    }
    for(int u = 1; u <= n; ++u) children[u].shrink_to_fit();

    for(int u = 1; u <= n; ++u) s[u] = -1;
    function<int(int)> __s = [&](int u)->int {
        if(s[u] != -1) return s[u];
        s[u] = x[u];
        for(int v : children[u]) s[u] += __s(v);
        return s[u];
    };
    for(int u = 1; u <= n; ++u) __s(u);
    
    c[1] = 0;
    for(int u = 2; u <= n; ++u) c[u] = -1;
    function<int(int)> __c = [&](int u)->int {
        if(c[u] != -1) return c[u];
        c[u] = s[u] + __c(parent[u]);
        return c[u];
    };
    for(int u = 1; u <= n; ++u) __c(u);

    z = 0;
    for(int u = 1; u <= n; ++u) z = min(z, c[u]);
    z *= -1;
    for(int u = 1; u <= n; ++u) c[u] += z;
    
    for(int u = 1; u <= n; ++u) {
        x[u] -= c[u] * (i64)neighbor[u].size();
        for(int v : neighbor[u]) x[v] += c[u];
    }

    yes = true;
    for(int u = 1; u <= n; ++u) if(x[u] != 0) yes = false;

    if(!yes) cout << "NIE\n";
    else {
        ans = 0;
        for(int u = 1; u <= n; ++u) ans += c[u];
        cout << "TAK\n";
        cout << ans << "\n";
    }

    return 0;
}
