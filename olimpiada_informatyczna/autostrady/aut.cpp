/*  Jan Zakrzewski
    X Olimpiada Informatyczna, Etap II
    Zadanie `Autostrady (aut)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20'000 + 10;
int n, k;
vector<pair<int, int>> pq[N];
priority_queue<int> barrierN;
priority_queue<int> barrierS;
char where[N];
bool ans = true;

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= k; ++i) {
        int p, q;
        cin >> p >> q;
        pq[p].push_back(make_pair(-q, i));
    }

    for(int p = 1; p <= n; ++p) {
        sort(pq[p].begin(), pq[p].end());
        //cout << p << ": "; for(auto el : pq[p]) cout << el.first << " "; cout << "\n";
        for(int j = 0; j < pq[p].size(); ++j) pq[p][j].first *= -1;
        //cout << p << ": "; for(auto el : pq[p]) cout << el.first << " "; cout << "\n";
    }

    barrierN.push(-2 * N);
    barrierS.push(-2 * N);
    for(int p = 1; p <= n; ++p) {
        while(p == -barrierN.top()) barrierN.pop();
        while(p == -barrierS.top()) barrierS.pop();
        //cout << p << " " << -barrierN.top() << " " << -barrierS.top() << "\n";
        for(auto el : pq[p]) {
            int q = el.first;
            int i = el.second;
            if(q <= -barrierN.top()) {
                barrierN.push(-q);
                where[i] = 'N';
            } else if(q <= -barrierS.top()) {
                barrierS.push(-q);
                where[i] = 'S';
            } else {
                ans = false;
                goto quitLoop;
            }
        }
    }
    quitLoop: 0;

    //cout << "NIE";

    if(!ans) cout << "NIE\n";
    else for(int i = 1; i <= n; ++i) cout << where[i] << "\n";

    return 0;
}
