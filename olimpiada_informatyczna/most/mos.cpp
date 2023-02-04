/*  Jan Zakrzewski
    XI Olimpiada Informatyczna, Etap II
    Zadanie `Most (mos)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 100;
int n, a[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);

    int ans = 0;

    int j = n;
    while(j - 1 > 2) {
        ans += min(a[1] + 2*a[2] + a[j], 2*a[1] + a[j-1] + a[j]);
        j -= 2;
    }

    if(n == 1) ans += a[1];
    else if(j == 2) ans += a[2];
    else if(j == 3) ans += a[1] + a[2] + a[3];

    cout << ans << "\n";

    return 0;
}
