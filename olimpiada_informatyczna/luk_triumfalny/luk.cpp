#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300'020;
int n;
vector<int> neighbor[N];
vector<int> children[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbor[u].push_back(v);
        neighbor[v].push_back(u);
    }

    queue<int> my_queue;
    my_queue.push(1);
    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        for(int v : neighbor[u]) {
            if(children[v].size() > 0) continue;
            children[u].push_back(v);
            my_queue.push(v);
        }
    }

    function<int(int, int)> phi = [&](int u, int k)->int {
        int ans = children[u].size();
        for(int v : children[u]) ans += phi(v, k);
        ans -= k;
        if(ans < 0) ans = 0;
        return ans;
    };

    int p = 0, q = n; 
    while(q - p > 1) {
        int mid = (p + q) / 2;
        if(phi(1, mid) == 0) q = mid;
        else p = mid;
    }
    int ans = q;
    if(children[1].size() == 0) ans = 0;

    cout << ans << "\n";

    return 0;
}