#include <iostream>

class Tree {
    int hold;
    int size;
    Tree * ptr0;
    Tree * ptr1;

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
    std::cout << "Hello, world!\n";
    return 0;
}