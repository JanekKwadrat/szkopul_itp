#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1'296'000;
constexpr int N = 100100;

int n, m;
int city[N];

vector<tuple<int, int, int>> flight[N];

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> city[i];
    for(int i = 1; i <= m; ++i) {
        int u, v, x, k;
        cin >> u >> v;
        cin >> x >> k;
        flight[u].push_back(make_tuple(v, x, k));
        flight[v].push_back(make_tuple(u, x, -k));
    }

    return 0;
}