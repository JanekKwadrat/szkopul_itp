#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
constexpr int N = 10'000;

int n;
i64 poly[N];
i64 ans = 0;

int main() {
    cin >> n;
    for(int i = 0; i <= n; ++i) cin >> poly[i];

    for(int k = n-1; k >= 0; --k) {
        for(int i = 0; i <= k; ++i) {
            poly[i] = poly[i+1] - poly[i];
        }
    }

    for(int i = 0; i <= n; ++i) ans += poly[i];

    cout << ans << "\n";

    return 0;
}