#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20'020;
int n, l, m;
int arr[N];

int main() {

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> l >> m;
        arr[i] = (l << 10 - m) * 1024 + m;
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; ++i) {
        l = arr[i] / 1024;
        m = arr[i] % 1024;
        l >>= 10 - m;
        cout << l << " " << m << "\n";
    }

    return 0;
}