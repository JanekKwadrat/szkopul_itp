/* Jan Zakrzewski
   https://szkopul.edu.pl/problemset/problem/O-5kKDiZiTP-Tv_9Pb44J6dU/site/?key=statement
   Zadanie `Grzybobranie (grz)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 150;
int n, m;
int sektor[N][N];
int wynik[N][N];

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> sektor[i][j];
    for(int i = 0; i <= n; ++i) wynik[i][0] = 0;
    for(int i = 0; i <= m; ++i) wynik[0][i] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            wynik[i][j] = max(wynik[i-1][j], wynik[i][j-1]);
            wynik[i][j] += sektor[i][j];
        }
    cout << wynik[n][m] << "\n";

    return 0;
}
