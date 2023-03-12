/* Jan Zakrzewski
   https://codeforces.com/contest/1794
   Problem 'B. Not Dividing' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 10'000 + 200;

int t, n;
int a[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        if(a[1] == 1) a[1]++;
        for(int i = 2; i <= n; ++i) {
            if(a[i] == 1) a[i]++;
            if(a[i] % a[i-1] == 0) a[i]++;
        }
        for(int i = 1; i <= n; ++i) cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}
