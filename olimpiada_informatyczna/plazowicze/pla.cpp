/*
    Jan Zakrzewski
    XXVIII Olimpiada Informatyczna, Etap II
    Zadanie Plażowicze
    Podzadanie 2
*/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned int u32;
typedef unsigned long long u64;

constexpr int N = 1'000'010;
int n, z, k;
u32 X;
u32 x[N];
u32 diff[N];
u32 splits[N];

vector<int> ord_occupy;

int main() {

    cin >> n >> X >> z;
    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n-1; ++i) diff[i] = x[i+1] - x[i];
    
    vector<pair<u32, u32>> sort_vect;
    for(int i = 1; i <= n-1; ++i) {
        sort_vect.push_back(make_pair(diff[i] * -1, i));
    }
    
    
    while(z--) {
        cin >> k;
    }

    return 0;
}