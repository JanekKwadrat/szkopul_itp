/*  Jan Zakrzewski
    XXVII Olimpiada Informatyczna, Etap II
    Zadanie 'Wielki Upadek (wie)' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

constexpr int N = 2e5 + 20;

int n;
i64 x[N]; // x[i] = pozycja i-tego domina
int h[N]; // h[i] = wysokosc i-tego domina

i64 N1, N2;
int H1, H2; // zakładamy, że H1 >= H2

int ile[N]; // ile[i] = ile jest takich j > i, że wywrócenie i-tego domina spowoduje wywrócenie domina j
i64 zas[N]; // zas[i] = jaki jest zasięg wywrócenia i-tego domina

i64 y[N]; // rozmiary kolejnych dziur, które będzie trzeba przykryć
i64 k1[N]; // k1[i] = ile kostek rozmiaru H1 trzeba by ustawić, aby pokryć przerwę y[i]
i64 k2[N]; // k2[i] = ile kostek rozmiaru H2 trzeba by ustawić, aby pokryć przerwę y[i]
i64 l1[N], l2[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> x[i] >> h[i];
    cin >> N1 >> H1 >> N2 >> H2;
    if(H1 < H2) {
        swap(N1, N2);
        swap(H1, H2);
    }

    ile[n] = 0;
    zas[n] = x[n] + h[n];
    for(int i = n-1; i >= 1; --i) {
        if(x[i] + h[i] < x[i+1]) ile[i] = 0;
        else {
            int j = i+1;
            while(true) {
                if(ile[j] != 0) j += ile[j];
                else if(j < n && x[i] + h[i] >= x[j+1]) j++;
                else break;
            }
            ile[i] = j - i;
        }
        zas[i] = max(x[i]+h[i], x[i+ile[i]]+h[i+ile[i]]);
    }
    // w tym momencie tablica ile[] powinna już zawierać poprawne wartości
    // poprzedni segment powinien mieć złożoność liniową
    //for(int i = 1; i <= n; ++i) cout << ile[i] << " "; cout << "\n";
    //for(int i = 1; i <= n; ++i) cout << zas[i] << " "; cout << "\n";
    // tu trzeba dodać kod, który sprawdzi poprawność otrzymanej tablicy ile[] przy losowym wejściu

    for(int i = 1; i <= n-1;) {
        for(int j = i; j <= i+ile[i]-1; ++j)
            y[j] = 0;
        y[i+ile[i]] = x[i+ile[i]+1] - zas[i];
        i += 1 + ile[i];
    }
    // w tym momencie tablica y[] powinna już zawierać poprawne wartości
    for(int i = 1; i <= n-1; ++i) cout << y[i] << " "; cout << "\n";

    for(int i = 1; i <= n-1; ++i) {
        k2[i] = (y[i] + H2 - 1) / H2;
        k1[i] = k2[i] / (H1 / H2);
        k2[i] -= k1[i] * (H1 / H2);
    }

    for(int i = 1; i <= n-1; ++i) cout << k1[i] << " "; cout << "\n";
    for(int i = 1; i <= n-1; ++i) cout << k2[i] << " "; cout << "\n";


    function<int(i64)> f = [&](i64 u)->int {
        // we wszystkich przerwach takich, że k2[i] >= u, zamiast małych kostek używamy dużych
        for(int i = 1; i <= n-1; ++i) {
            
        }
    };

    return 0;
}
