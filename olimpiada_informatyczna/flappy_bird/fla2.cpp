/*  Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap I
    Zadanie Flappy Bird (fla)
    Rozwiązanie w złożoności O(n) */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

inline pair<i64, i64> shrink(pair<i64, i64> I, pair<i64, i64> J) {
    return make_pair(max(I.first, J.first), min(I.second, J.second));
}

constexpr int N = 5e5 + 20;
int n;
i64 X;
i64 x[N];
pair<i64, i64> I[N];
pair<i64, i64> J;
i64 ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> X;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
        i64 a, b;
        cin >> a >> b;
        a += x[i], b += x[i];
        if(a % 2 == 1) a--;
        if(b % 2 == 1) b++;
        a /= 2, b /= 2;
        a++, b--;
        I[i] = make_pair(a, b);
        cout << x[i] << " " << a << " " << b << "\n";
    }
    x[0] = 0;
    I[0] = make_pair(1, 0);

    J = I[0];
    for(int i = 1; i <= n; ++i) {
        J = shrink(I[i], make_pair(J.first, J.second + x[i] - x[i-1]));
    }

    if(J.first <= J.second) ans = J.first;
    else ans = -1;

    if(ans == -1) cout << "NIE\n";
    else cout << ans << "\n";

    return 0;
}
