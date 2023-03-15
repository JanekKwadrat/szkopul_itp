/* Jan Zakrzewski
   XXII Olimpiada Informatyczna, Etap I
   Zadanie `Kwadraty (kwa)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9 + 300;
constexpr int N = 1e6;
int n = 100;
int k[N]; // tu będą wartości k(x) dla 0 <= x <= n



int main() {

    cin >> n;
    
    for(int i = 0; i <= n; ++i) k[i] = INF;
    k[0] = 0;

    for(int x = 1; x * x <= n; ++x) {
        for(int i = n; i >= 0; --i) {
            if(i + x*x > n) continue;
            k[i + x*x] = min(k[i + x*x], max(k[i], x));
        }
    }

    cout << k[n] << "\n";
    
    /*cout << "NIEDOBRE: ";
    for(int x = 0; x <= n; ++x) {
        if(k[x] == INF) cout << x << " ";
    }
    cout << "\n";

    for(int i = 0; i <= n; ++i) {
        cout << "k(" << i << ") = ";
        if(k[i] < INF) cout << k[i];
        else cout << "INF";
        if(i != n) cout << ", ";
    }
    cout << "\n";*/

    return 0;
}
