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

class Tree {
    int itr; // index of the forest-tree in whole sequence
    int hgt; // height of the forest-tree
    //int ans; // answer to the problem when starting at itr
    
    //int all; // minimum of answers over this node and all its children

    int size; // number of nodes - this one and all its children
    Tree * ptr0; // pointer to left subtree
    Tree * ptr1; // pointer to right subtree

    public:
    
    Tree(int _itr, int _hgt){
        itr = _itr;
        hgt = _hgt;
        size = 1;
        ptr0 = nullptr;
        ptr1 = nullptr;
    }

    void add(int _itr, int _hgt){
        Tree ** ptr_a = _hgt < hgt ? &ptr0 : &ptr1;
        if(*ptr_a == nullptr) *ptr_a = new Tree(_itr, _hgt);
        else (*ptr_a)->add(_itr, _hgt);
    }

    void rmv(int _itr, int _hgt){
        if(_hgt == hgt && _itr == itr){
            if(ptr0 == nullptr && ptr1 == nullptr) size = 0;
            else if(ptr1 == nullptr) *this = *ptr0;
            else if(ptr1->ptr0 == nullptr){
                ptr1->ptr0 = ptr0;
                *this = *ptr1;
            }
        }
        else {
            if(_hgt < hgt) ptr0->rmv(_itr, _hgt);
            else ptr1->rmv(_itr, _hgt);
        }
        if(ptr0 != nullptr && ptr0->size == 0) ptr0 = nullptr;
        if(ptr1 != nullptr && ptr1->size == 0) ptr1 = nullptr;
    }
};

int main(){
    Tree * my_tree = new Tree(8, 1);
    std::cout << "Hello, world!\n";
    return 0;
}