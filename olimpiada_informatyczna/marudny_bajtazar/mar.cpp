/* Jan Zakrzewski
   XXVII Olimpiada Informatyczna, Etap II
   Zadanie `Marudny Bajtazar (mar)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 20;
constexpr int K = 16;
int n, m;
char lampki[N];

int liczba(int start, int length) {
    if(start < 1) return -1;
    if(start + length > n+1) return -1;
    int answer = 0;
    for(int i = start; i < start + length; ++i) {
        answer *= 2;
        answer += lampki[i];
    }
    return answer;
}

int ok[2*K][2*N] = {};
int nie_ok[2*K] = {};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    cin >> lampki+1;
    for(int i = 1; i <= n; ++i) lampki[i] -= '0';

    for(int k = 1; k <= K; ++k) {
        for(int i = 1; i <= n; ++i) {
            int x = liczba(i, k);
            if(x == -1) continue;
            ok[k][x]++;
        }

        for(int i = 0; i < (1 << k); ++i)
            if(!ok[k][i])
                nie_ok[k]++;
    }

    int ans;

    ans = 1; while(ans < 17 && nie_ok[ans] == 0) ans++;
    cout << ans << "\n";

    while(m--) {
        int j;
        cin >> j;
        for(int i = j - 2*K; i <= j + 2*K; ++i) {
            for(int k = 1; k <= K; ++k) {
                int x = liczba(i, k);
                if(x == -1) continue;
                ok[k][x]--;
                if(ok[k][x] == 0) nie_ok[k]++;
            }
        }
        lampki[j] = !lampki[j];
        for(int i = j - 2*K; i <= j + 2*K; ++i) {
            for(int k = 1; k <= K; ++k) {
                int x = liczba(i, k);
                if(x == -1) continue;
                ok[k][x]++;
                if(ok[k][x] == 1) nie_ok[k]--;
            }
        }

        ans = 1; while(ans < 17 && nie_ok[ans] == 0) ans++;
        cout << ans << "\n";
    }

    return 0;
}
