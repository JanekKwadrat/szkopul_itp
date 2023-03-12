#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1020;

int n, m;
char building[N][N];
bool visited[N][N];
int ans;

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        string buf;
        cin >> buf;
        for(int j = 1; j <= m; ++j) building[i][j] = buf[j-1];
    }

    for(int i = 0; i <= n+1; ++i) {
        building[i][0] = '#';
        building[i][m+1] = '#';
    }
    for(int i = 0; i <= m+1; ++i) {
        building[0][i] = '#';
        building[n+1][i] = '#';
    }

    /*for(int i = 0; i <= n+1; ++i) {
        for(int j = 0; j <= m+1; ++j) {
            cout << building[i][j];
        }
        cout << "\n";
    }*/

    for(int i = 0; i <= n+1; ++i) for(int j = 0; j <= m+1; ++j) visited[i][j] = false;
    ans = 0;
    function<void(int, int, bool)> visit = [&](int i, int j, bool inc) {
        //cout << i << " " << j << "\n";
        if(building[i][j] == '#') return;
        if(visited[i][j]) return;
        visited[i][j] = true;
        if(inc) ans++;
        visit(i - 1, j, false);
        visit(i + 1, j, false);
        visit(i, j - 1, false);
        visit(i, j + 1, false);
    };
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            visit(i, j, true);
        }
    }

    cout << ans << "\n";

    return 0;
}