#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300;
constexpr int M = 1'000'000'000;
int n, a, b;
long long fib[N];
int t;
long long x;
bool ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fib[0] = 0;
    fib[1] = 1;
    n = 2;
    while(fib[n-1] < M) {
        fib[n] = fib[n-1] + fib[n-2];
        n++;
    }

    cin >> t;
    while(t--) {
        cin >> x;
        ans = false;
        a = 0, b = n-1;
        while(a <= b) {
            if(fib[a] * fib[b] < x) a++;
            else if(fib[a] * fib[b] > x) b--;
            else {
                ans = true;
                break;
            }

        }
        if(ans) cout << "TAK\n";
        else cout << "NIE\n";
    }

    return 0;
}