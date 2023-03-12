#include <bits/stdc++.h>
using namespace std;

constexpr int N = 201'718 * 2;
int n, a;
int ile_monet[N] = { 0 };
int ans;

int main() {

    cin >> n;
    while(n--) {
        cin >> a;
        ile_monet[a]++;
    }

    for(int i = 1; i < N; ++i) {
        ile_monet[i] += ile_monet[i-1] / 2;
        ile_monet[i-1] %= 2;
    }

    for(int i = N-1; i >= 0; --i) {
        if(ile_monet[i]) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}