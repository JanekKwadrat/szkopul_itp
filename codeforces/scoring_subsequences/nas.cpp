#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e4 + 10;
using ll = long long;

int t, n;
ll a[MAXN];

int dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        dp[1] = 1;
        int L = 1;

        for (int R = 2; R <= n; R++)
        {
            if (a[R] < R-L+1 || (a[R] == R-L+1 && a[R]  > a[L]))
            {
                L++;
                dp[R] = dp[R-1];
            }
            else
                dp[R] = dp[R-1] + 1;

        }

        for (int i = 1; i <= n; i++)
            cout << dp[i] << ' ';
        cout << '\n';

    }
}