/*  Jan Zakrzewski
    Potyczki Algorytmiczne 2022
    Zadanie Podwyżki */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'020;
int n, k;
int a[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    if(k == 2 || k == 3) {
        int small[N], big[N];
        small[1] = a[1], big[n] = a[n];
        for(int i = 2; i <= n; ++i) small[i] = min(small[i-1], a[i]);
        for(int i = n-1; i >= 1; --i) big[i] = max(big[i+1], a[i]);

        if(k == 2) {
            bool ok = false;
            int v;
            for(int i = 1; i <= n-1; ++i)
                if(small[i] >= big[i+1]) {
                    ok = true;
                    v = i;
                    break;
                }
            
            if(ok) {
                cout << "TAK\n";
                cout << v << "\n";
            } else cout << "NIE\n";
        } else {
            bool ok = false;
            int v, w;
            for(int i = 2; i <= n-1; ++i)
                if(small[i-1] >= a[i]) {
                    ok = true;
                    v = i-1, w = i;
                    break;
                } else if(a[i] >= big[i+1]) {
                    ok = true;
                    v = i, w = i+1;
                    break;
                }
            if(ok) {
                cout << "TAK\n";
                cout << v << " " << w << "\n";
            } else cout << "NIE\n";
        }
    } else {
        bool ok = false;
        int v, w;
        for(int i = 1; i <= n-1; ++i)
            if(a[i] >= a[i+1]) {
                ok = true;
                v = i, w = i+1;
                break;
            }
        if(!ok) cout << "NIE\n";
        else {
            cout << "TAK\n";
            int u;
            if(v == 1) {
                u = v;
                v = w;
                w = w+1;
            } else u = v-1;
            int c = n-4;
            for(int i = 1; i <= u-1; ++i)
                if(c > 0) {
                    cout << i << " ";
                    c--;
                }
            for(int i = w+1; i <= n; ++i)
                if(c > 0) {
                    cout << i << " ";
                    c--;
                }
            cout << "\n";
        }
    }

    return 0;
}
