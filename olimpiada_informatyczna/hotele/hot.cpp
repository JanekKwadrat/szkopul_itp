/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap I
   Zadanie `Hotele (hot)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5000 + 100;
int n;
vector<int> neighbors[N];

constexpr pair<int, int> COMPUTE = make_pair(-123, 456);
bool visited[N];
queue<pair<int, int>> Q; // pary (u, g) - wierzchcołek i jego grupa
vector<int> abc;
long long ans = 0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    for(int u = 1; u <= n; ++u) {
        for(int v = 1; v <= n; ++v) visited[v] = false;
        visited[u] = true;

        for(int v : neighbors[u]) Q.push(make_pair(v, v));
        Q.push(COMPUTE);

        int ktore_g = -1;
        while(Q.size() > 0) {
            if(Q.front() != COMPUTE) {
                int u = Q.front().first;
                int g = Q.front().second;
                Q.pop();
                visited[u] = true;
                if(g == ktore_g) abc.back()++;
                else {
                    abc.push_back(1);
                    ktore_g = g;
                }
                for(int v : neighbors[u]) {
                    if(visited[v]) continue;
                    Q.push(make_pair(v, g));
                }
            } else {
                Q.pop();
                if(Q.size() > 0) Q.push(COMPUTE);
                long long sum = 0;
                long long sqs = 0;
                long long cbs = 0;
                for(int x : abc) {
                    sum += (long long) x;
                    sqs += (long long) x * x;
                    cbs += (long long) x * x * x;
                }
                abc.clear();
                ans += (sum * sum * sum - 3 * sum * sqs + 2 * cbs) / 6;
                ktore_g = -1;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
