#include <bits/stdc++.h>
using namespace std;


constexpr int N = 1'000'200;
bool is_prime[N];
int ile_super[N];

int suma_dec(int x) {
    int ans = 0;
    while(x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int suma_bin(int x) {
    int ans = 0;
    while(x > 0) {
        ans += x % 2;
        x /= 2;
    }
    return ans;
}

int main() {

    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i < N; ++i) is_prime[i] = true;
    for(int i = 2; i*i <= N; ++i) {
        if(!is_prime[i]) continue;
        for(int j = 2*i; j < N; j += i) is_prime[j] = false;
    }

    for(int i = 0; i < N; ++i) ile_super[i] = 0;
    for(int i = 0; i < N; ++i) {
        if(!is_prime[i]) continue;
        if(!is_prime[suma_dec(i)]) continue;
        if(!is_prime[suma_bin(i)]) continue;
        ile_super[i]++;
    }
    for(int i = 1; i < N; ++i) ile_super[i] += ile_super[i-1];

    int a, b;
    cin >> a >> b;
    //cout << a  << "_" << b << "\n";
    int ans = ile_super[b] - ile_super[a-1];
    cout << ans << "\n";

    return 0;
}