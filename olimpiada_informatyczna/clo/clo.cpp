/*
 * Zadanie: Clo (XV Olimpiada Informatyczna, etap pierwszy)
 * Jan Zakrzewski, rozwiazanie
 * Pomysl: szukamy drzew rozpinajacych nad wszystkimi spojnymi czesciami grafu.
 * Dla kazdej czesci spojnej szukamy przy najmniej jednej krawedzi niebedacej czescia jej drzewa rozpinajacego.
 * Nastepnie iterujem sie zaczynajac od konca tej krawedzi.
 */

#include <iostream>
#include <map>
#include <queue>

const int max_n = 1e5 + 20;
const int max_m = 1e5 + 20;
const int none = -69;

int n, m;
std::map<int, bool> roadmap[max_n];

std::queue<int> think;
bool seen[max_n];

int answer[max_n];
int not_ok;

int main() {

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        roadmap[u][v] = false;
        roadmap[v][u] = false;
    }

    //std::cout << "\n";

    for(int i = 0; i < n; ++i) seen[i] = false;

    for(int i = 0; i < n; ++i) {
        if(seen[i]) continue;
        think.push(i);
        seen[i] = true;
        while(!think.empty()) {
            int u = think.front();
            think.pop();

            for(auto [v, good] : roadmap[u]) {
                if(seen[v]) continue;
                seen[v] = true;
                roadmap[u][v] = true;
                roadmap[v][u] = true;
                //std::cout << u + 1 << " " << v + 1 << "\n";
                think.push(v);
            }
        }
    }

    for(int i = 0; i < n; ++i) answer[i] = none;
    not_ok = n;

    for(int i = 0; i < n; ++i) {

        for(auto [j, good] : roadmap[i]) {
            
            if(good) continue;
            if(answer[j] != none) continue;

            answer[j] = i;
            --not_ok;
            think.push(j);
            break;
        }

        while(!think.empty()) {
            int u = think.front();
            think.pop();

            for(auto [v, good] : roadmap[u]) {
                if(!good) continue;
                if(answer[v] != none) continue;
                answer[v] = u;
                --not_ok;
                think.push(v);
            }
        }
    }


    //std::cout << not_ok << "\n";
    if(not_ok) std::cout << "NIE\n";
    else {
        std::cout << "TAK\n";
        for(int i = 0; i < n; ++i)
            std::cout << answer[i] + 1 << "\n";
    }

    return 0;
}