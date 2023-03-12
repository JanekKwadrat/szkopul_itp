#include <bits/stdc++.h>
using namespace std;

typedef signed char i8;

constexpr int N = 100'050;
int n, z;
i8 debt1[N];
i8 debt2[N];
i8 sum[N];
set<int> not_nine;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> z;
    {
        string str;
        cin >> str;
        for(int i = 1; i <= n-1; ++i) debt1[i] = str[n-i-1] - '0';
        cin >> str;
        for(int i = 1; i <= n-1; ++i) debt2[i] = str[n-i-1] - '0';
    }
    for(int i = 1; i <= n-1; ++i) {
        sum[i] = debt1[i] + debt2[i];
        if(sum[i] != 9) not_nine.insert(i);
    }
    sum[n] = 0;
    sum[0] = 0;
    not_nine.insert(0);
    while(z--) {
        char opr;
        int itr, dig;
        cin >> opr;
        if(opr == 'S') {
            cin >> itr;
            int jtr = *lower_bound(not_nine.rbegin(), not_nine.rend(), itr-1, greater<int>());
            int ans = (sum[itr] + sum[jtr] / 10) % 10;
            cout << ans << "\n";
        } else {
            cin >> itr >> dig;
            int inc;
            if(opr == 'W') debt1[itr] = dig;
            else debt2[itr] = dig;
            sum[itr] = debt1[itr] + debt2[itr];
            if(sum[itr] == 9) not_nine.erase(itr);
            else not_nine.insert(itr);
        }
    }

    return 0;
}