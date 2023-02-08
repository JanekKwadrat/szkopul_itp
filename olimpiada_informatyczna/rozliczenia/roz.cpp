/* Jan Zakrzewski
   XXVI Olimpiada Informatyczna, Etap II
   Zadanie `Rozliczenia (roz)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'020;

int q = 100;
long long arr[N] = {};

void inicjuj(int m) {

}

void dodaj(int k) {
    q = (q + 1) % N;
    arr[q] = k;
}

void koryguj(int i, int k) {
    int j = (q - i + 1 + N) % N;
    arr[j] += k;
}

long long suma(int i) {
    int p = (q - i + 1 + N) % N;
    long long ans = 0;
    if(p <= q) {
        for(int j = p; j <= q; ++j) ans += arr[j];
    } else {
        for(int j = 0; j <= q; ++j) ans += arr[j];
        for(int j = p; j <= N-1; ++j) ans += arr[j];
    }
    return ans;
}

/*int main() {

    inicjuj(3);
    dodaj(-6);
    cout << suma(1) << "\n";
    dodaj(5);
    koryguj(2, 10);
    cout << suma(3) << "\n";
    cout << suma(1) << "\n";

    return 0;
}*/

