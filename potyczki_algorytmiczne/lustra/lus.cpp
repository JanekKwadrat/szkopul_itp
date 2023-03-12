#include <bits/stdc++.h>
using namespace std;

constexpr int INF = INT32_MAX;
constexpr int _INF = INT32_MIN;

int t, n;
int w_min, w_max;
int h_min, h_max;
int best_w_min, best_w_max;
int best_h_min, best_h_max;
int min_w_min, max_w_max;
int min_h_min, max_h_max;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        min_w_min = INF, max_w_max = _INF;
        min_h_min = INF, max_h_max = _INF;
        best_w_min = INF, best_w_max = _INF;
        best_h_min = INF, best_h_max = _INF;
        while(n--) {
            cin >> w_min >> w_max;
            cin >> h_min >> h_max;
            min_w_min = min(min_w_min, w_min);
            max_w_max = max(max_w_max, w_max);
            min_h_min = min(min_h_min, h_min);
            max_h_max = max(max_h_max, h_max);
            if(w_min <= min_w_min && w_max >= max_w_max
            && h_min <= min_h_min && h_max >= max_h_max) {
                best_w_min = w_min;
                best_w_max = w_max;
                best_h_min = h_min;
                best_h_max = h_max;
            }
        }
        if(best_w_min <= min_w_min && best_w_max >= max_w_max
        && best_h_min <= min_h_min && best_h_max >= max_h_max)
            cout << "TAK\n";
        else cout << "NIE\n";
    }

    return 0;
}