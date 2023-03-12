/*  Jan Zakrzewski
    XX Olimpiada Informatyczna, Etap II
    Zadanie `Bajtokomputer (baj)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'000 + 10;
int n, x[N];
int ans_m[N];
int ans_z[N];
int ans_p[N];
int ans = INT32_MAX;

int main() {

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> x[i];

    ans_m[1] = INT32_MAX / 2;
    ans_z[1] = INT32_MAX / 2;
    ans_p[1] = INT32_MAX / 2;
         if(x[1] == -1) ans_m[1] = 0;
    else if(x[1] ==  0) ans_z[1] = 0;
    else if(x[1] ==  1) ans_p[1] = 0;

    for(int i = 2; i <= n; ++i) {
        if(x[i] == -1) {
            ans_m[i] = ans_m[i-1];
            ans_z[i] = INT32_MAX;
            ans_p[i] = ans_p[i-1] + 2;
        }
        else if(x[i] == 0) {
            ans_m[i] = ans_m[i-1] + 1;
            ans_z[i] = min(ans_z[i-1], ans_m[i-1]);
            ans_p[i] = ans_p[i-1] + 2;
        }
        else if(x[i] == 1) {
            ans_m[i] = ans_m[i-1] + 2;
            ans_z[i] = ans_m[i-1] + 1;
            ans_p[i] = min(ans_p[i-1], min(ans_z[i-1], ans_m[i-1]));
        }
    }

    //for(int i = 1; i <= n; ++i) cout << ans_m[i] << " "; cout << "\n";
    //for(int i = 1; i <= n; ++i) cout << ans_z[i] << " "; cout << "\n";
    //for(int i = 1; i <= n; ++i) cout << ans_p[i] << " "; cout << "\n";

    ans = min(ans, ans_m[n]);
    ans = min(ans, ans_z[n]);
    ans = min(ans, ans_p[n]);
    if(ans > INT32_MAX / 4) ans = INT32_MAX;

    if(ans == INT32_MAX) cout << "BRAK\n";
    else cout << ans << "\n";

    return 0;
}
