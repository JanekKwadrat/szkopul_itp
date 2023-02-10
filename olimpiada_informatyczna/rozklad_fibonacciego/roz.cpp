/* Jan Zakrzewski
   XIX Olimpiada Informatyczna, Etap II
   Zadanie `Rozkład Fibonacciego (roz)' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
constexpr int F = 93;
i64 fib[F]; // fib[F] > 2^31-1
int ile(i64 x) {
    if(x < 0) return 1000;
    if(x == 0) return 0;
    int I = 0; // supposed to be the biggest I such that fib[I] <= x
    while(I+1 < F && fib[I+1] <= x) I++;
    if(fib[I] == x) return 1;
    int ans = 1000;
    ans = min(ans, 1 + ile(x - fib[I]));
    ans = min(ans, 1 + ile(fib[I+1] - x));
    return ans;
}
int p;
i64 k;

int main() {

    fib[0] = 0, fib[1] = 1;
    for(int i = 2; i < F; ++i)
        fib[i] = fib[i-1] + fib[i-2];
    
    //for(int i = 0; i < F; ++i) cout << fib[i] << "\n";
    cin >> p;
    while(p--) {
        cin >> k;
        cout << ile(k) << "\n";
    }

    return 0;
}
