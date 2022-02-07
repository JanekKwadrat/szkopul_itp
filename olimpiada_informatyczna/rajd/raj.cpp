/* 
 * Zadanie: Rajd (XXI OI, etap drugi)
 * Jan Zakrzewski, rozwiazanie
 * 
 * Pomysly: przyporzadkowac kazdemu wierzcholkowi ile go poprzedza i ile jest po nim,
 * czyli jakas pare [a|b]. Najdluzsze trasy przechodza przez te wierzcholki, ze a+b jest najdluzsze (wierzcholki glowne).
 * Interesuja nas tylko te wierzcholki glowne, ze [a|b] jednoznacznie je okresla (wierzcholki ciekawe).
 * Trzeba znac dlugosc najlepszego objazdu danego ciekawego wiezcholka. Przez objazd ciekawego wierzcholka [a|b] rozumiemy trase z [0|a+b] do [a+b|0],
 * ktora jest krotsza niz a+b i nie przechodzi przez [a|b].
 * Jak policzyc ile jest objazdow danego skrzyzowania? Moze sprobowac przy liczeniu par ciekaych [a|b] liczyc druga najlepsza trase?
 * Chyba tak - dla kazdego pobocznego wierzcholka liczymy ile jest wierczholkow glownych przed nim i po nim. To pozwala stwierdzic do ktorych wierzcholkow
 * glownych jest on rownolegly, a zatem stanowi czesc objazdu. Pozniej trzeba dokonczyc robote drzewem przedzialowym.
 */

#include <iostream>
#include <set>
#include <queue>

const int max_n = 5e5 + 20;

int n, m;
std::set<int> road[max_n]; 
int before[max_n]{};
int after[max_n]{};
int helpful[max_n]{};
std::queue<int> think;
bool seen[max_n]{};

int main() {

    std::cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        road[u].insert(v);
        ++helpful[v];
    }

    for(int i = 0; i < n; ++i) {
        if(helpful[i]) continue;
        if(seen[i]) continue;

        think.push(i);
        while(!think.empty()) {
            int brought = think.front();
            think.pop();

            for(auto itr : road[brought]) {
                
            }
        }
    }

    return 0;
}