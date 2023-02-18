/* Jan Zakrzewski
   Codeforces Round 143
   Task `Two towers'
   https://codeforces.com/contest/1795/problem/A */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 30;

int t, n, m;
char tow1[N], tow2[N];
int ile;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> tow1 >> tow2;
        ile = 0;
        for(int i = 0; i <= n-2; ++i) if(tow1[i] == tow1[i+1]) ile++;
        for(int i = 0; i <= m-2; ++i) if(tow2[i] == tow2[i+1]) ile++;
        if(tow1[n-1] == tow2[m-1]) ile++;

        if(ile <= 1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
