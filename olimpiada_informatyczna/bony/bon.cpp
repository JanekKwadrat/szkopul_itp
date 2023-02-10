/* Jan Zakrzewski
   XIX Olimpiada Informatyczna, Etap II
   Zadanie `Bony (bon)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 20;
constexpr int M = 1e6;
int m, n;
bool candy[N];
bool taken[N];
int jump[N];
long long S = 0;
vector<long long> ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m;
    for(int i = 1; i <= M; ++i) {
        candy[i] = false;
        taken[i] = false;
    }
    for(int i = 1; i <= m; ++i) {
        int b;
        cin >> b;
        candy[b] = true;
    }

    for(int x = 1; x <= M; ++x) jump[x] = x;

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;

        int j = jump[a];
        int c = 0;
        while(j <= M && c < a) {
            if(!taken[j]) {
                //cout << j << " ";
                if(candy[j]) ans.push_back(S + c + 1);
                taken[j] = true;
                c++;
            }
            j += a;
        }
        jump[a] = j;

        S += a;
    }
    //cout << "\n";

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(long long x : ans) cout << x << "\n";


    return 0;
}
