/* Jan Zakrzewski
   XXVII Olimpiada Informatyczna, Etap II
   Zadanie `Wakacje Bajtazara (wak)' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
constexpr int N = 1e6 + 10;

int n;
i64 w[N];
vector<int> neighbors[N];

int root;
int parent[N];
vector<int> children[N];

bool visited[N];
queue<int> my_queue;

i64 red[N], blue[N];
i64 W;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int u = 1; u <= n; ++u) cin >> w[u];
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    for(int u = 1; u <= n; ++u) visited[u] = false;
    root = 1;
    my_queue.push(root);
    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        visited[u] = true;
        for(int v : neighbors[u]) {
            if(visited[v]) parent[u] = v;
            else {
                children[u].push_back(v);
                my_queue.push(v);
            }
        }
    }

    function<void(int)> Visit = [&](int u) {
        for(int v : children[u]) Visit(v);
        
        // compute red[u]
        red[u] = w[u];
        for(int v : children[u])
            red[u] = max(red[u], w[u] + blue[v]);

        // compute blue[u]
        blue[u] = 0;
        for(int v : children[u])
            blue[u] = max(blue[u], red[v] - w[v]);
        for(int v : children[u])
            blue[u] += w[v];
    };
    Visit(root);

    W = 0;
    for(int u = 1; u <= n; ++u) {
        //u = 2;

        W = max(W, red[u]);
        W = max(W, blue[u]);
        int v1, v2;

        //cout << u << " ";

        i64 Red = w[u];
        v1 = -1, v2 = -1;
        for(int v : children[u]) if(v1 == -1 || blue[v] > blue[v1]) v1 = v;
        for(int v : children[u]) if(v != v1 && (v2 == -1 || blue[v] > blue[v2])) v2 = v;
        if(v1 != -1 && v2 != -1) Red += blue[v1] + blue[v2];
        W = max(W, Red);
        //cout << Red << " ";

        i64 Blue = 0;
        v1 = -1, v2 = -1;
        for(int v : children[u]) if(v1 == -1 || red[v] - w[v] > red[v1] - w[v1]) v1 = v;
        for(int v : children[u]) if(v != v1 && (v2 == -1 || red[v] - w[v] > red[v2] - w[v2])) v2 = v;
        if(v1 != -1 && v2 != -1) {
            Blue += (red[v1] - w[v1]) + (red[v2] - w[v2]);
            for(int v : children[u]) Blue += w[v];
        }
        //cout << v1 << " " << v2 << "\n";
        if(u != root) Blue += w[parent[u]];
        W = max(W, Blue);
        //cout << Blue << " ";
        //cout << W << "\n";

        //break;
    }
    
    //for(int u = 1; u <= n; ++u) cout << red[u] << " "; cout << "\n";
    //for(int u = 1; u <= n; ++u) cout << blue[u] << " "; cout << "\n";

    cout << W << "\n";

    return 0;
}
