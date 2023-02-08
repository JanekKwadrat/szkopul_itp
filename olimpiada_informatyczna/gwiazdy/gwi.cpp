/* Jan Zakrzewski
   XXVI Olimpiada Informatyczna, Etap II
   Zadanie `Gwiazdy (gwi)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 20;
int n, s;
int l[N], r[N];
constexpr int L = 1, R = 2;
int d[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> s;
    for(int i = 1; i <= n-1; ++i) cin >> l[i] >> r[i];

    for(int i = 1; i <= n-1; ++i) {
        if(l[i] < r[i]) d[i] = L;
        else d[i] = R;
    }

    if(d[1] == L) {
        bool ok = false;
        if(s == n) ok = true;
        for(int i = 2; i <= s; ++i)
            if(d[i] == R)
                ok = true;
        if(!ok) {
            int j = 1;
            for(int i = 2; i <= s; ++i)
                if(r[i] - l[i] < r[j] - l[j])
                    j = i;
            d[j] = R;
        }
    } else if(d[1] == R) {
        bool ok = false;
        if(s == 1) ok = true;
        for(int i = 2; i <= n-s+1; ++i)
            if(d[i] == L)
                ok = true;
        if(!ok) {
            int j = 1;
            for(int i = 2; i <= n-s+1; ++i)
                if(l[i] - r[i] < l[j] - r[j])
                    j = i;
            d[j] = L;
        }
    }

    //for(int i = 1; i <= n-1; ++i) cout << d[i] << " "; cout << "\n";

    int p = 1, q = n;
    long long ans = 0;
    int path[N];

    for(int i = n-1; i >= 1; --i) {
        if(p == s) p++;
        if(q == s) q--;
        if(d[i] == L) {
            path[i] = p;
            p++;
        }
        if(d[i] == R) {
            path[i] = q;
            q--;
        }
    }

    for(int i = 1; i <= n-1; ++i) {
        if(d[i] == L) ans += l[i];
        else ans += r[i];
    }

    cout << ans << "\n";
    cout << s << " ";
    for(int i = 1; i <= n-1; ++i) cout << path[i] << " "; cout << "\n";

    return 0;
}
