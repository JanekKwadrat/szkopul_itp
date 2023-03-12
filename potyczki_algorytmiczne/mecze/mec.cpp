#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;

constexpr int N = 50'000;
int n, m, p;
u64 player[N];
bool ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; ++i) player[i] = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n / 2; ++j) {
            cin >> p;
            p -= 1;
            player[p] += 1ULL << i;
        }
        for(int j = 0; j < n / 2; ++j) cin >> p;
    }

    sort(player, player + n);
    ans = true;
    for(int i = 1; i < n; ++i) {
        if(player[i] == player[i-1]) {
            ans = false;
            break;
        }
    }

    if(ans) cout << "TAK\n";
    else cout << "NIE\n";

    return 0;
}