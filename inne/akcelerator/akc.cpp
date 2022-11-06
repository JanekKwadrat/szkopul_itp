#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100'020;
int n, q;
int v[N];
int vv, ans;

int main() {

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> v[i];

    cin >> q;
    while(q--) {
        cin >> vv;
        ans = (int) ( upper_bound(v, v+n, vv) - lower_bound(v, v+n, vv) );
        cout << ans << "\n";
    }

    return 0;
}