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

constexpr int RED = 1, BLUE = 2;
i64 red[N], blue[N];
int red_dir[N], blue_dir[N];
i64 W;
int g, t;
vector<int> path;
int k;

int main() {

    vector<int> vect(100*N);

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
        //for(int v : children[u]) Visit(v);
        
        // compute red[u]
        red[u] = w[u];
        red_dir[u] = -1;
        for(int v : children[u]) {
            if(w[u] + blue[v] > red[u]) {
                red[u] = w[u] + blue[v];
                red_dir[u] = v;
            }
        }

        // compute blue[u]
        blue[u] = 0;
        blue_dir[u] = -1;
        for(int v : children[u]) {
            if(red[v] - w[v] > blue[u]) {
                blue[u] = red[v] - w[v];
                blue_dir[u] = v;
            }
        }
        for(int v : children[u]) blue[u] += w[v];
    };
    //Visit(root);
    int Visited[N];
    for(int u = 1; u <= n; ++u) {
        Visited[u] = children[u].size();
        if(Visited[u] == 0) my_queue.push(u);
    }

    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        Visit(u);
        if(u == root) continue;
        Visited[parent[u]]--;
        if(Visited[parent[u]] == 0) my_queue.push(parent[u]);
    }

    W = 0, g = -1, t = -1;
    for(int u = 1; u <= n; ++u) {
        //u = 2;
        int v1, v2;

        //cout << u << " ";

        i64 Red = w[u];
        v1 = -1, v2 = -1;
        for(int v : children[u]) if(v1 == -1 || blue[v] > blue[v1]) v1 = v;
        for(int v : children[u]) if(v != v1 && (v2 == -1 || blue[v] > blue[v2])) v2 = v;
        if(v1 != -1) Red += blue[v1];
        if(v2 != -1) Red += blue[v2];
        if(Red > W) {
            W = Red;
            g = u;
            t = RED;
        }
        
        //cout << Red << " ";

        i64 Blue = 0;
        v1 = -1, v2 = -1;
        for(int v : children[u]) if(v1 == -1 || red[v] - w[v] > red[v1] - w[v1]) v1 = v;
        for(int v : children[u]) if(v != v1 && (v2 == -1 || red[v] - w[v] > red[v2] - w[v2])) v2 = v;
        if(v1 != -1) Blue += red[v1] - w[v1];
        if(v2 != -1) Blue += red[v2] - w[v2];
        for(int v : children[u]) Blue += w[v];
        if(u != root) Blue += w[parent[u]];
        //W = max(W, Blue);
        if(Blue > W) {
            //cout << Blue << " ";
            W = Blue;
            g = u;
            t = BLUE;
        }
        
        //cout << Blue << " ";
        //cout << W << "\n";

        //break;
    }
    //cout << "\n";
    
    //for(int u = 1; u <= n; ++u) cout << red[u] << " "; cout << "\n";
    //for(int u = 1; u <= n; ++u) cout << blue[u] << " "; cout << "\n";

    if(t == RED) {
        path.push_back(g);
        int v1, v2;

        v1 = -1, v2 = -1;
        for(int v : children[g]) if(v1 == -1 || blue[v] > blue[v1]) v1 = v;
        for(int v : children[g]) if(v != v1 && (v2 == -1 || blue[v] > blue[v2])) v2 = v;

        if(v1 != -1) {
                int u = v1, next_u;

            while(true) {

                // you are blue now
                next_u = blue_dir[u];
                for(int v : children[u]) {
                    if(v == next_u) continue;
                    path.push_back(u);
                    path.push_back(v);
                }
                if(next_u == -1) break;

                path.push_back(u);
                path.push_back(next_u);

                u = next_u;

                // you are red now
                next_u = red_dir[u];

                if(next_u == -1) break;
                u = next_u;
            }
        }

        reverse(path.begin(), path.end());

        if(v2 != -1) {
                int u = v2, next_u;

            while(true) {

                // you are blue now
                next_u = blue_dir[u];
                for(int v : children[u]) {
                    if(v == next_u) continue;
                    path.push_back(u);
                    path.push_back(v);
                }
                if(next_u == -1) break;

                path.push_back(u);
                path.push_back(next_u);

                u = next_u;

                // you are red now
                next_u = red_dir[u];

                if(next_u == -1) break;
                u = next_u;
            }
        }
    } else if(t == BLUE) {
        int v1, v2;
        v1 = -1, v2 = -1;
        for(int v : children[g]) if(v1 == -1 || red[v] - w[v] > red[v1] - w[v1]) v1 = v;
        for(int v : children[g]) if(v != v1 && (v2 == -1 || red[v] - w[v] > red[v2] - w[v2])) v2 = v;

        for(int u : children[g]) {
            if(u == v1 || u == v2) continue;
            path.push_back(g);
            path.push_back(u);
        }
        if(g != root) {
            path.push_back(g);
            path.push_back(parent[g]);
        }

        if(v1 != -1) {
            path.push_back(g);
            path.push_back(v1);

            int u = v1, next_u;
            
            while(true) {

                // you are red now
                next_u = red_dir[u];

                if(next_u == -1) break;
                u = next_u;

                // you are blue now
                next_u = blue_dir[u];
                for(int v : children[u]) {
                    if(v == next_u) continue;
                    path.push_back(u);
                    path.push_back(v);
                }
                if(next_u == -1) break;

                path.push_back(u);
                path.push_back(next_u);

                u = next_u;
            }
        }

        reverse(path.begin(), path.end());
        path.pop_back();

        if(v2 != -1) {
            path.push_back(g);
            path.push_back(v2);

            int u = v2, next_u;
            
            while(true) {

                // you are red now
                next_u = red_dir[u];

                if(next_u == -1) break;
                u = next_u;

                // you are blue now
                next_u = blue_dir[u];
                for(int v : children[u]) {
                    if(v == next_u) continue;
                    path.push_back(u);
                    path.push_back(v);
                }

                if(next_u == -1) break;

                path.push_back(u);
                path.push_back(next_u);

                u = next_u;
            }
        }
    }

    k = path.size() / 2 + 1;

    cout << W << "\n" << k << "\n";
    for(int u : path) cout << u << " ";
    cout << "\n";

    return 0;
}
