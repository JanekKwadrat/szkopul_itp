#include <iostream>
#include <vector>
#include <queue>

const int max_n = 1e6 + 20;
const int infty = 1e9 + 50;

int n, k, q;
int d[max_n];
int ans[max_n];

int main(){

    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> d[i];
    
    std::cin >> q;
    while(q--){
        std::cin >> k;

        ans[n - 1] = 0;
        for(int i = n - 2; i >= 0; --i){
            int ans_a = infty;
            int ans_b = infty;
            for(int j = i + 1; j <= i + k && j < n; ++j){
                ans_b = std::min(ans_b, ans[j]);
                if(d[j] >= d[i]) continue;
                ans_a = std::min(ans_a, ans[j]);
            }
            ++ans_b;
            ans[i] = std::min(ans_a, ans_b);
        }

        std::cout << ans[0] << "\n";
    }

    return 0;
}