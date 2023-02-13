/* Jan Zakrzewski
   X Olimpiada Informatyczna, Etap I
   Zadanie `Przemytnicy (prz)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5'020;
constexpr int INF = 1e9 + 200;
int n, m;
int p[N];
vector<pair<int, int>> out_neighbors[N];
vector<pair<int, int>> in_neighbors[N];
int out_distance[N];
int in_distance[N];
priority_queue<pair<int, int>> Queue;
int answer;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    cin >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        out_neighbors[u].push_back(make_pair(v, c));
        in_neighbors[v].push_back(make_pair(u, c));
    }

    for(int i = 1; i <= n; ++i) out_distance[i] = INF;
    Queue.push(make_pair(0, 1));
    while(Queue.size() > 0) {
        int u = Queue.top().second;
        int D = Queue.top().first * -1;
        Queue.pop();
        if(out_distance[u] < INF) continue;
        out_distance[u] = D;
        for(auto el : out_neighbors[u]) {
            int v = el.first;
            int c = el.second;
            if(out_distance[v] < INF) continue;
            Queue.push(make_pair((out_distance[u] + c) * -1, v));
        }
    }

    for(int i = 1; i <= n; ++i) in_distance[i] = INF;
    Queue.push(make_pair(0, 1));
    while(Queue.size() > 0) {
        int u = Queue.top().second;
        int D = Queue.top().first * -1;
        Queue.pop();
        if(in_distance[u] < INF) continue;
        in_distance[u] = D;
        for(auto el : in_neighbors[u]) {
            int v = el.first;
            int c = el.second;
            if(in_distance[v] < INF) continue;
            Queue.push(make_pair((in_distance[u] + c) * -1, v));
        }
    }

    //for(int i = 1; i <= n; ++i) cout << out_distance[i] << " "; cout << "\n";
    //for(int i = 1; i <= n; ++i) cout << in_distance[i] << " "; cout << "\n";

    answer = INF;
    for(int i = 1; i <= n; ++i) {
        int ans1 = out_distance[i] + in_distance[i] + p[i] / 2;
        answer = min(answer, ans1);
    }

    cout << answer << "\n";

    return 0;
}
