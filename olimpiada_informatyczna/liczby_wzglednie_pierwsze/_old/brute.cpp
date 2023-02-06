 // Jan Zakrzewski

#include <iostream>

const int max_n = 5e7;
const int M = 5e7;
int n, k, l;
bool array[max_n];
int numbers[max_n];
int top = 0;

int main() {

    std::cin >> n >> k >> l;
    --k;
    l += k;

    for(int i = 0; i < M; ++i) array[i] = true;
    for(int itr = 2; itr <= n; ++itr) {
        if(!array[itr]) continue;
        if(n % itr) continue;
        for(int jtr = itr; jtr < M; jtr += itr) array[jtr] = false;
    }

    for(int i = 1; i < M; ++i) if(array[i]) numbers[top++] = i;

    for(int i = k; i < l; ++i)
        std::cout << numbers[i] << " ";
    std::cout << "\n";

    return 0;
}