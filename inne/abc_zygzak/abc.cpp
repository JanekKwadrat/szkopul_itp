/* Jan Zakrzewski
   Zadanie `ABC zygzak (ABCZ)'
   https://szkopul.edu.pl/problemset/problem/ySk5LRuEDQoH0-Ozp0hl2zBU/site/?key=statement */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
int n, ans;
char zygzak[N];

int main() {

    cin >> n;
    cin >> zygzak;

    ans = 0;
    for(int i = 1; i < n; ++i) {
        if(zygzak[i] == zygzak[i-1]) {
            zygzak[i] = (zygzak[i] - 'A' + 1) % 3 + 'A';
            if(zygzak[i] == zygzak[i+1])
                zygzak[i] = (zygzak[i] - 'A' + 1) % 3 + 'A';
            ans++;
        }
    }

    cout << ans << "\n"; 

    return 0;
}
