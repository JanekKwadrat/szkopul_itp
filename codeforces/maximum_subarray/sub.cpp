/* Jan Zakrzewski
   Codeforces Round 144
   Problem `D. Maximum Subarray' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 100;

int t;
int n, k;
long long x;
long long a[N];
long long sum[N];
long long ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k >> x;
        sum[0] = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] -= x;
            sum[i] = sum[i-1] + a[i];
        }
        x *= 2;
        ans = 0;
        for(int d = 1; d <= k; ++d) {
            for(int i = 0; i + d < n; ++ i) {
                ans = max(ans, sum[i + d] - sum[i] + d * x);
            }
        }
        long long Max = sum[n-1];
        for(int i = n-1 - k; i >= 0; --i) {
            Max = max(Max, sum[i + k]);
            ans = max(ans, Max - sum[i] + k * x);
        }
        cout << ans << "\n";
    }

    return 0;
}
