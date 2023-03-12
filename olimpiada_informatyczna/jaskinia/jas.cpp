/*  Jan Zakrzewski
    XI Olimpiada Informatyczna, Etap II
    Zadanie `Jaskinia (jas)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e4 + 20;
int n;
vector<int> neighbors[N];

bool visited[N];
int dist[N];
int A;
queue<int> my_queue;

int d, ans;

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

    fill(visited+1, visited+n+1, false);
    my_queue.push(1);
    while(my_queue.size() > 0) {
        A = my_queue.front();
        my_queue.pop();
        visited[A] = true;
        for(int u : neighbors[A]) {
            if(visited[u]) continue;
            my_queue.push(u);
        }
    }

    fill(dist+1, dist+n+1, -1);
    dist[1] = 0;
    my_queue.push(1);
    while(my_queue.size() > 0) {
        A = my_queue.front();
        my_queue.pop();
        for(int u : neighbors[A]) {
            if(dist[u] != -1) continue;
            dist[u] = dist[A] + 1;
            my_queue.push(u);
        }
    }

    d = dist[A];
    ans = 0;
    
    while(d > 0) {
        d = (d - 1) / 2;
        ans++;
    }
    
    
    cout << ans << "\n";

    return 0;
}
