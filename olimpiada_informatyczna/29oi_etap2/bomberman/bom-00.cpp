#include <iostream>

struct Boxes {
    int top;
    int x[2], y[2];
    bool sure_x, sure_y;
    int the_x, the_y;
    bool good;
    Boxes() {
        top = 0;
        sure_x = false;
        sure_y = false;
        good = true;
    }
    void add(int nx, int ny) {
        if(sure_x && sure_y) {
            if(!(nx == the_x || ny == the_y)) good = false;
            return;
        }
        if(sure_x) {
            if(nx == the_x) return;
            sure_y = true;
            the_y = ny;
            return;
        }
        if(sure_y) {
            if(ny == the_y) return;
            sure_x = true;
            the_x = nx;
            return;
        }
        if(top == 0) {
            x[0] = nx;
            y[0] = ny;
            ++top;
        }
        else if(top == 1) {
            if(nx == x[0]) {
                sure_x = true;
                the_x = nx;
            }
            if(ny == y[0]) {
                sure_y = true;
                the_y = ny;
            }
            ++top;
        }
        else if(top == 2) {
            if(nx == x[0]) {
                sure_x = true;
                sure_y = true;
                the_x = nx;
                the_y = y[1];
            }
            else if(ny == y[0]) {
                sure_x = true;
                sure_y = true;
                the_x = x[1];
                the_y = ny;
            }
            else if(nx == x[1]) {
                sure_x = true;
                sure_y = true;
                the_x = nx;
                the_y = y[0];
            }
            else if(ny == y[1]) {
                sure_x = true;
                sure_y = true;
                the_x = x[0];
                the_y = ny;
            }
            else good = false;
        } 
    }
} sth;

int main() {

    sth.add(1, 1);
    sth.add(5, 1);
    sth.add(3, 3);
    std::cout << (sth.the_x == 3 && sth.the_y == 1) << "\n";

    return 0;
}