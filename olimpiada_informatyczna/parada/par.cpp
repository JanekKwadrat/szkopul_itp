/* Jan Zakrzewski
   XXIII Olimpiada Informatyczna, Etap III
   Zadanie `Parada (par)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+20;
int n;
vector<int> neighbors[N];

int root;
int parent[N];
vector<int> children[N];

bool visited[N];
queue<int> Queue;

int best_path[N]; // best_path[u] = jaka jest najlepsza ścieżka zaczynająca się w wierzchołka u i schodząca tylko w dół
int answer; // ostateczna odpowiedź tutaj będzie

/*
10
7 1
3 8
5 1
8 10
6 2
4 2
2 10
1 10
9 8
-> 5
*/

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    
    //cout << n << "_";
    
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        //cout << u << "_" << v << "_";
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    //cout << "\n";

    for(int u = 1; u <= n; ++u) visited[u] = false;
    root = 1;
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

    function<void(int)> Visit = [&](int u) {
        for(int v : children[u]) Visit(v);
        best_path[u] = 0;
        for(int v : children[u])
            best_path[u] = max(best_path[u], best_path[v] - 1);
        best_path[u] += children[u].size();
    };
    Visit(root);

    //for(int u = 1; u <= n; ++u) cout << u << " "; cout << "\n";
    //for(int u = 1; u <= n; ++u) cout << best_path[u] << " "; cout << "\n";

    answer = 0;
    for(int u = 1; u <= n; ++u) {
        int v1 = -1, v2 = -1;
        int answer1 = children[u].size();
        if(u != root) answer1++;
        for(int v : children[u]) {
            if(v1 == -1 || best_path[v] > best_path[v1]) v1 = v;
            else if(v2 == -1 || best_path[v] > best_path[v2]) v2 = v;
        }
        answer1 += best_path[v1] - 1;
        if(v2 != -1) answer1 += max(0, best_path[v2] - 1);
        answer = max(answer, answer1);
    }
    cout << answer << "\n";
    
    return 0;
}
