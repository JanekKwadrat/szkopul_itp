/*  Jan Zakrzewski
    XXVIII Olimpiada Informatyczna, Etap II
    Zadanie `Pakowanie plecaka (ple)' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
constexpr int N = 5e5 + 10;
int n;
i64 w[N];
i64 ans[N];

int main() {

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    ans[n] = w[n];
    for(int i = n-1; i >= 1; --i) {
        //for(int j = i+1; j <= n; ++j) cout << ans[j] << " "; cout << "\n";
        int j = i;
        ans[j] = 0;
        while(true) {
            if(j+1 <= n && ans[j+1] < w[i]) {
                ans[j] = ans[j+1];
                j++;
            } else break;
        }
        while(j <= n) {
            ans[j] += w[i];
            j++;
        }
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << " "; cout << "\n";

    return 0;
}
