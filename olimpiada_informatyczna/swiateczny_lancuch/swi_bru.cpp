/* Jan Zakrzewski
   XXIII Olimpiada Informatyczna, Etap II
   Zadanie `Świąteczny łańcuch (swi)' */

#include <bits/stdc++.h>
using namespace std;

class union_find {
    int n;
    vector<int> ancestor;
    vector<int> members;
public:
    union_find(int __n = 0) {
        n = __n;
        ancestor.resize(n);
        members.resize(n);
        for(int u = 0; u < n; ++u) ancestor[u] = u;
        for(int u = 0; u < n; ++u) members[u] = 1;
    }
    int find(int u) {
        int v = u;
        while(true) {
            if(v == ancestor[v]) break;
            else v = ancestor[v];
        }
        while(u != v) {
            u = ancestor[u];
            ancestor[u] = v;
        }
        return v;
    }
    void Union(int u, int v) {
        u = find(u);
        v = find(v);
        if(members[u] < members[v]) swap(u, v);
        members[u] += members[v];
        ancestor[v] = u;
    }
};

constexpr int N = 500'000 + 20;
int n, m;
union_find space(N);
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    while(m--) {
        int a, b, l;
        cin >> a >> b >> l;
        for(int i = 0; i < l; ++i)
            space.Union(a + i, b + i);
    }

    ans = 0;
    for(int u = 1; u <= n; ++u) {
        if(space.find(u) == u)
            ans++;
    }
    cout << ans << "\n";

    return 0;
}
