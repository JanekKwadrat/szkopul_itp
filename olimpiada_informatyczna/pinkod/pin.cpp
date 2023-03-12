#include "hsm.h"

#include <iostream>

constexpr int N = 16;

int sure[N] = {};
int arr[N];
int pin[4];
int p, q, m;

int main() {

    pin[0] = 1, pin[1] = 1, pin[2] = 1, pin[3] = 1;

    inicjuj();

    q = N - 1;
    while(true) {
        p = -1;
        std::cout << p << " " << q << "\n";
        while(q - p > 1) {

            m = (p + q) / 2;
            for(int i = 0; i < N; ++i) arr[i] = sure[i];
            for(int i = 0; i < m; ++i) arr[i] = arr[i] | 1;

            std::cout << "[ ";
            for(int i = 0; i < N; ++i) std::cout << arr[i] << " ";
            std::cout << "]";
            
            int t = sprawdz(pin, arr);
            if(t) q = m;
            else p = m;

            std::cout << " " << t << "\n";
        }
        sure[q] = 1;
        if(q == 0) break;
        --q;
    }


    std::cout << "[ ";
    for(int i = 0; i < N; ++i) std::cout << sure[i] << " ";
    std::cout << "]\n";

    return 0;
}