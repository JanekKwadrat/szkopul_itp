/*  Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap I
    Zadanie Reprezentacje różnicowe (rep)
    Rozwiązenie w złożoności log^2 X + n log log X */

#include <bits/stdc++.h>
using namespace std;

int binsearch(vector<tuple<int,int,int>> arr, int x) {
    if(get<0>(arr[0]) >= x) return 0;
    int a = 0;
    int b = arr.size();
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(get<0>(arr[mid]) >= x) b = mid;
        else a = mid;
    }
    return b;
}

constexpr int X = 1e9;
constexpr int N = 70;
int a[N], t, n;

bool r_seen[N*N+20];
int r;

vector<tuple<int, int, int>> uneasy;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    a[0] = 1, a[1] = 2;

    r = 2, r_seen[1] = true;
    for(int i = 2; i < N*N+20; ++i) r_seen[i] = false;
    n = N;
    for(int i = 2; i < N; ++i) {
        if(i % 2 == 0) a[i] = a[i-1] * 2;
        else a[i] = a[i-1] + r;
        if(a[i] > INT32_MAX / 2 - 20) { n = i; break; }
        for(int j = 0; j < i; ++j) {
            if(a[i] - a[j] < N*N+20)
                r_seen[a[i] - a[j]] = true;
        }
        while(r < N*N+20 && r_seen[r]) r++;
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            int x = a[i] - a[j];
            if(x <= X && (i - j > 1 || j % 2 == 1))
                uneasy.push_back(make_tuple(x, i, j));
        }
    }
    sort(uneasy.begin(), uneasy.end());

    function<pair<int, int>(int)> repr = [&](int x)->pair<int, int> {
        int i = binsearch(uneasy, x);
        if(i < uneasy.size() && get<0>(uneasy[i]) == x)
            return make_pair(get<1>(uneasy[i]), get<2>(uneasy[i]));
        int q = 2 * (x - i - 1);
        int p = q + 1;
        return make_pair(p, q);
    };

    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        auto elm = repr(x);
        int p = elm.first, q = elm.second;
        cout << p+1 << " " << q+1 << "\n";        
    }
    
    return 0;
}
