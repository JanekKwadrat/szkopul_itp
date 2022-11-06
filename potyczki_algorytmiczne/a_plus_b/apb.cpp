#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20;;
int l;
string nmb;
long long ans[20];

int main() {

    cin >> nmb;
    l = nmb.length();
    nmb = nmb + " ";
    reverse(nmb.begin(), nmb.end());
    
    ans[0] = 1;
    ans[1] = nmb[1] - '0' + 1;
    for(int i = 2; i <= l; ++i) {
        ans[i] = 0;
        ans[i] += ans[i-1] * (nmb[i] - '0' + 1);
        if(nmb[i] == '1') ans[i] += ans[i-2] * (9 - nmb[i-1] + '0');
    }

    //for(int i = 1; i <= l; ++i) cout << ans[i] << " "; cout << "\n";

    cout << ans[l] << "\n";

    return 0;
}