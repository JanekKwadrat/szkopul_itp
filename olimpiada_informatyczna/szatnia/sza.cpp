/*  Jan Zakrzewski
    XIX Olimpiada Informatyczna, Etap II
    Zadanie `Szatnia (sza)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 + 10;
int n, p;
vector<pair<int, int>> bring;
vector<pair<int, int>> take;

bool comp(const int &v, const pair<int, int> &el) {
    return v < el.first;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        int c, a, b;
        cin >> c >> a >> b;
        bring.push_back(make_pair(a, c));
        take.push_back(make_pair(b, c));
    }

    sort(bring.begin(), bring.end());
    sort(take.begin(), take.end());

    for(int i = 0; i < n; ++i) cout << bring[i].first << " " << bring[i].second << " ; "; cout << "\n";
    for(int i = 0; i < n; ++i) cout << take[i].first << " " << take[i].second << " ; "; cout << "\n";

    for(int i = 1; i < n; ++i) {
        bring[i].second += bring[i-1].second;
        take[i].second += take[i-1].second;
    }

    cin >> p;
    while(p--) {
        int a, b, k;
        cin >> a >> k >> b;
        b += a;
        int i = (int)(upper_bound(bring.begin(), bring.end(), a, comp) - bring.begin()) - 1;
        int j = (int)(upper_bound(take.begin(),  take.end(),  b, comp) - take.begin())  - 1;
        int ans = 0;
        if(i != -1) ans += bring[i].second;
        if(j != -1) ans -= take[j].second;
        cout << i << " " << j << " ";
        cout << ans << " ";
        if(ans >= k) cout << "TAK\n";
        else cout << "NIE\n";
    }

    return 0;
}
