/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap III
   Zadanie `Mrowisko (mro)' */

// w rozwiązaniu wykorzystam fakt, że m // p // q = m // (pq), gdzie '//' oznacza dzielenie z zaokrągleniem w dół (jak w Pythonie)

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'000 + 100;
int n, g, k;
int m[N];
vector<int> neighbors[N];

int root;
int parent[N];
vector<int> children[N];

bool visited[N];
queue<int> Queue;

constexpr int INF = 1'500'000'000;
int alpha[N]; // alpha[u] jest taką liczbą, że jeśli od wierzchołka u w górę drzewa idzie grupa o liczności x mrówek, to do mrówkojada dojdzie floor(x / alpha[u]) mrówek

long long ans, ans1;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> g >> k;
    for(int i = 1; i <= g; ++i) cin >> m[i];
    
    root = n+1;
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        if(i == 1) {
            neighbors[root].push_back(u);
            neighbors[u].push_back(root);
            neighbors[root].push_back(v);
            neighbors[v].push_back(root);
        } else {
            neighbors[u].push_back(v);
            neighbors[v].push_back(u);
        }
    }
    for(int u = 1; u <= n+1; ++u) visited[u] = false;

    Queue.push(root);
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();

        visited[u] = true;
        for(int v : neighbors[u]) {
            if(visited[v]) parent[u] = v;
            else {
                children[u].push_back(v);
                Queue.push(v);
            }
        }
    }

    for(int u = 1; u <= n; ++u) alpha[u] = -1;
    for(int u : children[root]) alpha[u] = 1;

    function<void(int)> Visit = [&](int u) {
        if(alpha[u] != -1) return;
        Visit(parent[u]);

        alpha[u] = min((long long) INF, (long long) alpha[parent[u]] * (long long) children[parent[u]].size());
    };
    for(int u = 1; u <= n; ++u) Visit(u);

    /* // kod, który następuje ma nieoptymalną złożoność
    ans = 0;
    for(int u = 1; u <= n; ++u) {
        if(children[u].size() != 0) continue;
        int a = 0;
        for(int i = 1; i <= g; ++i)
            if(m[i] / alpha[u] == k)
                ans++, a++;
        cout << u << " " << a << "\n";
    }
    cout << ans * k << "\n";
    // dotąd */

    //for(int u = 1; u <= n; ++u) cout << alpha[u] << " "; cout << "\n";

    // wesja poprawiona
    sort(m + 1, m + g + 1);
    ans1 = 0;
    for(int u = 1; u <= n; ++u) {
        if(children[u].size() != 0) continue;
        int p = (int)( lower_bound(m + 1, m + g + 1, (int) min((long long) INF, (long long) alpha[u] * k)) - m );
        int q = (int)( lower_bound(m + 1, m + g + 1, (int) min((long long) INF, (long long) alpha[u] * (k + 1))) - m );
        //cout << u << " " << q - p << " " << p << " " << q << "\n";
        ans1 += q - p;
    }
    ans1 *= k;
    cout << ans1 << "\n";
    // tyle

    return 0;
}