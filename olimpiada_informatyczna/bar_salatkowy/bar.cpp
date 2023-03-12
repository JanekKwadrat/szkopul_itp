/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap I
   Zadanie `Bar sałatkowy (bar)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'000 + 50;
int n;
char owoce[N];

int suma_fw[N]; // suma_fw[i] = owoce[1] + owoce[2] + ... + owoce[i], zachodzi -n <= suma_fw[i] <= n dla wszystkich 0 <= i <= n
int __memory_00[2 * N];
int* gdzie = __memory_00 + N;
int najdalej_fw[N]; // najdalej_fw[i] = największe takie j, że wrzucenie owoce[i], owoce[i+1], ..., owoce[j], w tej kolejności, spełnia wymagania

int dalej[N];
vector<int> Q;

deque<int> biggest;
int p, q;
int ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    cin >> owoce + 1;
    //owoce[n+1] = 'j';
    //n++;

    for(int i = n; i >= 1; --i) {
        if(owoce[i] == 'p') {
            Q.push_back(i);
            dalej[i] = i;
        } else {
            int j = n + 1;
            if(Q.size() > 0) {
                j = Q.back();
                Q.pop_back();
            }
            dalej[i] = j;
        }
    }

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

    p = 1, q = 0;
    ans = 0;
    while(true) {
        if(biggest.size() > 0 && biggest.front() > najdalej_fw[p]) {
            if(biggest.front() == dalej[p])
                biggest.pop_front();
            p++;
        } else {
            ans = max(ans, q - p + 1);
            q++;
            if(q > n) break;
            while(biggest.size() > 0 && biggest.back() < dalej[q])
                biggest.pop_back();
            biggest.push_back(dalej[q]);
        }
    }

    cout << ans << "\n";

    return 0;
}
