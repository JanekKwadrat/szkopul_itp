/* Jan Zakrzewski
   Codeforces Round 144
   Problem `B. Asterisk-Minor Template' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100;
int t;
int len_a, len_b;
char a[N], b[N];

bool seen_a[26][26];
bool seen_b[26][26];

int main() {

    cin >> t;
    while(t--) {
        cin >> a >> b;
        len_a = strlen(a);
        len_b = strlen(b);
        if(a[0] == b[0]) cout << "YES\n" << a[0] << "*\n";
        else if(a[len_a-1] == b[len_b-1]) cout << "YES\n*" << a[len_a-1] << "\n";
        else {
            for(int i = 0; i < 26;  ++i)
                for(int j = 0; j < 26;  ++j) {
                    seen_a[i][j] = false;
                    seen_b[i][j] = false;
                }
            for(int i = 1; i < len_a; ++i) seen_a[a[i-1]-'a'][a[i]-'a'] = true;
            for(int i = 1; i < len_b; ++i) seen_b[b[i-1]-'a'][b[i]-'a'] = true;
            bool ok = false;
            for(int i = 0; i < 26; ++i)
                for(int j = 0; j < 26; ++j) {
                    if(seen_a[i][j] && seen_b[i][j]) {
                        ok = true;
                        cout << "YES\n";
                        cout << "*" << (char)(i+'a') << (char)(j+'a') << "*\n";
                        goto break_the_loop;
                    }
                }
            break_the_loop:;
            if(!ok) cout << "NO\n";
        }
    }

    return 0;
}
