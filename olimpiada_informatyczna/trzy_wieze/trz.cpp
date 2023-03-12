/*  Jan Zakrzeski
    XXII Olimpiada Informatyczna, Etap II
    Zadanie 'Trzy wieże (TRZ)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'020;
int n;
char a[N];
int p[N], q[N], r[N];
int k[N], l[N], m[N];

int ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    cin >> (a+1);

    p[0] = 0; q[0] = 0; r[0] = 0;
    for(int i = 1; i <= n; ++i) {
        p[i] = p[i-1]; q[i] = q[i-1]; r[i] = r[i-1];
        switch(a[i]) {
            case 'S': p[i]--, q[i]++; break;
            case 'B': q[i]--, r[i]++; break;
            case 'C': r[i]--, p[i]++; break;
        }
    }

    k[n] = n+1; l[n] = n+1; m[n] = n+1;
    for(int i = n-1; i >= 0; --i) {
        if(p[i] == p[i+1]) k[i] = k[i+1];
        else k[i] = i+1;
        if(q[i] == q[i+1]) l[i] = l[i+1];
        else l[i] = i+1;
        if(r[i] == r[i+1]) m[i] = m[i+1];
        else m[i] = i+1;
    }

    ans = 0;
    for(int j = n; j >= 1; --j) {
        int i = 0;
        while(i <= n) {
                 if(p[i] == p[j]) i = k[i];
            else if(q[i] == q[j]) i = l[i];
            else if(r[i] == r[j]) i = m[i];
            else break;
        }
        ans = max(ans, j - i);
        //cout << i << " " << j << "\n";
    }

    //cout << "   "; for(int i = 1; i <= n; ++i) cout << setw(2) << a[i] << " "; cout << "\n";
    //for(int i = 0; i <= n; ++i) cout << setw(2) << p[i] << " "; cout << "\n";
    //for(int i = 0; i <= n; ++i) cout << setw(2) << q[i] << " "; cout << "\n";

    cout << ans << "\n";

    return 0;
}