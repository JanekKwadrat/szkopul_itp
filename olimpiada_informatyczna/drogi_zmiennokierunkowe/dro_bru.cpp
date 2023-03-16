/* Jan Zakrzewski
   XXIII Olimpiada Informatyczna, Etap II
   Zadanie `Drogi zmiennokierunkowe (dro)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'000 + 20;
int n, m;
vector<int> droga_out[N];
vector<int> droga_in[N];

bool visited_out[N] = {};
bool visited_in[N] = {};
queue<int> Queue;

vector<int> ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        droga_out[u].push_back(v);
        droga_in[v].push_back(u);
    }

    for(int U = 1; U <= n; ++U) {
        for(int u = 1; u <= n; ++u) visited_out[u] = false;
        Queue.push(U);
        while(Queue.size() > 0) {
            int u = Queue.front();
            Queue.pop();
            if(visited_out[u]) continue;
            visited_out[u] = true;
            for(int v : droga_out[u]) Queue.push(v);
        }
        for(int u = 1; u <= n; ++u) visited_in[u] = false;
        Queue.push(U);
        while(Queue.size() > 0) {
            int u = Queue.front();
            Queue.pop();
            if(visited_in[u]) continue;
            visited_in[u] = true;
            for(int v : droga_in[u]) Queue.push(v);
        }
        bool ok = true;
        for(int u = 1; u <= n; ++u) {
            if(u == U) continue;
            ok = ok && (visited_out[u] || visited_in[u]);
        }
        if(ok) ans.push_back(U);
    }
    
    cout << ans.size() << "\n";
    for(int u : ans) cout << u << " ";
    cout << "\n";

    return 0;
}