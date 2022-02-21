#include <iostream>

const int N = 1e6 + 20;

int q, x;
int array[N];

int main() {
    
    for(int i = 2; i < N; ++i)
        array[i] = 0;
    
    for(int k = 2; k < N; ++k) {
        if(array[k]) continue;
        for(int m = k; m < N; m += k)
            array[m] = k;
    }

    array[1] = 1;

    for(int i = 2; i < N; ++i) {
        int nmb = i;
        int mult = 1;
        int div = array[i];
        while(!(nmb % div)) {
            nmb /= div;
            ++mult;
        }
        array[i] = array[nmb] * mult;
    }

    std::cin >> q;
    while(q--) {
        std::cin >> x;
        std::cout << array[x] << "\n";
    }

    return 0;
}