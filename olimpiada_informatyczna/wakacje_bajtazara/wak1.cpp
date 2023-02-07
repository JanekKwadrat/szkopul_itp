/*  Jan Zakrzewski
    XXVII Olimpiada Informatyczna, Etap II
    Zadanie Wakacje Bajtazara (wak) */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6+20;
int n;
int w[N];
vector<int> neighbor[N];

bool visited[N];
queue<int> my_queue;

int root;
int parent[N];
vector<int> children[N];

long long ans_zwiedzanie[N];
long long ans_pamietniki[N];

long long solve_pamietniki(int u);

long long solve_zwiedzanie(int u) {
    if(ans_zwiedzanie[u] == -1) {
        ans_zwiedzanie[u] = 0;
        for(int v : children[u])
            ans_zwiedzanie[u] = max(ans_zwiedzanie[u], solve_pamietniki(v));
        ans_zwiedzanie[u] += w[u];
    }
    return ans_zwiedzanie[u];
}

long long solve_pamietniki(int u) {
    if(ans_pamietniki[u] == -1) {
        ans_pamietniki[u] = 0;
        for(int v : children[u])
            ans_pamietniki[u] = max(ans_pamietniki[u], solve_zwiedzanie(v) - w[v]);
        for(int v : children[u])
            ans_pamietniki[u] += w[v];
    }
    return ans_pamietniki[u];
}

