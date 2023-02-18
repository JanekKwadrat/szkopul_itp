/* Jan Zakrzewski
   Codeforces Round 143
   Task `Ideal point' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100;

int t;
int n, k;
int arr[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= 50; ++i) arr[i] = 0;
        for(int i = 1; i <= n; ++i) {
            int l, r;
            cin >> l >> r;
            if(l <= k && k <= r) {
                arr[l] = 1;
                arr[r+1] = -1;
            }
        }
        for(int i = 2; i <= 50; ++i) arr[i] += arr[i-1];
        int M = 0;
        for(int i = 1; i <= 50; ++i) {
            if(i == k) continue;
            M = max(M, arr[i]);
        }
        if(M < arr[k]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
