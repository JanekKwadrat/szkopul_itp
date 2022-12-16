/*  Jan Zakrzewski
    XXVIII Olimpiada Informatyczna, Etap I
    Zadanie 'Cukiernia (cuk)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300'100;
int n;
long long wypiek[3][N];
long long ans = INT64_MAX;
long long Plus = 0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> wypiek[0][i] >> wypiek[1][i] >> wypiek[2][i];

    bool ok[3] = {false, false, false};
    for(int i = 1; i <= n; ++i) if(wypiek[0][i] > 0) ok[0] = true;
    for(int i = 1; i <= n; ++i) if(wypiek[1][i] > 0) ok[1] = true;
    for(int i = 1; i <= n; ++i) if(wypiek[2][i] > 0) ok[2] = true;

    for(int i = 1; i <= n; ++i) {
        long long sum = wypiek[0][i] + wypiek[1][i] + wypiek[2][i];
        wypiek[0][i] = sum - wypiek[0][i];
        wypiek[1][i] = sum - wypiek[1][i];
        wypiek[2][i] = sum - wypiek[2][i];
        long long m = wypiek[0][i];
        m = min(m, wypiek[1][i]);
        m = min(m, wypiek[2][i]);
        Plus += m;
        wypiek[0][i] -= m;
        wypiek[1][i] -= m;
        wypiek[2][i] -= m;
    }


    for(int j = 0; j < 6; ++j) {
        int p, q, r;
        switch(j) {
        case 0: p = 0, q = 1, r = 2; break;
        case 1: p = 0, q = 2, r = 1; break;
        case 2: p = 1, q = 0, r = 2; break;
        case 3: p = 1, q = 2, r = 0; break;
        case 4: p = 2, q = 0, r = 1; break;
        case 5: p = 2, q = 1, r = 0; break;
        }

        if(!ok[p]) p = -1;
        if(!ok[q]) q = -1;
        if(!ok[r]) r = -1;

        int pI = -1; long long pV = INT64_MAX;
        int qI = -1; long long qV = INT64_MAX;
        int rI = -1; long long rV = INT64_MAX;
        if(p != -1)
            for(int i = 1; i <= n; ++i) {
                if(wypiek[p][i] < pV) pI = i, pV = wypiek[p][i];
            }
        if(q != -1)
            for(int i = 1; i <= n; ++i) {
                if(i == pI) continue;
                if(wypiek[q][i] < qV) qI = i, qV = wypiek[q][i];
            }
        if(r != -1)
            for(int i = 1; i <= n; ++i) {
                if(i == pI) continue;
                if(i == qI) continue;
                if(wypiek[r][i] < rV) rI = i, rV = wypiek[r][i];
            }
        long long s = 0;
        for(int i = 1; i <= n; ++i) {
            if(i == pI) continue;
            if(i == qI) continue;
            if(i == rI) continue;
            long long m = INT64_MAX;
            if(p != -1) m = min(m, wypiek[p][i]);
            if(q != -1) m = min(m, wypiek[q][i]);
            if(r != -1) m = min(m, wypiek[r][i]);
            s += m;
        }
        //cout << "   " << p << " " << q << " " << r << "\n";
        //cout << "   " << pI << " " << qI << " " << rI << "\n";
        //cout << "   " << pV << " " << qV << " " << rV << "\n";
        //cout << "   " << s << "\n";
        if(p != -1) s += pV;
        if(q != -1) s += qV;
        if(r != -1) s += rV;

        ans = min(ans, s + Plus);
    }

    cout << ans << "\n";
    
    return 0;
}
