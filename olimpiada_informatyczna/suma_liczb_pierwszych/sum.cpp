#include <bits/stdc++.h>
using namespace std;

typedef unsigned int       u32;
typedef unsigned long long u64;
constexpr int N = 10'000'000;

int p;
u32 primes[N];

u64 n;

int main() {

    primes[0] = 0;
    primes[1] = 0;
    for(int i = 2; i < N; ++i) primes[i] = 1;
    for(int i = 2; i*i <= N; ++i) {
        if(!primes[i]) continue;
        for(int j = 2*i; j < N; j += i) primes[j] = 0;
    }

    p = 0;
    for(int i = 0; i < N; ++i) {
        if(!primes[i]) continue;
        primes[p] = i;
        p++;
    }

    cin >> n;

    int i = 0, j = 0;
    int sum = 2;
    while(1) {
        if(i >= p || j >= p) break;
        if(sum == n) break;
        if(sum < n) {
            j++;
            sum += primes[j];
        }
        else if(sum > n) {
            sum -= primes[i];
            i++;
        }
    }

    if(sum == n) {
        cout << primes[i] << " " << primes[j] << "\n";
    } else cout << "NIE\n";

    return 0;
}