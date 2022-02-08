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
int lazy[plus]{};
int access(int itr) {
    itr += plus;
    for(int shf = 20; shf >= 1; --shf) {
        int the_itr = itr >> shf;
        if(the_itr == 0) continue;

        if(lazy[the_itr]) {
            around[the_itr] = max(around[the_itr], lazy[the_itr]);
            if(the_itr * 2 < plus) {
                lazy[the_itr * 2] = max(lazy[the_itr * 2], lazy[the_itr]);
                lazy[the_itr * 2 + 1] = max(lazy[the_itr * 2 + 1], lazy[the_itr]);
            }
            else {
                around[the_itr * 2] = max(around[the_itr * 2], lazy[the_itr]);
                around[the_itr * 2 + 1] = max(around[the_itr * 2 + 1], lazy[the_itr]);
            }
        }

        lazy[the_itr] = 0;
    }
    return around[itr];
}

void range_update(int itr, int jtr, int val) {
    access(itr);
    access(jtr);

    itr += plus;
    jtr += plus;

    while(itr / 2 != jtr / 2) {
        around[itr] = max(around[itr], val);
        around[jtr] = max(around[jtr], val);

        if(itr % 2 == 0) {
            if(itr < plus) lazy[itr + 1] = max(lazy[itr + 1], val);
            else around[itr + 1] = max(around[itr + 1], val);
        }
        if(jtr % 2 == 1) {
            if(jtr < plus) lazy[jtr - 1] = max(lazy[jtr - 1], val);
            else around[jtr - 1] = max(around[jtr - 1], val);
        }
        itr /= 2;
        jtr /= 2;
    }
    
    around[itr] = max(around[itr], val);
    around[jtr] = max(around[jtr], val);
    itr /= 2;

    while(itr){
        around[itr] = max(around[itr], val);
        itr /= 2;
    }
}

int range_query(int itr, int jtr) {
    access(itr);
    access(jtr);

    itr += plus;
    jtr += plus;

    int answer = max(around[itr], around[jtr]);

    while(itr / 2 != jtr / 2) {
        if(itr % 2 == 0) {
            answer = max(answer, around[itr + 1]);
            if(itr < plus) answer = max(answer, lazy[itr + 1]);
        }
        if(jtr % 2 == 1) {
            answer = max(answer, around[jtr - 1]);
            if(jtr < plus) answer = max(answer, lazy[jtr - 1]);
        }

        itr /= 2;
        jtr /= 2;
    }

    return answer;
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

    /*range_update(1, 3, 2);
    range_update(2, 4, 3);
    range_update(0, 3, 1);

    std::cout << access(0) << "\n";
    std::cout << access(1) << "\n";
    std::cout << access(2) << "\n";
    std::cout << access(3) << "\n";
    std::cout << access(4) << "\n";
    std::cout << access(5) << "\n\n";

    std::cout << range_query(1, 2) << "\n"; //3
    std::cout << range_query(0, 1) << "\n"; //2
    std::cout << range_query(3, 3) << "\n"; //3
    std::cout << range_query(0, 0) << "\n"; //1
    std::cout << range_query(3, 7) << "\n"; //3*/

    /*around[plus] = 3;
    around[plus + 1] = 6;
    around[plus + 2] = 2;
    lazy[plus / 2] = 5;
    lazy[plus / 4] = 4;

    std::cout << access(0) << "\n";
    std::cout << access(1) << "\n";
    std::cout << access(2) << "\n";*/

    for(int i = 0; i < n; ++i)
        std::cout << "[" << before[i] << "|" << after[i] << "] ";
    std::cout << "\n";

    for(int i = 0; i < n; ++i)
        std::cout << "[" << major_before[i] << "|" << major_after[i] << "] ";
    std::cout << "\n";

    return 0;
}