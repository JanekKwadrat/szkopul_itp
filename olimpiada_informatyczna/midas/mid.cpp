/*  Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap III
    Zadanie Midas (mid) */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6+20;

int n, z;
int l[N], r[N];
tuple<int, int, bool> dukaty[N];
int c = 0;
queue<int> my_queue;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> l[i] >> r[i];

    dukaty[1] = make_tuple(0, c++, false);
    my_queue.push(1);
    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        if(u == 0) continue;
        dukaty[l[u]] = make_tuple(get<0>(dukaty[u]) + 1, c++, get<2>(dukaty[u]));
        dukaty[r[u]] = make_tuple(get<0>(dukaty[u]) + 1, c++, true);
        my_queue.push(l[u]);
        my_queue.push(r[u]);
    }

    for(int i = 1; i <= n; ++i) {
        
    }

    /*cin >> z;
    while(z--) {
        int u, v;
        cin >> u >> v;
        bool b = !get<2>(dukaty[v]) || (dukaty[u] >= dukaty[v]);
        if(b) cout << "TAK\n";
        else cout << "NIE\n";
    }*/

    return 0;
}
