/* Jan Zakrzewski
   XXIX Olimpiada Informatyczna, Etap II
   Zadanie `Agenci (age)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 20;

constexpr long long INF = 1e12;

int n, k;
vector<int> neighbors[N];
bool agent[N] = {};

int root;
int parent[N];
vector<int> children[N];

long long answer[N];
long long supply[N];
long long consume[N];

bool visited[N] = {};
queue<int> my_queue;

long long ans;
long long L;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= k; ++i) {
        int u;
        cin >> u;
        agent[u] = true;
    }
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    root = 1;
    my_queue.push(root);
    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        visited[u] = true;
        for(int v : neighbors[u]) {
            if(visited[v]) parent[u] = v;
            else {
                children[u].push_back(v);
                my_queue.push(v);
            }
        }
    }

    function<void(int)> Visit = [&](int u) {
        for(int v : children[u]) Visit(v);
        long long sum = 0;
        for(int v : children[u]) sum += answer[v];
        if(agent[u]) {
            supply[u] = sum;
            answer[u] = sum;
            for(int v : children[u]) answer[u] = max(answer[u], sum + (consume[v] - answer[v] + 1));
            consume[u] = -INF;
        } else {
            supply[u] = -INF;
            for(int v : children[u]) supply[u] = max(supply[u], sum + (supply[v] - answer[v] + 1));
            consume[u] = sum;
            for(int v : children[u]) consume[u] = max(consume[u], sum + (consume[v] - answer[v] + 1));
            
            answer[u] = max(sum, supply[u]);
            if(children[u].size() >= 2) {
                int v1, w1;

                v1 = -1;
                for(int v : children[u]) {
                    if(v1 == -1) v1 = v;
                    else if(supply[v] - answer[v] + 1 > supply[v1] - answer[v1] + 1) v1 = v;
                }
                w1 = -1;
                for(int w : children[u]) {
                    if(w == v1) continue;
                    if(w1 == -1) w1 = w;
                    else if(consume[w] - answer[w] + 1 > consume[w1] - answer[w1] + 1) w1 = w;
                }
                answer[u] = max(answer[u], sum + (supply[v1] - answer[v1] + 1) + (consume[w1] - answer[w1] + 1));

                w1 = -1;
                for(int w : children[u]) {
                    if(w1 == -1) w1 = w;
                    else if(consume[w] - answer[w] + 1 > consume[w1] - answer[w1] + 1) w1 = w;
                }
                v1 = -1;
                for(int v : children[u]) {
                    if(v == w1) continue;
                    if(v1 == -1) v1 = v;
                    else if(supply[v] - answer[v] + 1 > supply[v1] - answer[v1] + 1) v1 = v;
                }
                answer[u] = max(answer[u], sum + (supply[v1] - answer[v1] + 1) + (consume[w1] - answer[w1] + 1));
            }
            
            /*answer[u] = max(sum, supply[u]);
            for(int v : children[u])
                for(int w : children[u]) {
                    if(v == w) continue;
                    answer[u] = max(answer[u], sum + (supply[v] + consume[w] - answer[v] - answer[w] + 2));
                }*/
        }
    };
    Visit(root);

    /*for(int u = 1; u <= n; ++u) cout << answer[u] << " "; cout << "\n";
    for(int u = 1; u <= n; ++u) cout << supply[u] << " "; cout << "\n";
    for(int u = 1; u <= n; ++u) cout << consume[u] << " "; cout << "\n";*/

    L = answer[root];
    ans = 2 * (n - k) - L;

    cout << ans << "\n";

    return 0;
}
