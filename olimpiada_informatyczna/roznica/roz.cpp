/* Jan Zakrzewski
   XVIII Olimpiada Informatyczna, Etap II
   Zadanie `Różnica (roz)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
int n;
char str[N];
int C[26][26];
pair<int, int> M[26][26];
pair<int, int> m[26][26];
int roznica = 0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    cin >> str+1;
    for(int i = 1; i <= n; ++i) str[i] -= 'a';
    for(int i = 0; i < 26; ++i)
        for(int j = 0; j < 26; ++j) {
            M[i][j] = make_pair(0, 0);
            m[i][j] = make_pair(0, 0);
        }
    
    for(int i = 1; i <= n; ++i) {
        for(int c = 0; c < 26; ++c) {
            C[c][str[i]]++;
            M[c][str[i]] = max(M[c][str[i]], make_pair(C[c][str[i]], i));
            C[str[i]][c]--;
            m[str[i]][c] = min(m[str[i]][c], make_pair(C[str[i]][c], i));
        }
    }

    for(int i = 0; i < 26; ++i)
        for(int j = 0; j < 26; ++j) {
            if(M[i][j].second - m[i][j].second > M[i][j].first - m[i][j].first) roznica = max(roznica, M[i][j].first - m[i][j].first);
            else roznica = max(roznica, M[i][j].first - m[i][j].first - 1);
        }

    cout << roznica << "\n";

    return 0;
}
