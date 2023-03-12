#include <bits/stdc++.h>
using namespace std;

int t;
struct P {
    int x, y;
} a, b, c;
bool ans;

int main() {

    cin >> t;
    while(t--) {
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;

        ans = false;

        if(a.x < b.x && b.x < c.x) ans = true;
        if(a.x > b.x && b.x > c.x) ans = true;
        if(a.y < b.y && b.y < c.y) ans = true;
        if(a.y > b.y && b.y > c.y) ans = true;

        if(b.x < c.x && c.x < a.x) ans = true;
        if(b.x > c.x && c.x > a.x) ans = true;
        if(b.y < c.y && c.y < a.y) ans = true;
        if(b.y > c.y && c.y > a.y) ans = true;

        if(c.x < a.x && a.x < b.x) ans = true;
        if(c.x > a.x && a.x > b.x) ans = true;
        if(c.y < a.y && a.y < b.y) ans = true;
        if(c.y > a.y && a.y > b.y) ans = true;

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