long long W; 
int k;
vector<int> route;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int u = 1; u <= n; ++u) cin >> w[u];
    for(int i = 1; i <= n-1; ++i) {
        int a, b;
        cin >> a >> b;
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }

    root = 1;
    for(int u = 1; u <= n; ++u) visited[u] = false;
    my_queue.push(root);
    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        visited[u] = true;
        for(int v : neighbor[u]) {
            if(visited[v]) parent[u] = v;
            else {
                children[u].push_back(v);
                my_queue.push(v);
            }
        }
    }

    for(int u = 1; u <= n; ++u) {
        ans_zwiedzanie[u] = -1;
        ans_pamietniki[u] = -1;
    }
    for(int u = 1; u <= n; ++u) {
        solve_zwiedzanie(u);
        solve_pamietniki(u);
    }

    //for(int u = 1; u <= n; ++u) cout << ans_zwiedzanie[u] << " "; cout << "\n";
    //for(int u = 1; u <= n; ++u) cout << ans_pamietniki[u] << " "; cout << "\n";

    long long W1 = 0;
    int k1;
    vector<int> route1;

    {

        int best_u;
        int v1 = -1, v2 = -1;

        for(int u = 1; u <= n; ++u) {
            int vv1 = -1, vv2 = -1;
            for(int v : children[u]) {
                if(vv1 == -1 || ans_pamietniki[v] > ans_pamietniki[vv1]) {
                    vv2 = vv1;
                    vv1 = v;
                } else if(vv2 == -1 || ans_pamietniki[v] > ans_pamietniki[vv2])
                    vv2 = v;
            }
            long long WW = w[u];
            if(vv1 != -1) WW += ans_pamietniki[vv1];
            if(vv2 != -1) WW += ans_pamietniki[vv2];

            if(WW > W1) {
                W1 = WW;
                best_u = u;
                v1 = vv1;
                v2 = vv2;
            }
        }

        vector<int> vect_ans1, vect_ans2;

        while(true) {
            if(v1 == -1) break;

            int w1 = -1;
            long long A = 0;
            for(int w : children[v1]) {
                if(ans_zwiedzanie[w] > A) {
                    A = ans_zwiedzanie[w];
                    w1 = w;
                }
            }
            if(w1 == -1) break;
            for(int w : children[v1]) {
                if(w == w1) continue;
                vect_ans1.push_back(v1);
                vect_ans1.push_back(w);
            }
            vect_ans1.push_back(v1);
            vect_ans1.push_back(w1);

            v1 = -1, A = 0;
            for(int v : children[w1]) {
                if(ans_pamietniki[v] > A) {
                    A = ans_pamietniki[v];
                    v1 = v;
                }
            } 
        }

        while(true) {
            if(v2 == -1) break;

            int w2 = -1;
            long long A = 0;
            for(int w : children[v2]) {
                if(ans_zwiedzanie[w] > A) {
                    A = ans_zwiedzanie[w];
                    w2 = w;
                }
            }
            if(w2 == -1) break;
            for(int w : children[v2]) {
                if(w == w2) continue;
                vect_ans2.push_back(v2);
                vect_ans2.push_back(w);
            }
            vect_ans2.push_back(v2);
            vect_ans2.push_back(w2);

            v2 = -1, A = 0;
            for(int v : children[w2]) {
                if(ans_pamietniki[v] > A) {
                    A = ans_pamietniki[v];
                    v2 = v;
                }
            } 
        }

        reverse(vect_ans1.begin(), vect_ans1.end());
        for(int u : vect_ans1) route1.push_back(u);
        route1.push_back(best_u);
        for(int u : vect_ans2) route1.push_back(u);

        k1 = route1.size() / 2;

    }

    long long W2 = 0;
    int k2;
    vector<int> route2;

    {

        int best_u;
        int v1 = -1, v2 = -1;

        for(int u = 0; u <= n; ++u) {
            int vv1 = -1, vv2 = -1;
            for(int v : children[u]) {
                if(vv1 == -1 || ans_zwiedzanie[v] > ans_zwiedzanie[vv1]) {
                    vv2 = vv1;
                    vv1 = v;
                } else if(vv2 == -1 || ans_zwiedzanie[v] > ans_zwiedzanie[vv2])
                    vv2 = v;
            }
            long long WW = 0;
            if(vv1 != -1) WW += ans_zwiedzanie[vv1];
            if(vv2 != -1) WW += ans_zwiedzanie[vv2];
            if(u != root) WW += w[parent[u]];

            if(WW > W2) {
                W2 = WW;
                best_u = u;
                v1 = vv1;
                v2 = vv2;
            }
        }

        vector<int> vect_ans_mid;
        vector<int> vect_ans1, vect_ans2;

        for(int u : neighbor[best_u]) {
            vect_ans_mid.push_back(u);
            vect_ans_mid.push_back(best_u);
        }
        if(vect_ans_mid.size() > 0) vect_ans_mid.pop_back();

        if(v1 != -1){
            int w1 = -1;
            long long A = 0;
            for(int w : children[v1]) {
                if(ans_pamietniki[w] > A) {
                    A = ans_pamietniki[w];
                    w1 = w;
                }
            }
            v1 = w1;
        }
        if(v2 != -1){
            int w2 = -1;
            long long A = 0;
            for(int w : children[v2]) {
                if(ans_pamietniki[w] > A) {
                    A = ans_pamietniki[w];
                    w2 = w;
                }
            }
            v2 = w2;
        }

        while(true) {
            if(v1 == -1) break;

            int w1 = -1;
            long long A = 0;
            for(int w : children[v1]) {
                if(ans_zwiedzanie[w] > A) {
                    A = ans_zwiedzanie[w];
                    w1 = w;
                }
            }
            if(w1 == -1) break;
            for(int w : children[v1]) {
                if(w == w1) continue;
                vect_ans1.push_back(v1);
                vect_ans1.push_back(w);
            }
            vect_ans1.push_back(v1);
            vect_ans1.push_back(w1);

            v1 = -1, A = 0;
            for(int v : children[w1]) {
                if(ans_pamietniki[v] > A) {
                    A = ans_pamietniki[v];
                    v1 = v;
                }
            } 
        }

        while(true) {
            if(v2 == -1) break;

            int w2 = -1;
            long long A = 0;
            for(int w : children[v2]) {
                if(ans_zwiedzanie[w] > A) {
                    A = ans_zwiedzanie[w];
                    w2 = w;
                }
            }
            if(w2 == -1) break;
            for(int w : children[v2]) {
                if(w == w2) continue;
                vect_ans2.push_back(v2);
                vect_ans2.push_back(w);
            }
            vect_ans2.push_back(v2);
            vect_ans2.push_back(w2);

            v2 = -1, A = 0;
            for(int v : children[w2]) {
                if(ans_pamietniki[v] > A) {
                    A = ans_pamietniki[v];
                    v2 = v;
                }
            } 
        }


        reverse(vect_ans1.begin(), vect_ans1.end());
        for(int u : vect_ans1) route1.push_back(u);
        for(int u : vect_ans_mid) route1.push_back(u);
        for(int u : vect_ans2) route1.push_back(u);
    }

    if(W1 > W2) {
        W = W1;
        k = k1;
        route = route1;
    } else {
        W = W1;
        k = k2;
        route = route2;
    }

    cout << W << "\n";
    cout << k << "\n";
    for(int u : route)
        cout << u << " ";
    cout << "\n";

    return 0;
}
