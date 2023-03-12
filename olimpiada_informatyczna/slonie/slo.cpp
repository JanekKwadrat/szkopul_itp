#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
int n;
int m[N];
int a[N], b[N];
int gdzie_a[N];
int gdzie_b[N];
long long ans;

int main() {

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> m[i];

    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    for(int i = 1; i <= n; ++i) {
        gdzie_a[a[i]] = i;
        gdzie_b[b[i]] = i;
    }

    for(int i = 1; i <= n; ++i) {
        cout << (long long) abs(gdzie_a[i] - gdzie_b[i]) << "\n";
        ans += (long long) m[i] * abs(gdzie_a[i] - gdzie_b[i]);
    }

    cout << ans << "\n";

    return 0;
}