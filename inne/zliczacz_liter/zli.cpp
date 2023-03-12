#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int ile[256] = { 0 };

int main() {

    cin >> n;
    getline(cin, str);
    while(n--) {
        getline(cin, str);
        for(char c : str) {
            ++ile[c];
        }
    }
    
    for(char c = 'a'; c <= 'z'; ++c) if(ile[c] > 0) cout << c << " " << ile[c] << "\n";
    for(char c = 'A'; c <= 'Z'; ++c) if(ile[c] > 0) cout << c << " " << ile[c] << "\n";

    return 0;
}