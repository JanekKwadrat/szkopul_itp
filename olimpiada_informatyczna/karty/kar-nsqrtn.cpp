#include <iostream>
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 201'050;
constexpr int P = 500;
//constexpr int p = 447; //447;
int p;
constexpr int BIG = 100'000'000;
constexpr int INF = 200'000'000;

int n, q, L;
int M[N], m[N];
int O[P], o[P];

void update(int k) {
    int itr = p*k;
    O[k] = M[itr];
    o[k] = m[itr];
    ++itr;
    while(itr < p * (k+1)) {
             if(m[itr] >= O[k]) O[k] = m[itr];
        else if(M[itr] >= O[k]) O[k] = M[itr];
        else                    O[k] = INF;
             if(m[itr] >= o[k]) o[k] = m[itr];
        else if(M[itr] >= o[k]) o[k] = M[itr];
        else                    o[k] = INF;
        ++itr;
    }
}

bool verify() {
    int x = 0;
    int itr = 0;
    while(itr < L) {
             if(m[p*itr] >= x) x = o[itr];
        else if(M[p*itr] >= x) x = O[itr];
        else                   x = INF;
        ++itr;
    }
    return x < INF;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> M[i] >> m[i];
        if(M[i] < m[i]) swap(M[i], m[i]);
    }

    p = (int) sqrt(n);
    L = n / p + 1;
    for(int i = n; i < L * p; ++i) {
        M[i] = BIG;
        m[i] = BIG;
    }

    for(int i = 0; i < L; ++i) {
        update(i);
    }

    cin >> q;
    while(q--) {

        /*cout << "\n-----\n";
        cout << "M m\n";
        for(int i = 0; i < p*L; ++i) {
            cout << M[i] << " " << m[i] << "\n";
        }
        cout << "O o\n";
        for(int i = 0; i < L; ++i) {
            cout << O[i] << " " << o[i] << "\n";
        }
        cout << "-----\n";*/

        int a, b;
        cin >> a >> b;
        --a, --b;
        swap(M[a], M[b]);
        swap(m[a], m[b]);
        update(a / p);
        update(b / p);
        if(verify()) cout << "TAK\n";
        else cout << "NIE\n";
    }

    return 0;
}