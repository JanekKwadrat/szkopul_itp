#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
constexpr int N = 10'000;

typedef unsigned long long u64;
typedef vector<u64> nmb;
constexpr u64 M = 1e18;

void add(nmb &a, nmb &b) {
    int n = max(a.size(), b.size());
    int k = min(a.size(), b.size());
    a.resize(n+1, 0);

    int i = 0;
    while(i < k) {
        a[i] += b[i];
        a[i+1] += a[i] % M;
        ++i;
    }

    for(int i )
}

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