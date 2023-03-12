#include <iostream>
#include <algorithm>

extern "C" {

inline int str_diff(char* a, char* b) {
    // returns index of a and b first difference
    int i;
    for(i = 0; 1; ++i) {
        if(a[i] != b[i]) return i;
        if(a[i] == 0) return -1;
    }
}

inline int str_less(char* a, char* b) {
    // returns 1 if a is lexicographicly smaller than b, and 0 otherwise
    int itr = str_diff(a, b);
    return a[itr] < b[itr];
}

}

int main() {

    

    return 0;
}