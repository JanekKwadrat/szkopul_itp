/*
    Jan Zakrzewski
    XXIII Olimpiada Informatyczna, Etap II
    Rozwiązanie zadania Zająknięcia (zaj)
    Złożoność obliczeniowa: O((m + n) log (m + n))
    Złożoność pamięciowa:   O(m + n)
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20'000;

int n, m, L;
int C[N], a[N];
int ans[N]; // ans[i] = jaka jest długość najdłuższego wspólnego zająknięcia słów C oraz (a[1], ..., a[i]) ?
int dist[N]; // dist[i] = jak daleko w słowie C rozciąga się najdłuższe wspólne zająknięcie słów C oraz (a[1], ..., a[i]) ?
int alt[N]; // alt[i] = jak daleko w słowie C roziągałoby się najdłuższe wspólne zająknięcie słów C oraz (a[1], ..., a[i]), gdyby usunąć jego dwa ostatnie elementy

int prev_a[N]; // prev_a[i] = jaki jest indeks ostatniego wystąpienia a[i] w słowie (a[1], ..., a[i-1]) ? jeśli takiego wystąpienia nie ma prev_a[i] = -1
vector<int> where_C[2 * N]; // where_C[x] = posortowany wektor pozycji, na których występuje x w słowie C

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> C[i];

    {
        // zmniejszanie wartości liczb w słowach C oraz a
        vector<int> dict;
        dict.insert(dict.end(), C + 1, C + n + 1);
        dict.insert(dict.end(), a + 1, a + n + 1);
        sort(dict.begin(), dict.end());
        dict.erase(unique(dict.begin(), dict.end()), dict.end());

        for(int i = 1; i <= m; ++i) C[i] = (int) ( lower_bound(dict.begin(), dict.end(), C[i]) - dict.begin() );
        for(int i = 1; i <= n; ++i) a[i] = (int) ( lower_bound(dict.begin(), dict.end(), a[i]) - dict.begin() );
        L = (int) dict.size();
    }

    {
        // uzupełnienie prev_a
        vector<int> prevs(L);
        fill(prevs.begin(), prevs.end(), -1);
        for(int i = 1; i <= n; ++i) {
            prev_a[i] = prevs[a[i]];
            prevs[a[i]] = i;
        }

        // uzupełnienie where_C
        for(int i = 1; i <= m; ++i) where_C[C[i]].push_back(i);
    }

    ans[0] = 0;
    dist[0] = 0;
    alt[0] = 0;
    for(int i = 1; i <= n; i++) {
        ans[i] = ans[i-1];
        dist[i] = dist[i-1];
        alt[i] = alt[i-1];
        if(prev_a[i] == -1) continue;
        int j = prev_a[i] - 1;
        int x = a[i];
        auto itr = lower_bound(where_C[x].begin(), where_C[x].end(), dist[j]+1);
        if(itr == where_C[x].end() || itr + 1 == where_C[x].end()) continue;
        
        
        /*
            ans[j] + 2 , *(itr + 1)
            ans[i]     , dist[i]
        */
        if(ans[j] + 2 > ans[i]) {
            ans[i] = ans[j] + 2;
            dist[i] = *(itr+1);
        } else if (ans[j] + 2 == ans[i]) {
            dist[i] = min(dist[i], *(itr+1));
        }
    }

    for(int i = 1; i <= n; ++i) cout << setw(2) << ans[i] << " "; cout << "\n";
    for(int i = 1; i <= n; ++i) cout << setw(2) << dist[i] << " "; cout << "\n";

    cout << ans[n] << "\n";

    return 0;
}