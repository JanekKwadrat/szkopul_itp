/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap I
   Zadanie `Kurierzy (kur)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500'000 + 20;
int n, q;
int p[N];

vector<int> firma[N]; // kursy o których numerach wykonała dana firma

inline int ile(int a, int b, int i) {
    // ile kursów w przedziale [a, b] wykonała firma k
    auto k0 = lower_bound(firma[i].begin(), firma[i].end(), a);
    auto k1 = upper_bound(firma[i].begin(), firma[i].end(), b);
    return (int)(k1 - k0);
}

constexpr int NONE = -101;

struct Interval {
    int a, b; // końce przedziału [a, b]
    int dominuje; // numer firmy, która dominuje na przedziale [a, b] lub NONE
    bool neutralny; // interwał jako element neutralny
};
inline Interval make_interval(int a, int b) { return Interval { a, b, NONE, false }; }
inline Interval make_interval(int a, int b, int dominuje) { return Interval { a, b, dominuje, false }; }
constexpr Interval EPSILON = Interval { 0, 0, NONE, true};

Interval combine(Interval I, Interval J) {
    // łączy dwa bezpośrednio następujące po sobie przedziały
    if(I.neutralny) return J;
    if(J.neutralny) return I;
    Interval K = Interval { I.a, J.b, NONE, false };
    vector<int> Queue = { I.dominuje, J.dominuje };
    for(int i : Queue) {
        if(i == NONE) continue;
        if(2 * ile(K.a, K.b, i) > K.b - K.a + 1) {
            K.dominuje = i;
            break;
        }
    }
    return K;
}

constexpr int D = 524'288; // potęga dwójki, D >= N
Interval tree[2 * D];


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        firma[p[i]].push_back(i);
    }

    for(int i = 0; i < D; ++i) tree[i + D] = make_interval(i, i);
    for(int i = 1; i <= n; ++i) tree[i + D].dominuje = p[i];

    for(int i = D-1; i >= 1; --i) tree[i] = combine(tree[2*i], tree[2*i+1]);

    function<int(int, int)> Query = [&](int a, int b)->int {
        // zwraca odpowiedź na pytanie o to, kto dominuje na przedziale [a, b]
        // jeśli nikt nie dominuje zwraca NONE
        a += D;
        b += D;
        Interval left = EPSILON;
        Interval right = EPSILON;
        left = combine(left, tree[a]);
        if(a != b)
            right = combine(tree[b], right);
        while(a / 2 != b / 2) {
            if(a % 2 == 0) left = combine(left, tree[a+1]);
            if(b % 2 == 1) right = combine(tree[b-1], right);
            a /= 2, b /= 2;
        }
        Interval final = combine(left, right);
        return final.dominuje;
    };

    while(q--) {
        int a, b;
        cin >> a >> b;
        
        int ans = Query(a, b);
        if(ans == NONE) cout << "0\n";
        else cout << ans << "\n";
    }

    return 0;
}
