#include <bits/stdc++.h>
using namespace std;

class Quo {
public:
    int a, b;
    Quo(int aa = 0, int bb = 1) { 
        a = aa, b = bb;
    }
    operator double() {
        return (double) a / (double) b;
    }
    bool operator<(Quo oth) {
        return (long long) a * oth.b < (long long) oth.a * b;
    }
};

Quo min(Quo x, Quo y) {
    if(x < y) return x;
    else return y;
}

Quo max(Quo x, Quo y) {
    if(x < y) return y;
    else return x;
}

constexpr int N = 5e5 + 20;
int n, k;
int p[N]; // p[i] = jaki jest przełożony i-tego pracownika
int S[N]; // s[i] = ilu podwładnych ma i-ty pracownik (pośrednich i bezpośrednich)
Quo z[N]; // z[i] = jakie musi być minimalne morale, żeby nie zbuntował się i-ty pracownik i wszyscy jego podwładni
Quo ans;
// założenie: najgorzej kiedy sabotażysta jest liściem

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 2; i <= n; ++i) cin >> p[i];

    for(int i = 1; i <= n; ++i) S[i] = 0;
    for(int i = n; i >= 2; --i) S[p[i]] += S[i] + 1;

    for(int i = 1; i <= n; ++i) {
        if(S[i] > 0) z[i] = Quo(0, 1);
        else z[i] = Quo(1, 1);
    }
    for(int i = n; i >= 2; --i) {
        z[p[i]] = max(z[p[i]], min(z[i], Quo(S[i]+1, S[p[i]])));
    }

    ans = Quo(0, 1);
    for(int i = 1; i <= n; ++i) {
        if(S[i]+1 > k) ans = max(ans, z[i]);
    }

    cout << setprecision(14) << (double) ans << "\n";

    return 0;
}