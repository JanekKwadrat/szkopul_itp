#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'050;

int n, q;
int k[N];
int a[N];

int t[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 0; i < q; ++i) cin >> k[i];
    for(int i = 1; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    for(int i = 0; i < q; ++i) {
        fill(t, t + N, 0);
        for(int j = 1; j < n; ++j) ++t[a[j]];
        int K = k[i];
        
        

        int ans = 0;
        queue<int> my_queue;
        for(int j = 0; j < n; ++j) {
            if(t[j] == 0) my_queue.push(j);
        }
        while(my_queue.size() > 0) {
            for(int j = 0; j < n; ++j) cout << t[j] << " "; cout << "\n";
            int j = 0;
            int L = min(K, (int) my_queue.size());
            while(j < L) {
                int u = my_queue.front();
                cout << u + 1 << " ";
                my_queue.pop();
                --t[a[u]];
                if(t[a[u]] == 0) my_queue.push(a[u]);
                ++j;
            }
            cout << "\n";
            ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}