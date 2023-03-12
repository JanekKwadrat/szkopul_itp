#include <bits/stdc++.h>
using namespace std;

constexpr int N = 40;

int n, x;
long long A[N];
vector<long long> p, q;
int ans;

int main() {

    cin >> n >> x;
    for(int i = 0; i < n; ++i) cin >> A[i];
    fill(A + n, A + N, 10'000'000'000LL);
    
    for(int itr = 0; itr < 1024 * 1024; ++itr) {
        int sum_p = 0;
        int sum_q = 0;
        for(int i = 0; i < 20; ++i) {
            sum_p += ((itr >> i) & 1) * A[i];
            sum_q += ((itr >> i) & 1) * A[i+20];
        }
        p.push_back(sum_p);
        q.push_back(sum_q);
    }
    sort(p.begin(), p.end());

    ans = 0;
    for(int itr : q) {
        ans += (int) ( upper_bound(p.begin(), p.end(), x - itr) - lower_bound(p.begin(), p.end(), x - itr) );
    }
    cout << ans << "\n";

    return 0;
}