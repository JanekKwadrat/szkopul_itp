 // Jan Zakrzewski

#include <iostream>

typedef long long int lli;

inline lli min(lli x, lli y) {
    return x < y ? x : y;
}

const lli max_n = 1e6 + 20;

lli n, a, b;
lli best[max_n]; // how fast can you reach this number of bots
lli answer;

int main() {

    std::cin >> n >> a >> b;
    a -= b;

    best[1] = 0;
    for(lli i = 2; i <= n && i < max_n; ++i) best[i] = INT64_MAX;

    for(lli itr = 1; itr < n && itr < max_n; ++itr) {
        if(best[itr] == INT64_MAX) continue;
        lli t = best[itr] + a + 2 * b;
        lli k = 2;
        lli jtr = itr * k;
        while(1) {
            if(jtr >= max_n) jtr = max_n - 1;
            if(jtr > n) jtr = n;
            best[jtr] = min(best[jtr], t);
            if(jtr == n || jtr == max_n - 1) break;
            t += b;
            ++k;
            jtr += itr;
        }
    }

    if(n < max_n) std::cout << best[n] << "\n";
    else {
        answer = INT64_MAX;
        lli k_min = a / b - 3;
        lli k_max = a / b + 3;
        if(k_min < 2) k_min = 2; 
        if(k_max < 2) k_max = 2; 
        for(lli itr = 1; itr < max_n; ++itr) {
            //if(itr % 10000 == 0) std::cout << itr / 10000 << "\n";
            if(best[itr] == INT64_MAX) continue;
            for(lli k = k_min; k <= k_max; ++k) {
                //std::cout << k << "\n";
                lli t = best[itr];
                lli dt = a + k * b;
                lli nmb = 1;
                while(nmb <= n) {
                    //std::cout << nmb << "\n";
                    t += dt;
                    nmb *= k;
                }
                answer = min(answer, t);
            }
        }
        std::cout << answer << "\n";
    }

    return 0;
}