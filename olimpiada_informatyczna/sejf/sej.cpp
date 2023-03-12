/*  Jan Zakrzewski
    XVIII Olimpiada Informatyczna, Etap II
    Zadanie `Sejf (sej)' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
constexpr int K = 250'000 + 20;
int k;
i64 n;
i64 a[K], X;
i64 P;

// Fakt: 14-cyfrowa liczba ma nie więcej niż 18000 dzielników.
// Niech a, b będą dzielnikami n, które otwierają sejf. Wówczas sejf otwiera również gcd(a, b).
// Wobec tego wszystkie liczby otwierające sejf są wielokrotnościami pewnej liczby g.
// A żadna z liczb a[1]..a[k-1] nie może być jej wielokrotnością.

/*
840 20
417 769 675 649 104 88 83 559 805 436 202 203 136 523 235 209 224 646 771 630
= 140
*/

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= k; ++i) {
        cin >> a[i];
        a[i] = gcd(n, a[i]);
        cout << a[i] << ' ';
    }
    X = a[k];
    cout << '\n';

    if(k == 1) P = 1;
    else {
        for(int i = 1; i <= k-1; ++i) {
            X /= gcd(X, a[i]);
            cout << X << " ";
        }
        cout << "\n";

        P = X;
        for(i64 p = 2; p*p <= X; ++p) {
            if(X % p == 0) {
                P = p;
                break;
            }
        }
    }

    cout << n / P << "\n";

    return 0;
}
