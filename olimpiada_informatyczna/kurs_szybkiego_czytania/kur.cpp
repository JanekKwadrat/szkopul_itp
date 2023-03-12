/*  Jan Zakrzewski
    XXII Olimpiada Informatyczna, Etap II
    Zadanie 'Kurs szybkiego czytanie (KUR)' */

#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b, p;

constexpr int M = 1'000'000;
char w[M+1];

struct Interval {
    int l, r;
    Interval(int ll = -1, int rr = -1) {
        l = ll, r = rr;
    }
    Interval Union(Interval oth) {
        return Interval(min(l, oth.l), max(r, oth.r));
    }
    Interval Intersection(Interval oth) {
        return Interval(max(l, oth.l), min(r, oth.r));
    }
    bool Contains(int x) {
        return l <= x && x < r;
    }
    bool NotContains(int x) {
        return x < l || r <= x;
    }
    int length() {
        if(l < r) return r - l;
        else return 0;
    }
};

pair<Interval, bool> phi(int C) {
    if(C == 0) return make_pair(Interval(0, p), false);
    else if(C < p) return make_pair(Interval(p - C, n - C), true);
    else return make_pair(Interval(n - C, n + p - C), false);

}

int ans = 0;
int k = 0;
vector<Interval> Is;
vector<pair<int, int>> bad_boys;
vector<int> sums;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> a >> b >> p;
    cin >> m >> w;

    int C = b;
    for(int i = 0; i < m; ++i) {
        auto elm = phi(C);
        if(w[i] != '0') elm.second = !elm.second;
        if(elm.first.l >= elm.first.r) continue;

        if(elm.second) Is.push_back(elm.first);
        else {
            Is.push_back(Interval(0, elm.first.l));
            Is.push_back(Interval(elm.first.r, n));
        }

        C = (C + a) % n;
    }

    for(Interval I : Is) {
        bad_boys.push_back(make_pair(I.l, 1));
        bad_boys.push_back(make_pair(I.r, -1));
    }

    sort(bad_boys.begin(), bad_boys.end());
    k = (int)bad_boys.size();
    sums.resize(k);
    fill(sums.begin(), sums.end(), 0);

    sums[0] = bad_boys[0].second;
    for(int i = 1; i < k; ++i) sums[i] = sums[i-1] + bad_boys[i].second;

    for(int i = 0; i < k-1; ++i) {
        if(sums[i] == 0) ans += bad_boys[i+1].first - bad_boys[i].first;
    }
    if(sums[k-1] == 0) ans += n - bad_boys[k-1].first;

    for(int i = n-m+1; i < n; ++i) {
        int x = (long long) a * i % n;
        int itr = ( int ) ( upper_bound(bad_boys.begin(), bad_boys.end(), make_pair(x, 100)) - bad_boys.begin() ) - 1;
        //if(sums[itr] == 0) ans--;
    }

    cout << ans << "\n";

    return 0;
}
