#include <bits/stdc++.h>
using namespace std;

constexpr int N = 700;
constexpr int K = 60;
int n, k;     // n = liczba stacji, stacje numerujemy od 1 do n; k = ile kontroli chce przeprowadzić Bajtazar
int x[N][N]; // x[i][j] = liczba pasażerów, który wsiadają na stacji i a wysiadają na stacji j
int sum[N]; // sum[i] = ile pasażerów jest w pociągu po odjechaniu z i-tej stacji
int s[N][N]; 
int common[N][N]; // common[i][j] = ilu pasażerów wsiadło nie później niż na i-tej stacji a wysiadło później niż na j-tej stacji 
int ans[K][N];
int len[K][N];

int main() {

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) cin >> x[i][j];
    }
    
    fill(sum, sum + n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            sum[i] += x[i][j];
            sum[j] -= x[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) sum[i] += sum[i-1];

    for(int i = 1; i <= n; ++i) {
        s[i][n] = x[i][n];
        for(int j = n-i; j > i; --j)
            s[i][j] = s[i][j+1] + x[i][j];
    }
    
    for(int j = 1; j <= n; ++j) {
        common[j][j] = sum[j];
        for(int i = j-1; i >= 1; --i) {
            common[i][j] = common[i+1][j] - s[i+1][j];
        }
    }
    
    //cout << "here1\n";

    for(int i = 0; i <= k; ++i) ans[i][0] = 0, len[i][0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int kk = 1; kk <= k; ++kk) {
            ans[kk][i] = ans[kk][i-1];
            len[kk][i] = len[kk][i-1];
            int alt = ans[kk-1][i-1] + sum[i] - common[len[kk-1][i-1]][i];
            if(alt > ans[kk][i]) {
                ans[kk][i] = alt;
                len[kk][i] = i;
            }
        }
    }

    cout << ans[k][n] << "\n";

    return 0;
}