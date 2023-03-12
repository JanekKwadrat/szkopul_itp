/* Jan Zakrzewski
   XVI Olimpiada Informatyczna, Etap III
   Zadanie `Wiedźmak (wie)' */

#include <bits/stdc++.h>
using namespace std;

int n, m;
int p, k;
// liczba miejscowości 1 <= n <= 200
// liczba dróg 0 <= m <= 3000
// liczba gatunków potworów 1 <= p <= 13
// liczba kowali 0 <= k <= n

// 2^p * n <= 2^13 * 200 = ~ 1.638 * 10^6

constexpr int P = 9000; // 2^13 = 8192 < 9000
constexpr int N = 250;

// mamy graf, którego wierzchołkami są pary u = (alpha, miasto), gdzie alpha jest maską bitową potworów jakie umie pokonać Bajtazar
int ile_czasu[P][N];
int kowal[N]; // kowal[miasto] = alternatywa bitowa mask bitowych kowali mieszkających w mieście kowali
vector<pair<int, pair<int, int>>> drogi[N]; // drogi[miasto] = wektor dróg wychodzących z danego miasta jako pary (miasto, (czas, maska potworów na drodze))

priority_queue<pair<int, pair<int, int>>> kolejka;

int poczatek;
int koniec;
int answer;

int main() {

    cin >> n >> m;
    cin >> p >> k;
    for(int i = 1; i <= n; ++i) kowal[i] = 0;
    for(int i = 1; i <= k; ++i) {
        int w, q, r;
        cin >> w >> q;
        while(q--) {
            cin >> r;
            kowal[w] = kowal[w] | (1 << r - 1);
        }
    }
    for(int i = 1; i <= m; ++i) {
        int u, v, t;
        int q, r;
        cin >> u >> v >> t >> q;
        int alpha = 0;
        while(q--) {
            cin >> r;
            alpha = alpha | (1 << r - 1);
        }
        drogi[u].push_back(make_pair(v, make_pair(t, alpha)));
    }

    for(int alp = 0; alp < (1 << p); ++alp)
        for(int u = 1; u <= n; ++u)
            ile_czasu[alp][u] = INT32_MAX;

    poczatek = 1;
    koniec = n;    
    kolejka.push(make_pair(0, make_pair(0, poczatek)));
    while(kolejka.size() > 0) {
        int t = kolejka.top().first * -1;
        int alp = kolejka.top().second.first;
        int u = kolejka.top().second.second;
        kolejka.pop();

        if(ile_czasu[alp][u] < INT32_MAX) continue;

        alp = kowal[u] | alp;
        ile_czasu[alp][u] = t;

        for(auto elm : drogi[u]) {
            int v = elm.first;
            int t1 = elm.second.first;
            int alp1 = elm.second.second;

            if(alp1 & ~alp != 0) continue;
            kolejka.push(make_pair((t + t1) * -1, make_pair(alp, v)));
        }
    }

    answer = INT32_MAX;
    for(int alp = 0; alp < (1 << p); ++alp) {
        answer = min(answer, ile_czasu[alp][koniec]);
    }

    if(answer == INT32_MAX) cout << "-1\n";
    else cout << answer << "\n";

    return 0;
}
