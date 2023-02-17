/* Jan Zakrzewski
   Potyczki Algorytmiczne 2020
   Zadanie `Zabawki (zab)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 20;
int n;
char StrA[N];
char StrB[N];
int ile[256] = {};
bool ok;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    cin >> StrA+1;
    cin >> StrB+1;

    for(int i = 1; i <= n; ++i) {
        char c = StrA[i];
        if(i % 2 == 0) c += 'A' - 'a';
        ile[c]++;
    }
    for(int i = 1; i <= n; ++i) {
        char c = StrB[i];
        if(i % 2 == 0) c += 'A' - 'a';
        ile[c]--;
    }

    ok = true;
    for(int i = 0; i < 256; ++i) if(ile[i] != 0) ok = false;

    if(ok) cout << "TAK\n";
    else cout << "NIE\n";

    return 0;
}
