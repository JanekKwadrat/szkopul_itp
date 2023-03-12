/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap II
   Zadanie 'Superkomputer (sup)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'000 + 100;
int n, q;
int k[N];
int parent[N];
int ile[N];

queue<int> Queue;
queue<int> Better;
bool visited[N];
int ans;

int main() {

    cin >> n >> q;
    for(int i = 1; i <= q; ++i) cin >> k[i];
    for(int u = 2; u <= n; ++u) cin >> parent[u];
    
    for(int _t = 1; _t <= q; ++_t) {
        int K = k[_t];

        for(int u = 1; u <= n; ++u) ile[u] = 0;
        for(int u = 2; u <= n; ++u) ile[parent[u]]++;

        for(int u = 1; u <= n; ++u) visited[u] = false;

        for(int u = 1; u <= n; ++u) {
            if(ile[u] == 0) {
                Queue.push(u);
                if(u != 1 && ile[parent[u]] == 1)
                    Better.push(u);
            }
        }

        ans = 0;
        while(Queue.size() > 0 || Better.size() > 0) {
            queue<int> Popme;
            int L = K;
            while(L > 0 && Better.size() > 0) {
                int u = Better.front();
                Better.pop();
                if(visited[u]) continue;
                visited[u] = true;
                Popme.push(u);
                L--;
            }
            while(L > 0 && Queue.size() > 0) {
                int u = Queue.front();
                Queue.pop();
                if(visited[u]) continue;
                visited[u] = true;
                Popme.push(u);
                L--;
            }

            if(Popme.size() > 0) ans++;
            while(Popme.size() > 0) {
                int u = Popme.front();
                Popme.pop();
                cout << u << " ";
                if(u != 1) {
                    int v = parent[u];
                    ile[v]--;
                    if(ile[v] == 0) {
                        Queue.push(v);
                        if(v != 1 && ile[parent[v]] == 1)
                            Better.push(v);
                    }
                }
            }
            cout << "\n";
        }
        cout << ans << "\n";
    }

    return 0;
}
