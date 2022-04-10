#include <iostream>

constexpr int max_n = 2005;

int n, k;   
int butelka;
int najlepsza = 3000;
int koszt;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            std::cin >> butelka;
            koszt = j * (i - j + 1);
            if(koszt > k) continue;
            if(butelka < najlepsza) najlepsza = butelka;
        }
    }
    std::cout << najlepsza << "\n";

    return 0;
}