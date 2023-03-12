/* Jan Zakrzewski
    Potyczki Algorytmiczne 2022
    Zadanie Liczenie punktów */

#include <bits/stdc++.h>
using namespace std;

int n;
char str[1000];
bool ans[1000];
int answer = 0;

int main() {

    cin >> n;
    cin >> str;

    for(int i = 0; i < 10; ++i) ans[i] = true;
    for(int i = 0; i < n; ++i) 
        if(str[i] == 'N') ans[i/(n/10)] = false;
    for(int i = 0; i < 10; ++i) answer += ans[i];
    cout << answer << "\n";

    return 0;
}
