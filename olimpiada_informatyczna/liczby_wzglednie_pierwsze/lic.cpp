// Jan Zakrzewski

#include <iostream>
#include <algorithm>

typedef unsigned long long ull;

const ull maxN = 1e14 + 20;

ull n;
ull k, c;

const int maxP = 20;

ull primes[maxP];
int P = 0;

// ile liczb w przedziale [0, m] jest wzglednie pierwszych z n
ull get_coprime(ull m) {
    ull answer = 0;
    int two2P = 1 << P;
    for(int itr = 0; itr < two2P; ++itr) {
        ull nmb = 1;
        ull sgn = 1;
        for(int j = 0; j < P; ++j) {
            bool ok = (bool)((itr >> j) & 0x1);
            if(!ok) continue;
            nmb *= primes[j];
            sgn *= -1;
        }
        nmb = m / nmb;
        answer += sgn * nmb;
    }
    return answer;
}

//szukamy najwiekszego answer takiego, ze get_coprime(answer) <= x
//zakladamy, ze w dowolnym momencie get_coprime(p) <= x < get_coprime(q)
//oraz, ze 0 <= p < q
ull search(ull x) {
    ull p = 0, q = maxN * 2, mid;
    while(q - p > 1) {
        mid = (p + q) / 2;
        if(get_coprime(mid) <= x) p = mid;
        else q = mid;
    }
    return p;
}

ull gcd(ull x, ull y) {
    if(y == 0) return x;
    else return gcd(y, x % y);
}

int main() {

    //std::ios_base::sync_with_stdio(0);
    //std::cin.tie(0);
    //std::cout.tie(0);

    std::cin >> n >> k >> c;
    //n = 304250263527210LL;
    //n = 30;

    // wyliczanie dzielnikow pierwszych
    {
        ull n0 = n;
        for(ull d = 2; d * d <= n; ++d) {
            if(n0 % d) continue;
            primes[P++] = d;
            while(n0 % d == 0) n0 /= d;
        }
        if(n0 != 1) primes[P++] = n0;
    }

    ull itr = search(k - 1) + 1;

    while(c) {
        if(gcd(itr, n) == 1) {
            std::cout << itr << " ";
            c--;
        }
        ++itr;
    }
    std::cout << "\n";

    /*std::cout << gcd(12, 20) << "\n"; // 4
    std::cout << get_coprime(10) << "\n"; // 2
    std::cout << get_coprime(12) << "\n"; // 3
    std::cout << get_coprime(13) << "\n"; // 4
    std::cout << get_coprime(30) << "\n"; // 8
    std::cout << search(4 - 1) + 1 << "\n"; // 13
    std::cout << search(5 - 1) + 1 << "\n"; // 17
    std::cout << search(6 - 1) + 1 << "\n"; // 19
    std::cout << search(7 - 1) + 1 << "\n"; // 23
    std::cout << search(8 - 1) + 1 << "\n"; // 29*/

    return 0;
}