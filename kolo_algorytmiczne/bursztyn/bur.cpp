#include <iostream>
#include <algorithm>

typedef unsigned long long u64;
typedef signed long i32;
constexpr i32 MAX_N = 1020;

i32 m, n, k;
u64 array[MAX_N][MAX_N];

i32 i, j;
u64 ans = 0;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> k;
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
            std::cin >> array[i][j];
    for(i = 0; i < n; ++i)
        for(j = 1; j < m; ++j)
            array[i][j] += array[i][j-1];
    for(i = 1; i < n; ++i)
        for(j = 0; j < m; ++j)
            array[i][j] += array[i-1][j];
    for(i = k; i < n; ++i)
        for(j = k; j < n; ++j) {
            if(i == k && j == k) ans = std::max(ans, array[i-1][j-1]);
            else if(i == k) ans = std::max(ans, array[i-1][j-1] - array[i-1][j-k-1]);
            else if(j == k) ans = std::max(ans, array[i-1][j-1] - array[i-k-1][j-1]);
            else ans = std::max(ans, array[i-1][j-1] - array[i-k-1][j-1] - array[i-1][j-k-1] + array[i-k-1][j-k-1]);
        }
    std::cout << ans << "\n";
    return 0;
}