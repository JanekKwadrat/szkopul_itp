#include <bits/stdc++.h>
using namespace std;

long long __solve(int k, long long arr[]) {
    sort(arr, arr + k);
    //for(int i =0; i <k; ++i) cout << arr[i] << " "; cout << "\n";
    long long* sum = new long long [k];
    long long S = 0;
    for(int i = 0; i < k; ++i) {
        S += arr[i];
        sum[i] = S;
    }
    long long ans = INT64_MAX;
    long long x = 0;
    for(int i = 0; i < k; ++i) {
        long long nans = (arr[i] * i - sum[i] + arr[i]) + (S - sum[i] - arr[i] * (k - i));
        if(nans < ans) {
            ans = nans;
            x = arr[i];
        }
    }
    return x;
}

constexpr int N = 100'050;
int n, k;
long long* arr[N];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) arr[i] = new long long [k];

    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> arr[j][i];
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << __solve(k, arr[i]) << " ";
    }
    cout << "\n";

    return 0;
}