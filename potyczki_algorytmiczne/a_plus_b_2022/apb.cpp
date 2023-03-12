/*  Jan Zakrzewski
    Potyczki algorytmiczne 2022, Rundy zdalne
    Zadanie A+B (apb) */

#include <bits/stdc++.h>
using namespace std;

int len_a, len_b;
char a[6000];
char b[6000];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a;
    cin >> b;

    len_a = strlen(a);
    len_b = strlen(b);

    reverse(a, a + len_a);
    reverse(b, b + len_b);

    for(int i = len_a; i < 5100; ++i) a[i] = '0';
    for(int i = len_b; i < 5100; ++i) b[i] = '0';

    for(int i = 0; i < 5000; ++i) {
        a[i] += b[i] - '0';
        a[i+1] += (a[i] - '0') / 10;
        a[i] = (a[i] - '0') % 10 + '0';
    }

    len_a = 5100;
    while(a[len_a-1] == '0') len_a--;

    reverse(a, a + len_a);
    a[len_a] = 0;

    cout << a << "\n";

    return 0;
}