#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {

    cin >> n;
    while(n % 2 == 0) n /= 2;
    while(n % 3 == 0) n /= 3;
    while(n % 5 == 0) n /= 5;
    if(n == 1) cout << "Bambus happy\n";
    else cout << "Bambus smutny\n";

    return 0;
}