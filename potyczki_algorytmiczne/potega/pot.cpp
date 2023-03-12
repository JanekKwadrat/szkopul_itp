#include <bits/stdc++.h>
using namespace std;

int n, l;
string str;

int main() {

    cin >> str;
    
    if(str == "0") cout << "1\n";
    else {
        str = "0" + str;
        l = str.length();
        n = str[l-1] + 10 * str[l-2];
        constexpr int ans[] = {6, 2, 4, 8};
        cout << ans[n % 4] << "\n";
    }

    return 0;
}