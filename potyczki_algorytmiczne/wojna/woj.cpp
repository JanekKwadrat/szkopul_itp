/*  Jan Zakrzewski
    Potyczki Algorytmiczne 2012
    Zadanie Wojna */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
int n;
int a[2*N], b[2*N];
bool who[2*N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    int Q = 2*n - 1;
    function<int(int)> f = [&](int x)->int {
        return max(-1, (x-n)*2);
    };


    who[Q-1] = true;
    for(int i = Q-2; i >= n; --i) {
        who[f(i)]   = !who[i];
        who[f(i)+1] = !who[i];
    }

    for(int i = n; i < Q; ++i) {
        if(who[i]) {
            a[i] = min(b[f(i)], b[f(i)+1]);
            b[i] = min(a[f(i)], a[f(i)+1]);
        } else {
            a[i] = max(b[f(i)], b[f(i)+1]);
            b[i] = max(a[f(i)], a[f(i)+1]);
        }
    }

    /*for(int i = 0; i < Q; ++i) cout << setw(2) << i << " "; cout << "\n";
    for(int i = 0; i < Q; ++i) cout << setw(2) << f(i) << " "; cout << "\n";
    for(int i = 0; i < Q; ++i) cout << setw(2) << who[i] << " "; cout << "\n";
    for(int i = 0; i < Q; ++i) cout << setw(2) << a[i] << " "; cout << "\n";
    for(int i = 0; i < Q; ++i) cout << setw(2) << b[i] << " "; cout << "\n";*/

    cout << a[Q-1] - b[Q-1] << "\n";

    return 0;
}