/*
    Jan Zakrzewski
    XVII Olimpiada Informatyczna, Etap I
    Rozwiązanie zadania 'Test na inteligencję (tes)'
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'020;
int m, q;
int C[N];
vector<int> where_C[N];

int n;
int a[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m;
    for(int i = 1; i <= m; ++i) cin >> C[i];
    for(int i = 1; i <= m; ++i) where_C[C[i]].push_back(i);
    
    cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        bool ok = true;
        int itr = 0;
        for(int i = 1; i <= n; ++i) {
            auto jtr = upper_bound(where_C[a[i]].begin(), where_C[a[i]].end(), itr);
            if(jtr == where_C[a[i]].end()) { ok = false; break; }
            itr = *jtr;
        }

        if(ok) cout << "TAK\n";
        else cout << "NIE\n";
    }

    return 0;
}