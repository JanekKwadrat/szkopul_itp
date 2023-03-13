/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap I
   Zadanie `Kurierzy (kur)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'000 + 20;
int n, q;
int p[N];
int ile[N];
pair<int, int> odp;

int main() {

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> p[i];

    while(q--) {
        int a, b;
        cin >> a >> b;
        for(int i = 1; i <= n; ++i) ile[i] = 0;
        odp.first = 0;
        for(int i = a; i <= b; ++i) {
            ile[p[i]]++;
            odp = max(odp, make_pair(ile[p[i]], p[i]));
        }
        if(2 * odp.first > b - a + 1) cout << odp.second << "\n";
        else cout << "0\n";
    }

    return 0;
}
