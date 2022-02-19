#include <iostream>

const int maxP = 20;
typedef unsigned long long ull;

ull n;

int p;
ull primes[maxP];
ull answer = 0;

int log(ull);

int main() {

    std::cin >> n >> p;
    for(int i = 0; i < p; ++i) std::cin >> primes[i];

    for(int itr = 1; itr < (1 << p); ++itr) {
        ull nmb = 1;
        ull sgn = -1;
        for(int k = 0; k < p; ++k) {
            if((itr >> k) % 2 == 0) continue;
            sgn *= -1;
            if(log(nmb) + log(primes[k]) >= 60) nmb = 0;
            nmb *= primes[k];
        }
        if(nmb) answer += sgn * (n / nmb);
    }

    std::cout << answer << "\n";

    return 0;
}

int log(ull x) {
    int ans = 0;
    while(x) {
        x /= 2;
        ++ans;
    }
    --ans;
    return ans;
}