/*
    Jan Zakrzewski
    XXX Olimpiada Informatyczna, I etap
    Rozwiązanie zadania 'Płytkie nawiasowania (ply)'
*/

#include <iostream>
using namespace std;

constexpr int N = 1'000'020;
int n, H;
char str[N];
int k = 0, ans = 0;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> H;
    cin >> str;

    for(int i = 0; i < n; ++i) {
        if(str[i] == '(') k += 1;
        if(str[i] == ')') k -= 1;
        if(k < 0) k += 2, ans++;
        if(k > H) k -= 2, ans++;
    }

    cout << ans << "\n";

    return 0;
}