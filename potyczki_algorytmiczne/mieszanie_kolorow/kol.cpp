#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
constexpr int K = 10;

int n, m;
int l, r, k;
int farba[N][K] = { 0 };
int ans = 0;

int main() {

    cin >> n >> m;
    while(m--) {
        cin >> l >> r >> k;
        farba[l][k]++;
        farba[r+1][k]--;
    }

    for(int i = 2; i <= n; ++i) {
        farba[i][1] += farba[i-1][1];
        farba[i][2] += farba[i-1][2];
        farba[i][3] += farba[i-1][3];
    }

    for(int i = 1; i <= n; ++i) {
        if(farba[i][1] > 0 && farba[i][2] > 0 && farba[i][3] == 0) ans++;
    }

    cout << ans << "\n";

    return 0;
}