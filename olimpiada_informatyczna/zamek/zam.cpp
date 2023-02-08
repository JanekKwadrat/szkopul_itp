/* Jan Zakrzewski
   XXIV Olimpiada Informatyczna, Etap II
   Zadanie `Zamek (zam)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int W1 = 2000 + 100;
constexpr int N = 1e6 + 100;

int w, h, n, m;
int xA, yA;
int xB, yB;
int zamek[W1][W1];
bool ok[N];

constexpr int INF = 2 * N + 100;
int A, B;
int dist[N];
vector<int> neighbors[N];
queue<int> my_queue;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> w >> h;
    cin >> n >> m;
    cin >> xA >> yA;
    cin >> xB >> yB;
    for(int i = 1; i <= n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        x1++, y1++;
        for(int x = x1; x <= x2; ++x)
            for(int y = y1; y <= y2; ++y)
                zamek[x][y] = i;
    }
    for(int i = 1; i <= n; ++i) ok[i] = true;
    for(int i = 1; i <= m; ++i) {
        int x1, y1;
        cin >> x1 >> y1;
        ok[zamek[x1][y1]] = false;
    }

    for(int x = 1; x <= w; ++x)
        for(int y = 1; y <= h; ++y) {
            int u, v;
            do {
                if(x + 1 > w) break;
                u = zamek[x][y];
                v = zamek[x+1][y];
                if(ok[u] == false) break;
                if(ok[v] == false) break;
                if(u == v) break;
                neighbors[u].push_back(v);
                neighbors[v].push_back(u);
            } while(false);
            do {
                if(y + 1 > h) break;
                u = zamek[x][y];
                v = zamek[x][y+1];
                if(ok[u] == false) break;
                if(ok[v] == false) break;
                if(u == v) break;
                neighbors[u].push_back(v);
                neighbors[v].push_back(u);
            } while(false);
        }

    /*for(int y = h; y >= 1; --y) {
        for(int x = 1; x <= w; ++x) {
            if(ok[zamek[x][y]]) cout << zamek[x][y] << " ";
            else cout << "X ";
        }
        cout << "\n";
    }*/

    A = zamek[xA][yA];
    B = zamek[xB][yB];
    for(int u = 1; u <= n; ++u) dist[u] = INF;
    dist[A] = 0;
    my_queue.push(A);
    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        //cout << " " << u << "\n";
        for(int v : neighbors[u]) {
            if(dist[v] < INF) continue;
            dist[v] = dist[u] + 1;
            my_queue.push(v);
        }
    }

    cout << dist[B] + 1 << "\n";

    return 0;
}
