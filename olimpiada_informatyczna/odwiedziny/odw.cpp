/* Jan Zakrzewski
   XXII Olimpiada Informatyczna, Etap III
   Zadanie `Odwiedziny (odw)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 50'000 + 20;
int n;
vector<int> neighbors[N];
int cena[N], _t[N], _k[N];

constexpr int L = 16;
constexpr int K = 300;

int root;
vector<int> children[N];

int ancestor[N][L+1]; // ancestor[u][l] = kto jest o 2^l starszy od wierzchołka u, 0 jeśli nie ma takiego wierzchołka, 0 <= l <= L
int height[N]; // height[u] = jak daleko od korzenia root znajduje się wierzchołek u
int ile_kosztuje[N][K+10]; // ile_kosztuje[u][k] = ile kosztowałaby podróż od wierzchołka u do korzenia root, jeśli trzeba tankować po przejechaniu każdych k dróg, 1 <= k <= K

bool visited[N] = {};
queue<int> Queue;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int u = 1; u <= n; ++u) cin >> cena[u];
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    root = 1;
    Queue.push(root);
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        visited[u] = true;
        for(int v : neighbors[u]) {
            if(visited[v]) ancestor[u][0] = v;
            else {
                children[u].push_back(v);
                Queue.push(v);
            }
        }
    }

    ancestor[root][0] = 0;
    height[root] = 0;
    height[0] = -1;
    Queue.push(root);
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        for(int l = 0; l <= L-1; ++l)
            ancestor[u][l+1] = ancestor[ancestor[u][l]][l];
        for(int v : children[u]) {
            Queue.push(v);
            height[v] = height[u] + 1;
        }
    }

    function<int(int, int)> Lift = [&](int u, int h)->int {
        for(int l = L; l >= 0; --l) {
            if(1 << l <= h) {
                u = ancestor[u][l];
                h -= 1 << l;
            }
        }
        return u;
    };

    function<int(int, int)> LowestCommonAncestor = [&](int u, int v)->int {
        if(height[u] < height[v]) swap(u, v);
        u = Lift(u, height[u] - height[v]);
        if(u == v) return u;
        for(int l = L; l >= 0; --l) {
            if(ancestor[u][l] != ancestor[v][l]) {
                u = ancestor[u][l];
                v = ancestor[v][l];
            }
        }
        return ancestor[u][0]; // = ancestor[v][0]
    };

    for(int k = 1; k <= K; ++k) ile_kosztuje[0][k] = 0;
    Queue.push(root);
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        for(int k = 1; k <= K; ++k) ile_kosztuje[u][k] = ile_kosztuje[Lift(u, k)][k] + cena[u];
        for(int v : children[u]) Queue.push(v);
    }

    for(int i = 1; i <= n; ++i) cin >> _t[i];
    for(int i = 1; i <= n-1; ++i) cin >> _k[i];
    for(int _i = 2; _i <= n; ++_i) {
        int u = _t[_i-1], v = _t[_i];
        int k = _k[_i-1];

        int w = LowestCommonAncestor(u, v);
        int ans = 0;
        if(k > K) {
            while(height[u] <= height[w]) {
                ans += cena[u];
                u = Lift(u, k);
            }
            while(height[v] < height[w]) {
                ans += cena[v];
                v = Lift(v, k);
            }
        } else {
            ans += ile_kosztuje[u][k];
            ans += ile_kosztuje[v][k];
            ans -= ile_kosztuje[Lift(w, k - (height[u] - height[w]) % k)][k];
            ans -= ile_kosztuje[Lift(w, k - (height[v] - height[w]) % k)][k];
            if((height[u] - height[w]) % k == 0) ans -= cena[w];
        }

        cout << ans << "\n";
    }

    return 0;
}