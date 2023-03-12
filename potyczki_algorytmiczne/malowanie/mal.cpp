#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef long i32;
constexpr i32 INF = INT32_MAX;

struct Rect {
    i32 x, y;
    i32 xx, yy;
};

inline Rect make_rect(i64 x, i64 y, i64 xx, i64 yy) {
    Rect ans;
    ans.x = x, ans.y = y, ans.xx = xx, ans.yy = yy;
    return ans;
}

inline Rect combine_rect(Rect a, Rect b) {
    return make_rect(max(a.x, b.x), max(a.y, b.y), min(a.xx, b.xx), min(a.yy, b.yy));
}

inline i64 get_area(Rect a) {
    return (i64) max(a.xx - a.x, 0l) * (i64) max(a.yy - a.y, 0l);
}

constexpr int N = 500'050;

int n;
Rect child[N];
Rect sum_fw[N]; // sum_fw[i] = result of combining child[1], child[2], ..., child[i]
Rect sum_bw[N]; // sum_bw[i] = result of combining child[i], child[i+1], ..., child[n]
i64 common_area;
i64 the_area;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> child[i].x >> child[i].y;
        cin >> child[i].xx >> child[i].yy;
    }

    sum_fw[0] = make_rect(0, 0, INF, INF);
    for(int i = 1; i <= n; ++i) sum_fw[i] = combine_rect(sum_fw[i-1], child[i]);

    sum_bw[n+1] = make_rect(0, 0, INF, INF);
    for(int i = n; i >= 1; --i) sum_bw[i] = combine_rect(sum_bw[i+1], child[i]);

    common_area = get_area(sum_fw[n]);
    the_area = common_area;
    for(int i = 1; i <= n; ++i) the_area += get_area(combine_rect(sum_fw[i-1], sum_bw[i+1]));
    the_area -= common_area * (i64) n;

    cout << the_area << "\n";

    return 0;
}