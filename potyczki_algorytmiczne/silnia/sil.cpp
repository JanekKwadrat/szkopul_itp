#include <bits/stdc++.h>
using namespace std;

int n;
int ans[] = {1, 1, 2, 6, 4};

int main() {
    cin >> n;
    if(n >= 5) cout << "0\n";
    else cout << ans[n] << "\n";
    return 0;
}