/* Jan Zakrzewski
   XXVI Olimpiada Informatyczna, Etap III
   Zadanie `Wyścigi (wys)' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
constexpr int N = 300'000 + 100;
int n, q;
i64 p[N];

constexpr int D = 524'288; // potęga dwójki, [1, n] zawiera się w [0, D)
i64 tree[2 * D];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> p[i];

    sort(p+1, p+n+1);

    while(q--) {
        char c;
        i64 x, y;
        cin >> c;
        if(c == 'Z') {
            int ans = 0;
            int target = 0;
            for(int i = 1; i <= n; ++i) {
                target = max((i64)target, p[i] + (n+1)-i);
            }
            for(int i = 1; i <= n; ++i) {
                if(p[i] + n >= target) ans ++;
            }
            cout << ans << "\n";
        } else if(c == 'B') {
            cin >> x >> y;
            for(int i = 1; i <= n; ++i) {
                if(p[i] >= x) p[i] += y;
            }
        } else if(c == 'K') {
            cin >> x >> y;
            for(int i = 1; i <= n; ++i) {
                if(p[i] <= x) p[i] -= y;
            }
        }
    }

    return 0;
}
