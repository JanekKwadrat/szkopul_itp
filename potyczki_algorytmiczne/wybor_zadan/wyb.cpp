#include <bits/stdc++.h>
using namespace std;

int n;
int zadania[5][3] = { 0 };
char s[3];
int runda, dywizja;
bool ans = true;

int main() {

    cin >> n;
    while(n--) {
        cin >> s;
        runda = s[0] - '1';
        dywizja = s[1] - 'A';
        zadania[runda][dywizja]++;
    }

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(zadania[i][j] < 1) ans = false;
        }
    }
    for(int j = 0; j < 3; ++j) {
        if(zadania[4][j] < 2) ans = false;
    }

    if(ans) cout << "TAK\n";
    else cout << "NIE\n";

    return 0;
}