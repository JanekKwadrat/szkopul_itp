/*  Jan Zakrzewski
    Liga CMI, Gremliny 2022
    Zadanie Rajd przez płotki */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'020;
int n;
char a[N];
char b[N];

pair<int, int> v;

inline int min_branchless(int x, int y) {
    return (x & -(x < y)) | (y & -(x >= y));
}

int main() {

    cin >> n;
    cin >> a;
    cin >> b;

    /* v = make_pair(0, 0);
    for(int i = 0; i < n; ++i) {
        if(a[i] == 'x') v.first++;
        if(b[i] == 'x') v.second++;
        v = make_pair(min(v.first, v.second+1), min(v.first+1, v.second));
    } */

    v = make_pair(0, 0);
    for(int i = 0; i < n; ++i) {
        v.first  += a[i] == 'x';
        v.second += b[i] == 'x';
        v = make_pair(min_branchless(v.first, v.second+1), min_branchless(v.first+1, v.second));
    }

    cout << min_branchless(v.first, v.second) << "\n";

    return 0;
}
