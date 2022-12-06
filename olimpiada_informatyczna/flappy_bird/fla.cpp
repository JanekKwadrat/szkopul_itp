/*  Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap I
    Zadanie Flappy Bird (fla)
    Rozwiązanie w złożoności O(n) */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
constexpr int N = 5e5 + 20;
int n;
i64 X;
i64 x[N];
pair<i64, i64> I[N];
pair<i64, i64> J;
i64 ans;


int main() {

    cin >> n >> X;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
        cin >> I[i].first;
        cin >> I[i].second;
    }
    x[0] = 0;
    I[0] = make_pair(0, 0);

    ans = 0;
    J = I[0];
    for(int i = 1; i <= n; ++i) {
        J.first  = max(I[i].first  + 1, J.first  - (x[i] - x[i-1]));
        J.second = min(I[i].second - 1, J.second + (x[i] - x[i-1]));
        //cout << J.first << " " << J.second << "\n";
        if((x[i] - J.first ) % 2 != 0) J.first ++;
        if((x[i] - J.second) % 2 != 0) J.second--;
        if(J.first > J.second) ans = -1;
        //cout << J.first << " " << J.second << "\n";
    }


    if(ans == 0) ans = (J.first + x[n]) / 2;

    if(ans == -1) cout << "NIE\n";
    else cout << ans << "\n";

    return 0;
}