/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap II
   Zadanie `Rajd (raj)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'000 + 100;
int n, m;
vector<int> ulica_fw[N];
vector<int> ulica_bw[N];
int pcz, kon;

vector<int> topologicznie; // tu będą skrzyżowania posortowane topologicznie
bool visited[N];

int najdalej_fw[N]; // jaka jest najdłuższa ścieżka zaczynająca się w danym wierzchołku (długość liczymy po liczbie krawędzi)
int najdalej_bw[N]; // jaka jest najdłuższa ścieżka kończąca się w danym wierzchołku (długość liczymy po liczbie krawędzi)
int L; // maksymalna wartość najdalej_fw[u] + najdalej_bw[u] po wszystkich wierzchołkach u

priority_queue<tuple<int, int>> Queue; // kolejka trójek opisujących ulice (D, v), gdzie D to długość najdłuższej trasy zawierającej pewną ulicę (u, v)
pair<int, int> odp; // odpowiedź jako para (dlugość, skrzyżowanie), w odwrotnej kolejności niż ma być na wyjściu

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

    pcz = n+1;
    kon = n+2;
    for(int u = 1; u <= n; ++u) {
        ulica_fw[pcz].push_back(u);
        ulica_bw[u].push_back(pcz);
        
        ulica_fw[u].push_back(kon);
        ulica_bw[kon].push_back(u);
    }
    n += 2;

    fill(visited+1, visited+1+n, false);
    function<void(int)> Visit = [&](int u) {
        if(visited[u]) return;
        visited[u] = true;
        for(int v : ulica_fw[u]) Visit(v);
        topologicznie.push_back(u);
    };
    for(int u = 1; u <= n; ++u) Visit(u);
    reverse(topologicznie.begin(), topologicznie.end());

    //for(int u : topologicznie) cout << u << " "; cout << "\n";

    fill(visited+1, visited+1+n, false);    
    function<void(int)> Licz_fw = [&](int u) {
        if(visited[u]) return;
        visited[u] = true;
        najdalej_fw[u] = 0;
        for(int v : ulica_fw[u]) {
            Licz_fw(v);
            najdalej_fw[u] = max(najdalej_fw[u], najdalej_fw[v] + 1);
        }
    };
    for(int u = 1; u <= n; ++u) Licz_fw(u);

    fill(visited+1, visited+1+n, false);    
    function<void(int)> Licz_bw = [&](int u) {
        if(visited[u]) return;
        visited[u] = true;
        najdalej_bw[u] = 0;
        for(int v : ulica_bw[u]) {
            Licz_bw(v);
            najdalej_bw[u] = max(najdalej_bw[u], najdalej_bw[v] + 1);
        }
    };
    for(int u = 1; u <= n; ++u) Licz_bw(u);

    L = 0;
    for(int u = 1; u <= n; ++u)
        L = max(L, najdalej_fw[u] + najdalej_bw[u]);

    fill(visited+1, visited+1+n, false);
    odp = make_pair(INT32_MAX, -1);
    for(int u : topologicznie) {
        visited[u] = true;
        if(najdalej_fw[u] + najdalej_bw[u] == L) {
            
            int D = INT32_MIN;
            
            while(true) {
                if(Queue.size() == 0) break;
                int v;
                v = get<1>(Queue.top());
                if(!visited[v]) {
                    D = get<0>(Queue.top());
                    break;
                } else Queue.pop();
            }

            // cout << u << " " << D << " " << najdalej_fw[u] << " " << najdalej_bw[u] << "\n";

            D = max(D, najdalej_fw[u] - 1);
            D = max(D, najdalej_bw[u] - 1);
            D = max(D, 0);

            odp = min(odp, make_pair(D, u));
        }
        for(int v : ulica_fw[u]) {
            Queue.push(make_tuple(najdalej_fw[v] + najdalej_bw[u] + 1, v));
        }
    }

    cout << odp.second << " " << odp.first - 2 << "\n";

    return 0;
}