/*  Jan Zakrzewski
    XX Olimpiada Informatyczna, Etap III
    Zadanie Łańcuch kolorowy (lan) */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6+20;
int m, n;
int a[N];
int k[N];
long long L;
int p, q;
int ok;
int ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) k[i] = 0;
   
    int l[N], c;
    for(int i = 1; i <= m; ++i) cin >> l[i];
    for(int i = 1; i <= m; ++i) {
        cin >> c;
        k[c] = l[i];
    }

    //cout << "here1\n";

    for(int i = 1; i <= n; ++i) cin >> a[i];
    L = 0;
    for(int i = 1; i <= n; ++i) L += k[i];

    //for(int i = 1; i <= n; ++i) cout << k[i] << " "; cout << "\n";
    
    if(L > n) {
        cout << "0\n";
        return 0;
    }

    for(q = 1; q <= L; ++q) k[a[q]]--;
    ok = 0, p = 1;
    for(int i = 1; i <= n; ++i) if(k[i] != 0) ok++;


    ans = 0;
    if(ok == 0) ans++;
    while(q <= n) {
        //cout << p << " " << q << " " << ok << "\n";
        //for(int i = 1; i <= n; ++i) cout << k[i] << " "; cout << "\n";
        
        if(k[a[q]] == 0) ok++;
        k[a[q]]--;
        if(k[a[q]] == 0) ok--;
        q++;

        if(k[a[p]] == 0) ok++;
        k[a[p]]++;
        if(k[a[p]] == 0) ok--;
        p++;

        if(ok == 0) ans++;
    }

    cout << ans << "\n";

    return 0;
}
