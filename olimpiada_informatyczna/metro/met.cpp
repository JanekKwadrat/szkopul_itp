/* Jan Zakrzewski
   XXVI Olimpiada Informatyczna, Etap III
   Zadanie `Metro (met)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e6 + 20;
int n, k;
vector<int> neighbors[N];

int leaf[N]; // leaf[u] = odległość od wierzchołka u do najbliższego liścia
vector<int> anty[N]; // anty[x] = wszystkie u takie, że leaf[u] = x

int root; // root = korzen drzewa
int parent[N];
//vector<int> children[N];

queue<int> my_queue;
bool visited[N];

bool krancowy[N];
int irytacja, krancowych;

int main() {
    
    cin >> n >> k;
    for(int i = 1; i <= n-1; ++i) {
        int a, b;
        cin >> a >> b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
	}

    for(int u = 1; u <= n; ++u) {
        leaf[u] = -1;
        if(neighbors[u].size() == 1) {
            leaf[u] = 0;
            my_queue.push(u);
        }
    }
    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        for(int v : neighbors[u]) {
            if(leaf[v] == -1)
                leaf[v] = leaf[u] + 1;
        }
        root = u;
    }

    for(int u = 1; u <= n; ++u) visited[u] = false;
    my_queue.push(root);
    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        visited[u] = true;
        for(int v : neighbors[u]) {
            if(visited[v]) parent[u] = v;
            else {
                //children[u].push_back(v);
                my_queue.push(v);
            }
        }
    }

    for(int u = 1; u <= n; ++u) anty[leaf[u]].push_back(u);
    irytacja = leaf[root];
    if(anty[irytacja].size() == 1) {
        anty[irytacja-1].push_back(anty[irytacja][0]);
        irytacja--;
    }

    krancowych = 2;
    for(int u = 1; u <= n; ++u) visited[u] = false;
    visited[root] = true;

    while(true) {
        for(int u : anty[irytacja]) {
            ;
        }
    }

    return 0;
}
