#include <iostream>

const int max_n = 1e6 + 20;
const int infty = 1e9 + 50;

int n, k, q;
int height[max_n];
int answer[max_n];
int subans[max_n];

inline int min(int x, int y) {
    return x < y ? x : y;
}

class Tree {
    int itr;
    Tree * ptr0;
    Tree * ptr1;

    public:

    Tree(int jtr) {
        itr = jtr;
        subans[itr] = answer[jtr];
        ptr0 = nullptr;
        ptr1 = nullptr;
    }

    ~Tree() {
        delete ptr0;
        delete ptr1;
    }

    void add(int jtr) {
        Tree ** ptrp = height[jtr] < height[itr] ? &ptr0 : &ptr1;
        if(*ptrp == nullptr) *ptrp = new Tree(jtr);
        else (*ptrp)->add(jtr);
        subans[itr] = min(subans[itr], subans[(*ptrp)->itr]);        
    }

    int query(int lim) {
        int ans = infty;
        if(height[itr] <= lim) {
            if(ptr0 != nullptr) ans = min(ans, subans[ptr0->itr]);
            if(ptr1 != nullptr) ans = min(ans, ptr1->query(lim));
            if(ptr0 == nullptr && ptr1 == nullptr) ans = min(ans, subans[itr]);
        }
        else if(ptr0 != nullptr) ans = min(ans, ptr0->query(lim));
        return ans;
    }
} * lemon_tree;

int main() {

    height[1] = 1;
    answer[1] = 7;

    height[2] = 2;
    answer[2] = 5;
    
    height[3] = 3;
    answer[3] = 3;
    
    height[4] = 4;
    answer[4] = 4;
    
    height[5] = 5;
    answer[5] = 6;
    
    height[6] = 6;
    answer[6] = 3;
    
    height[7] = 7;
    answer[7] = 2;
    
    lemon_tree = new Tree(5);
    lemon_tree->add(2);
    lemon_tree->add(3);
    lemon_tree->add(7);
    lemon_tree->add(1);
    lemon_tree->add(4);
    lemon_tree->add(6);

    std::cout << lemon_tree->query(4) << "\n";
    std::cout << (lemon_tree->query(6) == 3) << "\n";
    std::cout << (lemon_tree->query(7) == 3) << "\n";
    std::cout << (lemon_tree->query(2) == 7) << "\n";
    std::cout << lemon_tree->query(8) << "\n";

    std::cin >> n;
    for(int i = 0; i < n; ++i)
        std::cin >> height[i];
    
    std::cin >> q;
    while(q--) {
        std::cin >> k;


    }

    return 0;
}