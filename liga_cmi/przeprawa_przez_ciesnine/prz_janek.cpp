#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 n;

inline i64 f(i64 x) {
    return x + (n + x - 1) / x;
}

i64 ternary_search() {
    i64 l = 1, r = n;
    while(r - l > 2) {
        i64 ll = l + (r - l) / 3;
        i64 rr = r - (r - l) / 3;
        if(f(ll) > f(rr)) l = ll;
        else r = rr;
    }
    i64 ans, val = INT64_MAX;
    for(i64 i = l; i <= r; ++i) if(f(i) < val) val = f(i), ans = i;
    return ans;
}

i64 brute_search() {
    i64 l = 1, r = n;
    i64 ans, val = INT64_MAX;
    for(i64 i = l; i <= r; ++i) {
        if(f(i) < val) {
            ans = i;
            val = f(i);
        }
    }
    return ans;
}

i64 nastka_search();

i64 wajcha_search() {
    i64 a = (i64)sqrt((long double)(n * 4));
    i64 ans, val = INT64_MAX;
    for(i64 i = max(a/2 - 20, 1ll); i <= a/2 + 20; ++i) if(f(i) < val) val = f(i), ans = i;
    return ans;
}

i64 binwajcha_search() {
    i64 a, b;
    
}

int main() {

    /*cin >> n;
    cout << f(brute_search()) << "\n";
    cout << f(ternary_search()) << "\n";
    cout << nastka_search() << "\n";
    cout << f(wajcha_search()) << "\n";*/

    for(i64 x = 2; x <= 100'000; ++x) {
        n = x;
        if(x % 1000 == 0) cout << x << " " << flush;
        i64 val = f(brute_search());
        //if(f(ternary_search()) != val) cout << "janek " << x << "\n";
        //if(nastka_search() != val) cout << "nastka " << x << "\n";
        if(f(wajcha_search()) != val) cout << "wajcha " << x << "\n";
    }
    //cout << "\n";

    return 0;
}

long long __nastka_search(long long L, long long R)
{
    long long m1 = L + (R-L)/3;
    long long m2 = R - (R-L)/3;

    if (m2 - m1 < 2)
    {
        return min((m1+n-1)/m1 + m1, (m2+n-1)/m2 + m2);
    }
    else if (m2 - m1 == 2)
    {
        return min({(m1+n-1)/m1 + m1, (m1+n)/(m1+1) + m1+1, (m2+n-1)/m2 + m2});
    }

    if ((m1+n-1)/m1 + m1 > (m2+n-1)/m2 + m2)
    {
        return __nastka_search(m1, R);
    }
    else if ((m1+n-1)/m1 + m1 < (m2+n-1)/m2 + m2)
    {
        return __nastka_search(L, m2);
    }
    else
    {
        return __nastka_search(m1, m2);
    }

}

long long nastka_search() {
    return __nastka_search(1, n+1);
}
