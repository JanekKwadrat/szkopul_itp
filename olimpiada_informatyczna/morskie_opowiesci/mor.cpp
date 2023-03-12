/*
    Jan Zakrzewski
    XX Olimpiada Informatyczna, Etap II
    Rozwiązanie zadania Morskie opowieści
*/
#include <bits/stdc++.h>
using namespace std;

constexpr short N = 5'020;
constexpr short INF = INT16_MAX;
short n, m;
vector<short> neighbor[N];

short shortest_even[N][N];
short shortest_odd[N][N];

int k;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for(short i = 1; i <= m; ++i) {
        short u, v;
        cin >> u >> v;
        neighbor[u].push_back(v);
        neighbor[v].push_back(u);
    }

    for(short u = 1; u <= n; ++u) {
        for(short v = 1; v <= n; ++v) {
            shortest_even[u][v] = INF;
            shortest_odd[u][v] = INF;
        }
    }

    for(short u = 1; u <= n; ++u) {
        queue<short> queue_even;
        queue<short> queue_odd;
        
        shortest_even[u][u] = 0;
        queue_even.push(u);

        while(queue_even.size() > 0) {
            while(queue_even.size() > 0) {
                short v = queue_even.front();
                queue_even.pop();
                for(short w : neighbor[v]) {
                    if(shortest_odd[u][w] < INF) continue;
                    shortest_odd[u][w] = shortest_even[u][v] + 1;
                    queue_odd.push(w);
                }
            }
            while(queue_odd.size() > 0) {
                short v = queue_odd.front();
                queue_odd.pop();
                for(short w : neighbor[v]) {
                    if(shortest_even[u][w] < INF) continue;
                    shortest_even[u][w] = shortest_odd[u][v] + 1;
                    queue_even.push(w);
                }
            }
        }
    }

    /*cout << "shortest_even[][]\n";
    for(short u = 1; u <= n; ++u) {
        for(short v = 1; v <= n; ++v) {
            short x = shortest_even[u][v];
            if(x == INF) cout << "- ";
            else cout << x << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "shortest_odd[][]\n";
    for(short u = 1; u <= n; ++u) {
        for(short v = 1; v <= n; ++v) {
            short x = shortest_odd[u][v];
            if(x == INF) cout << "- ";
            else cout << x << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/

    for(int i = 1; i <= k; ++i) {
        short u, v;
        int d;
        cin >> u >> v >> d;
        if(u == v && d % 2 == 0) {
            if(neighbor[u].size() > 0) cout << "TAK\n";
            else cout << "NIE\n";
        } else {
            bool ans = false;
            ans = ans || d % 2 == 0 && d >= shortest_even[u][v] && shortest_even[u][v] < INF;
            ans = ans || d % 2 == 1 && d >= shortest_odd[u][v] && shortest_odd[u][v] < INF;
            if(ans) cout << "TAK\n";
            else cout << "NIE\n";
        }
    }

    return 0;
}

/*
8 7 4
1 2
2 3
3 4
5 6
6 7
7 8
8 5
2 3 1
1 4 1
5 5 8
1 8 10

*/