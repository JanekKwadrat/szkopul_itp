/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap II
   Zadanie `Rajd (raj)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'000 + 100;
int n, m;
vector<int> ulica_fw[N];
vector<int> ulica_bw[N];
int pierwszy, ostatni;

vector<int> topologiczne; // tu będą posortowane topologicznie skrzyżowania
bool visited[N];

int najdalej_fw[N]; // jaka jest najdłuższa ścieżka zaczynająca się w danym wierzchołku (długość liczymy po liczbie krawędzi)
int najdalej_bw[N]; // jaka jest najdłuższa ścieżka kończąca się w danym wierzchołku (długość liczymy po liczbie krawędzi)

multiset<int> Dobre; // tu będą wybrane krawędzie
pair<int, int> odp;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        ulica_fw[u].push_back(v);
        ulica_bw[v].push_back(u);
    }

    pierwszy = n + 1;
    ostatni = n + 2;
    for(int u = 1; u <= n; ++u) {
        ulica_fw[pierwszy].push_back(u);
        ulica_bw[u].push_back(pierwszy);
        ulica_fw[u].push_back(ostatni);
        ulica_bw[ostatni].push_back(u);
    }
    n += 2;

    function<void(int)> Visit = [&](int u) {
        if(visited[u]) return;
        visited[u] = true;

        for(int v : ulica_fw[u]) Visit(v);
        topologiczne.push_back(u);
    };
    fill(visited + 1, visited + n + 1, false);
    for(int u = 1; u <= n; ++u) Visit(u);
    reverse(topologiczne.begin(), topologiczne.end());

    //for(int u : topologiczne) cout << u << " "; cout << "\n";

    function<void(int)> Licz_fw = [&](int u) {
        if(najdalej_fw[u] != -1) return;
        najdalej_fw[u] = 0;
        for(int v : ulica_fw[u]) {
            Licz_fw(v);
            najdalej_fw[u] = max(najdalej_fw[u], najdalej_fw[v] + 1);
        }
    };
    fill(najdalej_fw + 1, najdalej_fw + n + 1, -1);
    for(int u = 1; u <= n; ++u) Licz_fw(u);

    function<void(int)> Licz_bw = [&](int u) {
        if(najdalej_bw[u] != -1) return;
        najdalej_bw[u] = 0;
        for(int v : ulica_bw[u]) {
            Licz_bw(v);
            najdalej_bw[u] = max(najdalej_bw[u], najdalej_bw[v] + 1);
        }
    };
    fill(najdalej_bw + 1, najdalej_bw + n + 1, -1);
    for(int u = 1; u <= n; ++u) Licz_bw(u);

    odp = make_pair(INT32_MAX, -1);
    for(int u : topologiczne) {
        int D;
        for(int v : ulica_bw[u]) {
            D = najdalej_bw[v] + najdalej_fw[u] + 1;
            auto itr = Dobre.find(-D);
            if(itr != Dobre.end()) Dobre.erase(itr);
        }
        if(u != pierwszy && u != ostatni) {

            D = 0;
            if(Dobre.size() > 0) D = - * Dobre.begin();

            //cout << u << " " << D << "\n";
            
            D = max(D, najdalej_fw[u] - 1);
            D = max(D, najdalej_bw[u] - 1);

            odp = min(odp, make_pair(D, u));
        }
        for(int v : ulica_fw[u]) {
            D = najdalej_fw[v] + najdalej_bw[u] + 1;
            Dobre.insert(-D);
        }
    }

    //for(int u : topologiczne) cout << u << " "; cout << "\n";
    //for(int u : topologiczne) cout << najdalej_fw[u] << " "; cout << "\n";
    //for(int u : topologiczne) cout << najdalej_bw[u] << " "; cout << "\n";

    cout << odp.second << " " << odp.first - 2 << "\n";

    return 0;
}
