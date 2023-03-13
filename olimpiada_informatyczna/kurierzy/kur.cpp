/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap I
   Zadanie `Kurierzy (kur)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'000 + 20;
int n, q;
int p[N];

vector<int> firma[N]; // kursy o których numerach wykonała dana firma
pair<int, int> odp;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        firma[p[i]].push_back(i);
    }
    
    while(q--) {
        int a, b;
        cin >> a >> b;

        odp.first = 0;
        for(int i = 1; i <= n; ++i) {
            auto k0 = lower_bound(firma[i].begin(), firma[i].end(), a);
            auto k1 = upper_bound(firma[i].begin(), firma[i].end(), b);
            odp = max(odp, make_pair((int) (k1 - k0), i));
        }
        if(2 * odp.first > b - a + 1) cout << odp.second << "\n";
        else cout << "0\n";
    }

    return 0;
}
