#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200'050;

int t, n, a1;
int a[N];

int main() {

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(&a[2], &a[n+1]);
        for(int i = 2; i <= n; ++i) {
            if(a[1] >= a[i]) continue;
            a[1] = (a[1] + a[i] + 1) / 2;
            
        }
        cout << a[1] << "\n";
    }

    return 0;
}
