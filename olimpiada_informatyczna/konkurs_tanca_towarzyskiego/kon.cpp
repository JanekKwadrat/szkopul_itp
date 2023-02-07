/* Jan Zakrzewski
   XXIX Olimpiada Informatyczna, Etap II
   Zadanie `Konkurs tańca towarzyskiego (kon)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5'020;
constexpr int M = 1'000'020;

int q, n;
bool adj[N][N];
int group[M];
int ile[10];

int main() {

    cin >> q;
    n = 2;

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            adj[i][j] = false;
    adj[1][2] = true;
    adj[2][1] = true;

    group[1] = 1;
    group[2] = 2;
    ile[1] = 1;
    ile[2] = 1;

    if(q <= 5'000) {
        while(q--) {
            char c; int u;
            cin >> c >> u;
            switch(c) {
            case '?': {
                int sum = 0;
                for(int v = 1; v <= n; ++v) sum += (int)adj[u][v];
                cout << sum << "\n";
            } break;
            case 'W': {
                n++;
                adj[n][u] = true;
                adj[u][n] = true;
            } break;
            case 'Z': {
                n++;
                for(int v = 1; v < n; ++v) {
                    adj[n][v] = adj[u][v];
                    adj[v][n] = adj[v][u];
                }
            } break;
            }
        }
    } else {
        while(q--) {
            char c; int u;
            cin >> c >> u;
            switch(c) {
            case '?': {
                cout << ile[3 - group[u]] << "\n";
            } break;
            case 'Z': {
                n++;
                group[n] = group[u];
                ile[group[u]]++;
            } break;
            }
        }
    }

    return 0;
}
