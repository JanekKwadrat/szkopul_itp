#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1020;
int n, m;
char* obraz[N];
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> n >> m;
    for(int i = 0; i < N; ++i) obraz[i] = new char [N];
    for(int i = 0; i < m; ++i) obraz[i][n] = 0;

    for(int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for(int j = 0; j < m; ++j) obraz[j][n-i-1] = str[j];
    }

    for(int i = 0; i < m; ++i) {
        cout << obraz[i] << "\n";
    }

    return 0;
}