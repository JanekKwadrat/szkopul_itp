/* Jan Zakrzewski
   https://szkopul.edu.pl/problemset/problem/zuuZLeGrS-pExrg0F1pBFtdJ/site/?key=statement
   Zadanie `3 Spacer (spa)' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
constexpr int N = 101;
constexpr i64 INF = 1e14 + 1000;
int n, m;
i64 trasa[N*N][N][N]; // trasa[k][u][v] = jaka jest najkrótsza trasa, składająca się z k dróg, z wierzchołka u do wierzchołka v
double ans = INF;

int main() {

    cin >> n >> m;
    for(int k = 1; k <= 2*n; ++k)
        for(int u = 1; u <= n; ++u)
            for(int v = 1; v <= n; ++v)
                trasa[k][u][v] = INF;
    for(int i = 1; i <= m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        trasa[1][u][v] = d;
    }
    for(int k = 1; k < 2*n; ++k) {
        for(int u = 1; u <= n; ++u)
            for(int v = 1; v <= n; ++v) 
                for(int w = 1; w <= n; ++w)
                    trasa[k+1][u][w] = min(trasa[k+1][u][w], trasa[k][u][v] + trasa[1][v][w]);
    }
    for(int k = 1; k <= 2*n; ++k) {
        for(int u = 1; u <= n; ++u)
            ans = min(ans, (double)trasa[k][u][u] / k);
    }
    cout << ans << "\n";

    return 0;
}
