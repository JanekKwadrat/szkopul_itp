/* Jan Zakrzewski
   XXV Olimpiada Informatyczna, Etap III
   Zadanie `Dwa pionki (dwa)' */

#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

struct P {
    long long x, y;
};

bool operator<(P _a, P _b) {
    return false;
}

double angle_between(double a, double b) {
    double ans = b - a;
    while(ans < 0) ans += M_PI * 2;
    return ans;
}

int n;
vector<pair<double, P>> V;
P sum = {0, 0};
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    while(n--) {
        long long x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) continue;
        double alpha = atan2(y, x);
        while(alpha < 0) alpha += M_PI * 2;
        while(alpha >= M_PI * 2) alpha -= M_PI * 2;
        V.push_back(make_pair(alpha, P {x, y}));

        sum.x += x;
        sum.y += y;
    }
    n = V.size();
    sort(V.begin(), V.end());

    for(int i = 0; i < n; ++i) V.push_back(V[i]);

    P ans1 = {0, 0};
    for(int i = 0, j = 0; i < n; ++i) {
        while(j < i + n && angle_between(V[i].first, V[j].first) < M_PI) {
            ans1.x += V[j].second.x;
            ans1.y += V[j].second.y;
            j++;
            ans = max(ans, (2 * ans1.x - sum.x) * (2 * ans1.x - sum.x) + (2 * ans1.y - sum.y) * (2 * ans1.y - sum.y));
        }
        
        ans1.x -= V[i].second.x;
        ans1.y -= V[i].second.y;
    }

    cout << ans << "\n";

    return 0;
}