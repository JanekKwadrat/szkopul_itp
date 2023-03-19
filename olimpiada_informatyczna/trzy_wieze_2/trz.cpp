/* Jan Zakrzewski
   XXV Olimpiada Informatyczna, Etap III
   Zadanie `Trzy wieże 2 (trz) */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'000 + 20;
int n;
char str[N];
int ile_B[N];
int ile_S[N];
int ile_C[N];

int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    cin >> str+1;

    ile_B[0] = 0, ile_S[0] = 0, ile_C[0] = 0;
    for(int i = 1; i <= n; ++i) {
        ile_B[i] = ile_B[i-1];
        ile_S[i] = ile_S[i-1];
        ile_C[i] = ile_C[i-1];
        switch(str[i]) {
        case 'B': ile_B[i]++; break;
        case 'S': ile_S[i]++; break;
        case 'C': ile_C[i]++; break;
        }
    }

    ans = -1;
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            int x = ile_B[j] - ile_B[i-1];
            int y = ile_S[j] - ile_S[i-1];
            int z = ile_C[j] - ile_C[i-1];
            if(x == y) continue;
            if(y == z) continue;
            if(z == x) continue;
            ans = max(ans, j - i + 1);
        }
    }

    if(ans == -1) cout << "NIE\n";
    else cout << ans << "\n";

    return 0;
}