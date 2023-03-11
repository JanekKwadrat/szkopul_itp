/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap III
   Zadanie `FarmerCraft (far)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'000 + 100;
int n;
int c[N];
vector<int> neighbors[N];

int root;
int parent[N];
vector<int> children[N];

bool visited[N];
queue<int> Queue;

long long czas_przejazdu[N]; // czas_przejazdu[u] = ile czasu jest potrzebne, żeby przejechać całe poddrzewo u
long long czas_dodatkowy[N]; // czas_dodatkowy[u] = ile czasu po przejechaniu poddrzewa u minie zanim wszyscy z tego poddrzewa skończą instalować FarmerCrafta

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> c[i];

    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

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
        
        vector<pair<long long, long long>> abc; // wektor par (dod, prz)
        abc.push_back(make_pair(c[u], 0));
        for(int v : children[u]) {
            abc.push_back(make_pair(max(czas_dodatkowy[v] - 1, 0ll), czas_przejazdu[v] + 2));
        }
        sort(abc.begin(), abc.end());
        reverse(abc.begin(), abc.end());

        czas_przejazdu[u] = 0;
        czas_dodatkowy[u] = 0;

        for(auto elm : abc) {
            long long dod = elm.first;
            long long prz = elm.second;

            czas_przejazdu[u] += prz;
            czas_dodatkowy[u] = max(czas_przejazdu[u] + dod, czas_dodatkowy[u]);
        }
        czas_dodatkowy[u] -= czas_przejazdu[u];
    };
    Visit(root);

    czas_dodatkowy[root] = max(czas_dodatkowy[root], (long long)c[root]);

    cout << czas_przejazdu[root] + czas_dodatkowy[root] << "\n";

    return 0;
}
