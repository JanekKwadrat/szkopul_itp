/*  Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap I
    Zadanie Turysta (tur)
    Rozwiązanie w złożoności O(n!), podzadanie 1 */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20;
int n, n_fact;
bool road[N][N];

vector<int> ans[N];

int main() {

    cin >> n;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            char c;
            cin >> c;
            switch(c) {
            case '0':
                road[i][j] = true;
                road[j][i] = false;
                break;
            case '1':
                road[i][j] = false;
                road[j][i] = true;
                break;
            }
        }
    }

    n_fact = 1;
    for(int i = 2; i <= n; ++i) n_fact *= i;

    for(int i = 0; i < n_fact; ++i) {
        int a[N];
        for(int j = 0; j < n; ++j) a[j] = j;
        int x = i;
        for(int j = n; j >= 1; --j) {
            swap(a[x % j], a[j-1]);
            x /= j;
        }
        vector<int> u;
        u.push_back(a[0]);
        for(int i = 1; i < n; ++i) {
            if(road[a[i-1]][a[i]]) u.push_back(a[i]);
            else break;
        }
        if(u.size() > ans[a[0]].size()) ans[a[0]] = u;
    }

    for(int i = 0; i < n; ++i) {
        cout << ans[i].size() << " ";
        for(int x : ans[i]) cout << x + 1 << " ";
        cout << "\n";
    }

    return 0;
}