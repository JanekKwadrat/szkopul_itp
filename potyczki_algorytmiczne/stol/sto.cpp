#include <bits/stdc++.h>
using namespace std;

int a, b, k;
int ans;

int main() {

    cin >> a >> b >> k;
    if(a < b) swap(a, b);
    if(b >= 2 * k) ans = 2 * (a / k) + 2 * (b / k - 2);
    else if(b >= k) ans = a / k;
    else ans = 0;
    cout << ans << "\n";

    return 0;
}