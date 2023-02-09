/* Jan Zakrzewski
   XVIII Olimpiada Informatyczna, Etap II
   Zadanie `Temperatura (temp)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
int n;
int a[N], b[N];
int p, q;
deque<int> the;
int ans = 1;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];

    p = 1, q = 1;
    the.push_back(a[1]);
    while(q < n) {
        q++;
        while(the.size() > 0 && the.back() < a[q]) the.pop_back();
        the.push_back(a[q]);
        while(the.front() > b[q]) {
            if(the.front() == a[p]) the.pop_front();
            p++;
        }
        ans = max(ans, q - p + 1);
    }

    cout << ans << "\n";

    return 0;
}
