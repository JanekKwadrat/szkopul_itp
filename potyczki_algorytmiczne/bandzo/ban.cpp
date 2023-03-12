#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'050;
int n;
int a[N], b[N];

int main() {

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    {
        vector<int> sth;
        for(int i = 0; i < n; ++i) sth.push_back(a[i]);
        for(int i = 0; i < n; ++i) sth.push_back(b[i]);
        sort(sth.begin(), sth.end());
        sth.erase(unique(sth.begin(), sth.end()), sth.end());
        for(int i = 0; i < n; ++i) a[i] = (int)( lower_bound(sth.begin(), sth.end(), a[i]) - sth.begin() );
        for(int i = 0; i < n; ++i) b[i] = (int)( lower_bound(sth.begin(), sth.end(), b[i]) - sth.begin() );
    }

    int 



    return 0;
}