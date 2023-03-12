#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_B = 1e6 + 50;

int B, q;
int a[MAX_B];
long long A[MAX_B];
long long sum;
long long k;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> B >> q;

    sum = 0;
    for(int i = 0; i < B; ++i) {
        cin >> a[i];
        sum += (long long) a[i] * (long long) i;
        sum %= B-1;
    }

    //cout << sum << "\n";
    if(sum > 0) a[sum]--;

    A[0] = 0;
    for(int i = 1; i < B; ++i) A[i] = A[i-1] + a[i-1];
    sum = A[B-1] + a[B-1];

    /*for(int i = 0; i < B; ++i) cout << a[i] << " ";
    cout << "\n";
    for(int i = 0; i < B; ++i) cout << A[i] << " ";
    cout << "\n";*/

    if(sum > a[0]) {
        while(q--) {
            cin >> k;
            int itr = -1;
            if(k < sum) itr = (int)(upper_bound(A, A + B, k) - A) - 1;
            cout << itr << "\n";
        }
    } else {
        while(q--) {
            cin >> k;
            if(k == 0) cout << "0\n";
            else cout << "-1\n";
        }
    }

    return 0;
}