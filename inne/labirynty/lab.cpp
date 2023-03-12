/* Jan Zakrzewski
   XVII Olimpiada Informatyczna Juniorów, Etap II
   Zadanie `Labirynty (lab)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'000 + 10;
int n;
int a[N];

priority_queue<int> potwor;
long long ile;
int ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie();

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    ans = 0;
    ile = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] >= 0) ile += a[i];
        else {
            a[i] *= -1;
            ile -= a[i];
            potwor.push(a[i]);

            if(ile < 0) {
                ans++;
                ile += 2 * potwor.top();
                potwor.pop();
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
