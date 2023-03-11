#include <iostream>
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'050;
constexpr int None = -1'000'000;

int n, m;
vector<int> neighbors_out[N];
vector<int> neighbors_in[N];
int longest_out[N];
int longest_in[N];
int L;
int which[N];
int maxima[N];
int ans, val;

int main() {

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors_out[u].push_back(v);
        neighbors_in[v].push_back(u);
    }

    {
        fill(longest_out, longest_out + N, None);
        fill(longest_in, longest_in + N, None);

        function<int(int)> f_out = [&](int u)->int {
            if(longest_out[u] == None) {
                int ans = -1;
                for(int v : neighbors_out[u]) {
                    if(f_out(v) > ans) ans = f_out(v);
                }
                longest_out[u] = ans + 1;
            }
            return longest_out[u];
        };
        function<int(int)> f_in = [&](int u)->int {
            if(longest_in[u] == None) {
                int ans = -1;
                for(int v : neighbors_in[u]) {
                    if(f_in(v) > ans) ans = f_in(v);
                }
                longest_in[u] = ans + 1;
            }
            return longest_in[u];
        };

        for(int i = 1; i <= n; ++i) {
            f_out(i);
            f_in(i);
        }
    }
    
    L = 0;
    for(int i = 1; i <= n; ++i) {
        if(longest_in[i] + longest_out[i] > L) {
            L = longest_in[i] + longest_out[i];
        }
    }

    fill(which, which + N, None);
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= L; ++j) cout << which[j] << " "; cout << "\n";
        if(longest_in[i] + longest_out[i] < L) continue;
        if(which[longest_in[i]] != None) continue;
        which[longest_in[i]] = i;
    }

    fill(maxima, maxima + N, 0);
    for(int i = 1; i <= n; ++i) {
        if(i == which[longest_in[i]]) {
            maxima[longest_in[i]] = max(maxima[longest_in[i]], longest_in[i] - 1);
            maxima[longest_in[i]] = max(maxima[longest_in[i]], longest_out[i] - 1);
        } else maxima[longest_in[i]] = max(maxima[longest_in[i]], longest_in[i] + longest_out[i]);
    }

    val = 1'000'000'000;
    for(int i = 0; i <= L; ++i) {
        if(maxima[i] < val) {
            ans = which[i];
            val = maxima[i];
        }
    }

    for(int i = 1; i <= n; ++i) {
        cout << i << ": " << longest_in[i] << " | " << longest_out[i] << "\n";
    }

    cout << L << "\n";

    for(int i = 0; i <= L; ++i) {
        cout << i << ": " << which[i] << " " << maxima[i] << "\n";
    }

   // cout << ans << " " << val << "\n";

    return 0;
}