#include <iostream>

int solve(int n, int k) {
    if(n == 1) return 0;
    if(k < n / 2) return 2 * k + 1;
    
    int ans = solve(n - n / 2, k - n / 2);
    if(n % 2) {
        if(ans == 0) return n - 1;
        else return (ans - 1) * 2;
    }
    else return ans * 2;
}

int q, n, k;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> q;
    while(q--) {
        std::cin >> n >> k;
        std::cout << solve(n, k - 1) + 1 << "\n";
    }
    return 0;
}