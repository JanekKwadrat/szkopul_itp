/* Jan Zakrzewski
   Codeforces Round 144
   Problem `A. Typical Interview Problem' */

#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

int L;
string fizzbuzz = "";
vector<string> lookup;

int main() {

    for(int i = 1; i <= 40; ++i) {
        if(i % 3 == 0) fizzbuzz += "F";
        if(i % 5 == 0) fizzbuzz += "B";
    }
    L = fizzbuzz.length();

    for(int i = 0; i < L; ++i) {
        for(int j = i+1; j < L; ++j) {
            lookup.push_back(fizzbuzz.substr(i, j - i));
        }
    }


    cin >> t;
    while(t--) {
        cin >> n >> s;
        bool ok = false;
        for(string oth : lookup) {
            if(oth == s) {
                ok = true;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
