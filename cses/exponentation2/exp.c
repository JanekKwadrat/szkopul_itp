#include <stdio.h>

typedef long long lli;

const lli modP = 1e9 + 7;
const lli modPhi = 1e9 + 6;

lli power(lli a, lli k, lli M) {
    lli ans = 1;
    while(k) {
        if(k % 2) ans = ans * a % M;
        a = a * a % M;
        k /= 2;
    }
    return ans;
}

int q;
lli a, b, c;
lli zns, ans;

int main() {

    scanf("%ld", &q);
    while(q--) {
        scanf("%lld %lld %lld", &a, &b, &c);
        zns = power(b, c, modPhi);
        ans = power(a, zns, modP);
        printf("%lld\n", ans);
    }

    return 0;
}