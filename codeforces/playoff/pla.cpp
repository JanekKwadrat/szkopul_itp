#include <iostream>

int t, n;
int ans;

int main() {
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        if(n == 1) ans = 1;
        else ans = (1 << n) - 1;
        std::cout << ans << "\n";
    }

    return 0;
}