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
        all[itr] = ans[itr];
        ptr0 = nullptr;
        ptr1 = nullptr;
    }

    ~Tree(){
        if(ptr0 != nullptr) delete ptr0;
        if(ptr1 != nullptr) delete ptr1;
    }

    void add(int _itr){
        Tree ** ptr_a = d[_itr] < d[itr] ? &ptr0 : &ptr1;
        if(*ptr_a == nullptr) *ptr_a = new Tree(_itr);
        else (*ptr_a)->add(_itr);
        all[itr] = ans[itr];
        if(ptr0 != nullptr) all[itr] = min(all[itr], all[ptr0->itr]);
        if(ptr1 != nullptr) all[itr] = min(all[itr], all[ptr1->itr]);
    }

    void rmv(int _itr){
        if(_itr == itr) ans[itr] = infty;
        else {
            if(d[_itr] < d[itr]){ if(ptr0 != nullptr) ptr0->rmv(_itr); }
            else { if(ptr1 != nullptr) ptr1->rmv(_itr); }
        }
        all[itr] = ans[itr];
        if(ptr0 != nullptr) all[itr] = min(all[itr], all[ptr0->itr]);
        if(ptr1 != nullptr) all[itr] = min(all[itr], all[ptr1->itr]);
    }

    int query(int lim){
        int answer = infty;
        if(d[itr] <= lim){
            if(ptr0 != nullptr) answer = min(answer, all[ptr0->itr]);
            if(ptr1 != nullptr) answer = min(answer, ptr1->query(lim));
        }
        else if(ptr0 != nullptr) answer = min(answer, ptr0->query(lim));
        return answer;
    }

    void print(std::string pad = ""){
        std::cout << pad << itr << "\n";
        std::string nextpad = "  " + pad;
        if(ptr0 != nullptr) ptr0->print(nextpad);
        else std::cout << nextpad << "-\n";
        if(ptr1 != nullptr) ptr1->print(nextpad);
        std::cout << nextpad << "-\n";
    }

} * lemon_tree;

int main(){
    
    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> d[i];

    std::cin >> q;
    while(q--){
        std::cin >> k;

        ans[n-1] = 0;
        lemon_tree = new Tree(n-1);

        for(int i = n - 2; i >= 0; --i){
            for(int i = 0; i < n; ++i) std::cout << all[i] << " ";
            std::cout << "\n";

            int ans_not = lemon_tree->query(d[i]);
            int ans_can = lemon_tree->query(infty) + 1;
            ans[i] = min(ans_not, ans_can);

            lemon_tree->add(i);
            if(i + k < n) lemon_tree->rmv(i + k);
        }

        /*std::cout << "############\n";
        lemon_tree->print();       
        std::cout << "############\n";*/


        std::cout << ans[0] << "\n";
        delete lemon_tree;
    }

    return 0;
}