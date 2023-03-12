/*  Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap II
    Zadanie Zawody sportowe (zaw)
    Rozwiazanie w złożoności O(n) */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
constexpr int MOD = 1e9 + 7;
int n;
vector<pair<int, int>> adj[N]; // opis grafu
int who[N] = {};
int deg[N] = {};
int sure[N] = {};
int inverse[N];
queue<int> my_queue;
bool visited[N] = {};
int ans = 0;
int expo = 0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        int a, b;
        switch(c) {
        case 'T':
            cin >> a;
            adj[a].push_back(make_pair(a, i));
            deg[a] += 2;
            sure[a] = i;
            expo--;
            break;
        case 'N':
            cin >> a >> b;
            adj[a].push_back(make_pair(b, i));
            adj[b].push_back(make_pair(a, i));
            deg[a]++;
            deg[b]++;
            break;
        }
    }

    for(int u = 1; u <= n; ++u) {
        if(deg[u] == 1) my_queue.push(u);
    }

    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        if(who[u] != 0) continue;
        if(deg[u] != 1) continue;

        //cout << "here1\n";

        for(auto el : adj[u]) {
            int v = el.first;
            int d = el.second;
            if(who[v] != 0) continue;
            who[u] = d;
            deg[v]--;
            if(deg[v] == 1) my_queue.push(v);
        }
    }

    bool tak = true;
    for(int u = 1; u <= n; ++u) if(who[u] == 0 && !sure[u]) tak = false;

    //for(int u = 1; u <= n; ++u) if(who[u] == 0) cout << "problem: " << u << "\n";

    if(tak) {
        for(int u = 1; u <= n; ++u) if(sure[u]) who[u] = sure[u];
        for(int u = 1; u <= n; ++u) inverse[who[u]] = u;
        cout << "TAK\n";
        for(int u = 1; u <= n; ++u) cout << inverse[u] << "\n";
        return 0;
    }

    bool zero = false;
    for(int u = 1; u <= n; ++u) if(who[u] == 0 && deg[u] != 2) zero = true;

    if(zero) {
        cout << "NIE\n0\n";
        return 0;
    }

    for(int u = 1; u <= n; ++u) {
        if(who[u] != 0) continue;
        if(visited[u]) continue;
        expo++;
        my_queue.push(u);
        while(my_queue.size() > 0) {
            int v = my_queue.front();
            my_queue.pop();
            visited[v] = true;
            for(auto el : adj[v]) {
                int w = el.first;
                int d = el.second;
                if(who[w] != 0) continue;
                if(visited[w]) continue;
                my_queue.push(w);
            }
        }
    }

    ans = 1;
    for(int i = 0; i < expo; ++i) ans = (ans * 2) % MOD;
    cout << "NIE\n";
    cout << ans << "\n";

    return 0;
}