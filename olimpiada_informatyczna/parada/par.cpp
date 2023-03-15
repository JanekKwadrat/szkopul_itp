/* Jan Zakrzewski
   XXIII Olimpiada Informatyczna, Etap III
   Zadanie `Parada (par)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200'000 + 50;
int n;
vector<int> neighbors[N];

int root;
int parent[N];
vector<int> children[N];

bool visited[N];
int licznik[N];
queue<int> Queue;

int best[N]; // best[u] = ile bramek byłoby potrzebnych na najlepszej trasie kończącej się w wierzchołku u, w poddrzewie u (nie liczymy bramki między u a jego rodzicem)

int ans;

inline pair<int, int> max(pair<int, int> ab, int x) {
    // pomaga w znalezieniu dwóch największych elementów
    int a = ab.first, b = ab.second;
    if(a < b) swap(a, b);
    if(x > a) {
        b = a;
        a = x;
    } else if(x > b) {
        b = x;
    }
    return make_pair(a, b);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

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

    for(int u = 1; u <= n; ++u) {
        licznik[u] = children[u].size();
        if(licznik[u] == 0) Queue.push(u);
    }

    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        if(u != root) {
            licznik[parent[u]]--;
            if(licznik[parent[u]] == 0)
                Queue.push(parent[u]);
        }
        
        best[u] = children[u].size();
        for(int v : children[u]) {
            best[u] = max(best[u], best[v] + (int) children[u].size() - 1);
        }
    }

    ans = 0;
    for(int u = 1; u <= n; ++u) {
        pair<int, int> odp = make_pair(-1, -1);
        for(int v : children[u]) odp = max(odp, best[v]);
        if(odp.first < odp.second) swap(odp.first, odp.second);
        int ans1 = children[u].size();
        if(odp.first != -1) ans1 += odp.first - 1;
        else continue;
        if(odp.second != -1) ans1 += max(odp.second - 1, 0);
        if(u != root) ans1++;
        ans = max(ans, ans1);
    }

    // for(int u = 1; u <= n; ++u) cout << u << " "; cout << "\n";
    // for(int u = 1; u <= n; ++u) cout << best[u] << " "; cout << "\n";

    cout << ans << "\n";

    return 0;
}