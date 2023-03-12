#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

int orientation(Point a, Point b, Point c) {
    long long val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if(val < 0) return -1;
    if(val > 0) return 1;
    return 0;
}

constexpr int N = 300'050;
int n, m;
Point Bitocja[N];
Point bomb;
int ans = 0;

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> Bitocja[i].x >> Bitocja[i].y;
    while(m--) {
        cin >> bomb.x >> bomb.y;
        int eps = orientation(Bitocja[1], Bitocja[2], bomb);
        if(orientation(Bitocja[1], Bitocja[2], bomb) * orientation(Bitocja[1], Bitocja[n], bomb) > 0) break;

        int a = 2, b = n;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(orientation(Bitocja[1], Bitocja[mid], bomb) == eps) a = mid;
            else b = mid;
        }
        if(orientation(Bitocja[1], Bitocja[a], bomb) * eps >= 0
        && orientation(Bitocja[a], Bitocja[b], bomb) * eps >= 0
        && orientation(Bitocja[b], Bitocja[1], bomb) * eps >= 0) ans++;
    }
    cout << ans << "\n";

    return 0;
}