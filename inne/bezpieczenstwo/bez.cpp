/* Jan Zakrzewski
   Zadanie `Bezpieczeństwo'
   https://szkopul.edu.pl/problemset/problem/693OiLUi9fkPBp9zHXE_72Dx/site/?key=statement */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 20;
constexpr int X = 1e6 + 20;
int n, m;
int a[N];
int divisor[X];
int Count[X];
int ans;

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int x = 0; x < X; ++x) divisor[x] = x;
    for(int x = 2; x < X; ++x) {
        if(divisor[x] != x) continue;
        for(int y = 2*x; y < X; y += x)
            if(divisor[y] == y)
                divisor[y] = x;
    }

    for(int x = 0; x < X; ++x) Count[x] = 0;
    for(int i = 1; i <= n; ++i) {
        int x = a[i];
        int p = -1, c;
        while(x > 1) {
            p = divisor[x];
            c = 0;
            while(x % p == 0) {
                x /= p;
                c++;
            }
            Count[p] = max(Count[p], c);
        }
    }

    ans = 1;
    for(int x = 0; x < 20; ++x) {
        ans = (long long) ans * (Count[x] + 1) % m;
    }
    ans = (ans - n + m) % m;
    cout << ans << "\n";

    return 0;
}
