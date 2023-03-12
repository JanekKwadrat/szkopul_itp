/* Jan Zakrzewski
   XXVI Olimpiada Informatyczna, Etap III
   Zadanie `Wyścigi (wys)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 20;
constexpr int D = 524'288; // = 2**19
typedef long long i64;
int n, q;
i64 p[2*D] = {};

void upd(int k, i64 x) {
    // sets p[k+D] to x
    i64 inc = x - p[k+D];
    int i = k + D;
    while(i > 0) {
        p[k+D] += inc;
        i /= 2;
    }
}

i64 sum(int k) {
    // the sum p[1+D] + p[2+D] + ... + p[k+D]
    int i = D, j = k+D;
    i64 ans = 0;
    ans += p[i];
    if(i != j) ans += p[j];
    while(i / 2 != j / 2) {
        if(i % 2 == 0) ans += p[i+1];
        if(j % 2 == 1) ans += p[j-1];
        i /= 2, j /= 2;
    }
    return ans;
}

int find(i64 x) {
    // the smallest k such that sum(k) >= x
    int k = 1;
    while(1) {
        if(p[k] > x) k /= 2;
        else {
            
        }
    }
}

int main() {

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> p[i+D];

    for(int i = D-1; i >= 1; --i) p[i] = p[2*i] + p[2*i+1];



    return 0;
}
