/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap III
   Zadanie `Panele słoneczne (pan)' */

#include <bits/stdc++.h>
using namespace std;

int t;
int a_min, a_max;
int b_min, b_max;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> a_min >> a_max;
        cin >> b_min >> b_max;

        int N = max(a_max, b_max) + 100;
        int x = N;
        while(x > 1) {
            bool ok = true;
            ok = ok && a_max / x - (a_min-1) / x > 0;
            ok = ok && b_max / x - (b_min-1) / x > 0;
            if(ok) break;
            x--;
        }
        cout << x << "\n";
    }

    return 0;
}
