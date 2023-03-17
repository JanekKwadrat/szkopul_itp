/* Jan Zakrzewski
   XXIII Olimpiada Informatyczna, Etap II
   Zadanie `Zająknięcia (zaj)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 15'000 + 20;
int n, m; // n = długość ciągu A, m = długość ciągu B, 1 <= n, m <= 15'000
int A[N], B[N];
vector<pair<int, int>> wyrazy_A; // wyrazy_A jest wektorem par (a, i), gdzie a jest wartością a i jej indeksem w tablicy A
vector<pair<int, int>> wyrazy_B; // wyrazy_B jest wektorem par (b, i), gdzie b jest wartością a i jej indeksem w tablicy B
pair<int, int> best[N]; // best[i] = para (d, -j), gdzie d jest długością najdłuższego wspólnego zająknięcia A[1..i] oraz B, z koleji j jest najmniejsze takie, że najdłuższe wspólne zająknięcie A[1..i] oraz B[1...j] ma długość d; ze wszystkich możliwych wyborów tego typu par (d, -j) jest leksykograficznie największa

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> A[i];
    for(int i = 1; i <= m; ++i) cin >> B[i];

    for(int i = 1; i <= n; ++i) wyrazy_A.push_back(make_pair(A[i], i));
    for(int i = 1; i <= m; ++i) wyrazy_B.push_back(make_pair(B[i], i));
    sort(wyrazy_A.begin(), wyrazy_A.end());
    sort(wyrazy_B.begin(), wyrazy_B.end());

    best[0] = make_pair(0, 0);
    for(int i = 1; i <= n; ++i) {
        best[i] = best[i-1];
        vector<int> i0s;
        auto itr = lower_bound(wyrazy_A.begin(), wyrazy_A.end(), make_pair(A[i], i));
        if(itr != wyrazy_A.begin() && prev(itr)->first == A[i])
            i0s.push_back(prev(itr)->second - 1);

        auto jtr = lower_bound(&best[1], &best[i-1]+1, make_pair(best[i].first, INT32_MIN));
        if(jtr != &best[1])
            i0s.push_back((int)(prev(jtr) - &best[0]));

        for(int i0 : i0s) {
            int j0 = best[i0].second;
            auto ktr = lower_bound(wyrazy_B.begin(), wyrazy_B.end(), make_pair(A[i], j0-1));
            if(ktr != wyrazy_B.end() && next(ktr) != wyrazy_B.end()) {
                if(ktr->first == A[i] && next(ktr)->first == A[i]) {
                    best[i] = max(best[i], make_pair(best[i0].first + 1, -next(ktr)->second));
                }
            }
        }
    }

    //for(int i = 1; i <= n; ++i) cout << best[i].first << " ";
    //cout << "\n";
    //for(int i = 1; i <= n; ++i) cout << best[i].second << " ";
    //cout << "\n";

    cout << best[n].first * 2 << "\n";

    return 0;
}
