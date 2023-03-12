/* Jan Zakrzewski
   XXX Olimpiada Informatyczna, Etap I
   Zadanie `Gang biciaków (gan)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+20;
constexpr int M = 1.5e5+20;
int n, m, z;
vector<int> neighbors[N];
tuple<int, int, int> edges[N];
int edge_to_vertex[N];
int root;
int parent[N];
vector<int> children[N];
queue<int> Queue;
bool visited[N];
int biciak[N]; // biciak[u] = jaki biciak jest sprzedawany na drodze pomiędzy wierzchołkiem u a jego rodzicem
int ile_biciaka[M]; // ile_biciaka[c] = ile jest na razie biciaka rodzaju c
int answer[N];

int main() {

    cin >> n >> m >> z;
    for(int i = 1; i <= n-1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = make_tuple(u, v, c);
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    root = 1;
    Queue.push(root);
    for(int u = 1; u <= n; ++u) visited[u] = false;
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
    parent[root] = -1;

    for(int i = 1; i <= n-1; ++i) {
        int u = get<0>(edges[i]);
        int v = get<1>(edges[i]);
        int c = get<2>(edges[i]);

        if(parent[u] == v) edge_to_vertex[i] = u;
        else edge_to_vertex[i] = v;

        biciak[edge_to_vertex[i]] = c;
    }


    for(int c = 1; c <= m; ++c) ile_biciaka[c] = 0;
        

    return 0;
}
