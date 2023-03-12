#include <iostream>

typedef unsigned int u32;
constexpr u32 max_n = 1020;
constexpr u32 limit = 1e9;

u32 t, n;
u32 arr[max_n];
bool ans;

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        ans = true;
        arr[0] = 1;
        for(u32 i = 1; i < n; ++i) {
            arr[i] = arr[i-1] * 3;
            if(arr[i] > limit) {ans = false; break;}
        }
        if(ans) {
            std::cout << "YES\n";
            for(int i = 0; i < n; ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n";
        }
        else std::cout << "NO\n";
    }

    return 0;
}