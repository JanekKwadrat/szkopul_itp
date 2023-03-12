/*  Jan Zakrzewski
    Potyczki Algorytmiczne 2022
    Zadanie Ornirolog 2 */

#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
constexpr int N = 5e4 + 30;

int n;
int a[N];
bool alter;
int last1, last2;
int ans1, ans2;
int ans;

int main() {

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];

    last1 = a[0], last2 = a[0];
    ans1 = 0, ans2 = 0;
    alter = true;
    for(int i = 1; i < n; ++i) {
        //cout << last1 << " " << last2 << "\n";
        if(alter) {
            if(a[i] <= last1) last1 =  INF, ans1++; else last1 = a[i];
            if(a[i] >= last2) last2 = -INF, ans2++; else last2 = a[i];
        } else {
            if(a[i] >= last1) last1 = -INF, ans1++; else last1 = a[i];
            if(a[i] <= last2) last2 =  INF, ans2++; else last2 = a[i];
        }
        alter = !alter;
    }
    //cout << last1 << " " << last2 << "\n";
    //cout << ans1 << " " << ans2 << "\n";

    ans = min(ans1, ans2);

    cout << ans << "\n";

    return 0;
}