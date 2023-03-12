/*  Jan Zakrzewski
    Potyczki Algorytmiczne 2022
    Zadanie 'Muzyka pop 2' */

#include <bits/stdc++.h>
using namespace std;

int bit(int x) {
    int ans = 0;
    while(x > 0) {
        ans += x % 2;
        x /= 2;
    }
    return ans;
}

int n, k;
int C, p;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    C = 0;
    k = 0;
    while(true) {
        k++;
        C += bit(k);
        if(C >= n) break;
    }

    p = k;
    while(true) {
        if(C - bit(p) == n) break;
        p--;
        if(p == 0) break;
    }

    cout << (p == 0 ? k : k - 1) << "\n";
    for(int i = k; i >= 1; --i) if(i != p) cout << i << " ";
    cout << "\n";

    return 0;
}
