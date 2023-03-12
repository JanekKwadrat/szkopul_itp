/* Jan Zakrzewski
   https://codeforces.com/contest/1794
   Problem 'C. Scoring Subsequences' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100'000 + 200;

int t, n;
int a[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        int p = 1;
        for(int k = 1; k <= n; ++k) {
            while(true) {
                if(a[p] >= k - p + 1) break;
                p++;
            }
            cout << k - p + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
