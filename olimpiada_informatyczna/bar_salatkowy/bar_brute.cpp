/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap I
   Zadanie `Bar sałatkowy (bar)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'000 + 100;
int n; // 1 <= n <= 10^6
char owoce[N];
int suma_fw[N]; // suma_fw[i] = owoce[1] + owoce[2] + ... + owoce[i], zachodzi -n <= suma_fw[i] <= n dla wszystkich 0 <= i <= n
int suma_bw[N]; // suma_bw[i] = owoce[n] + owoce[n-1] + ... + owoce[i], zachodzi -n <= suma_bw[i] <= n dla wszystkich 1 <= i <= n+1

int __memory_00[2 * N];

int* gdzie = __memory_00 + N;
int najdalej_fw[N]; // najdalej_fw[i] = największe takie j, że wrzucenie owoce[i], owoce[i+1], ..., owoce[j], w tej kolejności, spełnia wymagania
int najdalej_bw[N]; // najdalej_bw[i] = najmniejsze takie j, że wrzucenie owoce[i], owoce[i-1], ..., owoce[j], w tej kolejności, spełnia wymagania
int ans = 0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    cin >> owoce + 1;

    suma_fw[0] = 0;
    for(int i = 1; i <= n; ++i) {
        switch(owoce[i]) {
            case 'p': suma_fw[i] = suma_fw[i-1] + 1; break;
            case 'j': suma_fw[i] = suma_fw[i-1] - 1; break;
        }
    }
    for(int x = -n; x <= n; ++x) gdzie[x] = n+1;
    for(int i = n; i >= 1; --i) {
        gdzie[suma_fw[i]] = i;
        najdalej_fw[i] = gdzie[suma_fw[i-1]-1]-1;
    }
    
    suma_bw[n+1] = 0;
    for(int i = n; i >= 1; --i) {
        switch(owoce[i]) {
            case 'p': suma_bw[i] = suma_bw[i+1] + 1; break;
            case 'j': suma_bw[i] = suma_bw[i+1] - 1; break;
        }
    }
    for(int x = -n; x <= n; ++x) gdzie[x] = 0;
    for(int i = 1; i <= n; ++i) {
        gdzie[suma_bw[i]] = i;
        najdalej_bw[i] = gdzie[suma_bw[i+1]-1]+1;
    }

    // gąsienica ?
    
    // tutaj jest brute force
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            if(j > najdalej_fw[i]) continue;
            if(i < najdalej_bw[j]) continue;
            ans = max(ans, j - i + 1);
        }
    }
    
    cout << ans << "\n";

    return 0;
}
