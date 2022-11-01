/*
    Jan Zakrzewski
    XXI Olimpiada Informatyczna, Etap II
    Zadanie Karty (kar)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 201'050;
constexpr int D = 262'144; // = 2^18
constexpr int BIG = 100'000'000;
constexpr int INF = 200'000'000;

struct Func {
    int A, B;
    int a, b;
};

Func circle(Func f, Func g) {
    Func ans = f;
         if(f.b <= g.a) ans.b = g.b;
    else if(f.b <= g.A) ans.b = g.B;
    else                ans.b = INF;
         if(f.B <= g.a) ans.B = g.b;
    else if(f.B <= g.A) ans.B = g.B;
    else                ans.B = INF;
    return ans;
}

Func make_Func(int a, int A) {
    Func f;
    f.a = a, f.b = a;
    f.A = A, f.B = A;
    return f;
}

int n, q;
Func arr[2 * D];

void arr_init() {
    int itr = D;
    while(true) {
        --itr;
        if(itr == 0) break;
        arr[itr] = circle(arr[2*itr], arr[2*itr+1]);
    }
}

inline void arr_set(int itr, Func f) {
    arr[itr + D] = f;
}

void arr_update(int itr) {
    itr += D;
    while(true) {
        itr /= 2;
        if(itr == 0) break;
        arr[itr] = circle(arr[2*itr], arr[2*itr+1]);
    }
}

inline Func arr_all() {
    return arr[1];
}

void arr_swap(int itr, int jtr) {
    swap(arr[itr + D], arr[jtr + D]);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        arr_set(i, make_Func(x, y));
    }
    for(int i = n; i < D; ++i) {
        arr_set(i, make_Func(BIG, BIG));
    }
    arr_init();

    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        arr_swap(a, b);
        arr_update(a);
        arr_update(b);
        bool ok = arr_all().b < INF;
        if(ok) cout << "TAK\n";
        else cout << "NIE\n";
    }

    return 0;
}