#include <bits/stdc++.h>
using namespace std;

long long zlicz(long long x) {
    long long ans = 0;
    while(x) {
        if(x % 2) ans++;
        x /= 2;
    }
    return ans;
}

string dwojkowo(long long x) {
    if(x == 0) return "0";
    string ans = "";
    while(x) {
        if(x % 2) ans = "1" + ans;
        else ans = "0" + ans;
        x /= 2;
    }
    return ans;
}

int main() {

    long long n;
    cin >> n;

    cout << dwojkowo(n) << " " << dwojkowo(zlicz(n)) << "\n";

    return 0;
}