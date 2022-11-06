#include <iostream>
#include <queue>
#include <set>

#define NieMa 0
#define Krawcow -1
#define Szwaczek 1
#define Druga(x) x*-1

int n, m; //liczba miast, liczb drog
std::set<int>* drogi; //graf drog

int* gildie; //jaka gildia znajduje sie w danym miescie
std::queue<int> kolejka; //kolejka miast do przeanalizowania

int main(){

    std::cin >> n >> m;
    drogi = new std::set<int> [n];
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        drogi[a].insert(b);
        drogi[b].insert(a);
    }

    gildie = new int [n];
    for(int i = 0; i < n; i++) gildie[i] = NieMa;
    
    int itr = 0;
    while(true){
        if(!kolejka.empty()){
            int teraz = kolejka.front();
            kolejka.pop();
            for(std::set<int>::iterator i = drogi[teraz].begin(); i != drogi[teraz].end(); ++i){
                if(gildie[*i] != NieMa) continue;
                gildie[*i] = Druga(gildie[teraz]);
                kolejka.push(*i);
            }
        }
        else{
            while(itr < n && gildie[itr] != NieMa) itr++;
            if(itr >= n) break;
            if(drogi[itr].empty()){
                std::cout << "NIE\n";
                return 0;
            }
            gildie[itr] = Krawcow;
            kolejka.push(itr);
        }
    }

    std::cout << "TAK\n";
    for(int i = 0; i < n; i++){
        if(gildie[i] == Krawcow) std::cout << "K\n";
        else if(gildie[i] == Szwaczek) std::cout << "S\n";
    }

    //system("pause");
    return 0;
}