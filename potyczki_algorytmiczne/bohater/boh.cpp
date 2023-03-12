#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100'050;
int n;
long long z;
struct monster {
    int d, a, itr;
} p[N];

struct {
    bool operator()(monster i, monster j) {
        return i.d + max(j.d - i.a, 0) < j.d + max(i.d - j.a, 0);
    }
} cmp;

bool ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> z;
    for(int i = 0; i < n; ++i) {
        cin >> p[i].d >> p[i].a;
        p[i].itr = i + 1;
    }

    sort(p, p + n, cmp);
    ans = true;

    for(int i = 0; i < n; ++i) {
        z -= p[i].d;
        if(z <= 0) ans = false;
        z += p[i].a;
    }
    
    if(ans) {
        cout << "TAK\n";
        for(int i = 0; i < n; ++i) cout << p[i].itr << " ";
        cout << "\n";
    } else cout << "NIE\n";

    return 0;
}
