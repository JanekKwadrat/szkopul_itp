/* 
 * Zadanie ptaszek (XXI OI, etap II, dzien drugi)
 * Jan Zakrzewski, rozwiazanie
 * 
 * Pomysl: dynamiczne drzewo przedzialowe z programowaniem dynamicznym
 * (przechowujace wynikiki, a segregowane wedlug wysokosci)
 */

#include <iostream>

inline int min(int x, int y){
    return x < y ? x : y;
}

const int max_n = 1e6 + 20;
const int infty = 1e9 + 50;

int n, k, q;
int d[max_n];

int ans[max_n];
int all[max_n];

class Tree {
    int itr;
    Tree * ptr0; // pointer to left subtree
    Tree * ptr1; // pointer to right subtree

    public:
    
    Tree(int _itr){
        itr = _itr;
        ptr0 = nullptr;
        ptr1 = nullptr;
    }

    ~Tree(){
        if(ptr0 != nullptr) delete ptr0;
        if(ptr1 != nullptr) delete ptr1;
    }

    inline void make_all(){
        all[itr] = ans[itr];
        if(ptr0 != nullptr) all[itr] = min(all[itr], all[ptr0->itr]);
        if(ptr1 != nullptr) all[itr] = min(all[itr], all[ptr1->itr]);
    }

    void add(int _itr){
        Tree ** ptr_a = d[_itr] < d[itr] ? &ptr0 : &ptr1;
        if(*ptr_a == nullptr) *ptr_a = new Tree(_itr);
        else (*ptr_a)->add(_itr);
        make_all();
    }

    void rmv(int _itr){
        if(_itr == itr) ans[itr] = infty;
        else {
            if(d[_itr] < d[itr]){ if(ptr0 != nullptr) ptr0->rmv(_itr); }
            else { if(ptr1 != nullptr) ptr1->rmv(_itr); }
        }
        make_all();
    }

    int query(int lim){
        if(d[itr] < lim) return all[itr];
        else if(ptr0 == nullptr) return 0;
        else return ptr0->query(lim);
    }
};

int main(){
    
    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> d[i];

    std::cin >> q;
    while(q--){
        std::cin >> k;

        ans[n-1] = 0;
    }

    return 0;
}