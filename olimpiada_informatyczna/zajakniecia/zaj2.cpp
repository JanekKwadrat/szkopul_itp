#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2'020;

int n, m;
int a[N], b[N];
int ans[N][N];

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            ans[i][j] = 0;

    for(int i = 1; i < N; ++i)
        for(int j = 1; j < N; ++j)
            ans[i][j] = -1;
    
    function<int(int, int)> solve = [&](int i, int j)->int {
        if(ans[i][j] == -1) {
            int answer = 0;
            answer = max(answer, solve(i-1, j));
            answer = max(answer, solve(i, j-1));
            int i1 = i, j1 = j;
            int ic = 2, jc = 2;
            while(i1 > 0 && ic > 0) { if(a[i1] == a[i]) ic--; i1--; }
            while(j1 > 0 && jc > 0) { if(b[j1] == a[i]) jc--; j1--; }
            /*cout << i << " " << j << " " << ic << " " << jc << " " << i1 << " " << j1 << "\n";
            if(i == 3 && j == 3) {
                cout << "    " << a[i] << " " << b[i] << "\n";
            }*/
            if(ic == 0 && jc == 0) answer = max(answer, solve(i1, j1) + 2);
            ans[i][j] = answer;
        }
        return ans[i][j];
    };

    cout << solve(n, m) << "\n";

    return 0;
}