#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'100;
int n, m;
vector<int> neighbor[N];
bool visited[N] = { false };
int countdown[N];
queue<int> the_queue;
int height[N] = { 0 };
bool ans = true;

int main() {

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }

    countdown[2] = 2 * N + 1000;
    for(int u = 3; u <= n; ++u) countdown[u] = neighbor[u].size() / 2;

    int H = 1;
    the_queue.push(1);
    for(int u = 3; u <= n; ++u) if(neighbor[u].size() == 0) the_queue.push(u);
    while(the_queue.size() > 0) {
        int u = the_queue.front();
        the_queue.pop();

        height[u] = H;
        H++;

        for(int v : neighbor[u]) {
            if(countdown[v] > 0) {
                countdown[v]--;
                if(countdown[v] == 0) the_queue.push(v);
            } else if(height[v] == 0) ans = false;
        }
    }
    height[2] = H;

    if(H != n) ans = false;

    if(ans) {
        cout << "TAK\n";
        for(int u = 1; u <= n; ++u) cout << height[u] << " ";
        cout << "\n";
    } else cout << "NIE\n";

    return 0;
}