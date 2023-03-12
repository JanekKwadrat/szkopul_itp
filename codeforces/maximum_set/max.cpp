/* Jan Zakrzewski
   Codeforces Round 144
   Problem `C. Maximum Set' */

#include <bits/stdc++.h>
using namespace std;

constexpr int M = 998'244'353;
int t;
int l, r;

int main() {

    cin >> t;
    while(t--) {
        cin >> l >> r;
        int k = 1, ans = 0;
        int fac = 1;
        while(2 * fac * l <= r) {
            fac *= 2;
            k++;
        }
        ans += (r / fac) - l + 1;
        if(k >= 2) {
            fac = fac / 2 * 3;
            ans += max(((r / fac) - l + 1) * (k - 1), 0);
        }
        cout << k << " " << ans << "\n";
    }

    return 0;
}
