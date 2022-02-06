/* 
 * Zadanie ptaszek (XXI OI, etap II, dzien drugi)
 * Jan Zakrzewski, rozwiazanie
 * 
 * Pomysl: dynamiczne drzewo przedzialowe z programowaniem dynamicznym
 * (przechowujace wyniki, a segregowane wedlug wysokosci)
 */

#include <iostream>

class Tree {
    int hold; // value held in node
    int size; // number of nodes - this one and all its children
    Tree * ptr0; // pointer to left subtree
    Tree * ptr1; // pointer to right subtree

    public:
    
    Tree(int x){
        hold = x;
        size = 1;
        ptr0 = nullptr;
        ptr1 = nullptr;
    }

    int add(int x){
        int wh = 0;
        if(x < hold){
            if(ptr0 == nullptr) ptr0 = new Tree(x);
            else wh += ptr0->add(x);
        }
        else {
            if(ptr1 == nullptr) ptr1 = new Tree(x);
            else wh += ptr1->add(x);
            if(ptr0 != nullptr)
                wh += ptr0->size;
            ++wh;
        }
        ++size;
        return wh;
    }
};

int main(){
    Tree * my_tree = new Tree(8);
    my_tree->add(5);
    my_tree->add(10);
    my_tree->add(9);
    my_tree->add(6);
    my_tree->add(4);
    my_tree->add(11);
    std::cout << my_tree->add(7) << "\n";
    std::cout << my_tree->add(12) << "\n";
    std::cout << "Hello, world!\n";
    return 0;
}