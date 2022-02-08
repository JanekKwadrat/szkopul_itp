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
const int plus = 512 * 1024;

int n, m;

std::set<int> roadmap_forward[max_n]; 
std::set<int> roadmap_backward[max_n]; 

int before[max_n]{};
int after[max_n]{};

int major_before[max_n]{};
int major_after[max_n]{};

int memory[10 * max_n];
int mem_top = 0;

int longest = 0;

std::queue<int> think;

inline int max(int x, int y) { return x > y ? x : y; }

int around[2 * plus]{};
bool lazy[plus]{};
int _access(int itr) {
    int shift;
    while(true){
        if(shift < 0) break;
        if(itr >> shift == 0) continue;

        if(lazy[])
    }
}
void update(int itr, int jtr, int val) {
    itr += plus;
    while(itr){
        
    }
}

int main() {

    std::cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        roadmap_forward[u].insert(v);
        roadmap_backward[v].insert(u);
    }

    {
        int * incoming = &memory[mem_top];
        mem_top += max_n;

        for(int i = 0; i < n; ++i) {
            incoming[i] = roadmap_backward[i].size();
            if(incoming[i] == 0)
                think.push(i);
        }

        while(!think.empty()) {
            int itr = think.front();
            think.pop();
            for(auto jtr : roadmap_forward[itr]) {
                before[jtr] = max(before[jtr], before[itr] + 1);
                --incoming[jtr];
                if(incoming[jtr] == 0)
                    think.push(jtr);
            }
        }

        mem_top -= max_n;
    }

    {   
        int * outgoing = &memory[mem_top];
        mem_top += max_n;

        for(int i = 0; i < n; ++i) {
            outgoing[i] = roadmap_forward[i].size();
            if(outgoing[i] == 0)
                think.push(i);
        }

        while(!think.empty()) {
            int itr = think.front();
            think.pop();
            for(auto jtr : roadmap_backward[itr]) {
                after[jtr] = max(after[jtr], after[itr] + 1);
                --outgoing[jtr];
                if(outgoing[jtr] == 0)
                    think.push(jtr);
            }
        }

        mem_top -= max_n;
    }

    for(int i = 0; i < n; ++i)
        longest = max(longest, before[i] + after[i]);

    {
        int * incoming = &memory[mem_top];
        mem_top += max_n;

        for(int i = 0; i < n; ++i) {
            incoming[i] = roadmap_backward[i].size();
            if(incoming[i] == 0){
                think.push(i);
                if(before[i] + after[i] == longest)
                    major_before[i] = 1;
            }
        }

        while(!think.empty()) {
            int itr = think.front();
            think.pop();
            for(auto jtr : roadmap_forward[itr]) {
                int inc = before[jtr] + after[jtr] == longest;
                major_before[jtr] = max(major_before[jtr], major_before[itr] + inc);
                --incoming[jtr];
                if(incoming[jtr] == 0)
                    think.push(jtr);
            }
        }

        mem_top -= max_n;
    }

    {
        int * outgoing = &memory[mem_top];
        mem_top += max_n;

        for(int i = 0; i < n; ++i) {
            outgoing[i] = roadmap_forward[i].size();
            if(outgoing[i] == 0){
                think.push(i);
                if(before[i] + after[i] == longest)
                    major_after[i] = 1;
            }
        }

        while(!think.empty()) {
            int itr = think.front();
            think.pop();
            for(auto jtr : roadmap_backward[itr]) {
                int inc = before[jtr] + after[jtr] == longest;
                major_after[jtr] = max(major_after[jtr], major_after[itr] + inc);
                --outgoing[jtr];
                if(outgoing[jtr] == 0)
                    think.push(jtr);
            }
        }

        mem_top -= max_n;
    }

    for(int i = 0; i < n; ++i)
        std::cout << "[" << before[i] << "|" << after[i] << "] ";
    std::cout << "\n";

    for(int i = 0; i < n; ++i)
        std::cout << "[" << major_before[i] << "|" << major_after[i] << "] ";
    std::cout << "\n";

    return 0;
}