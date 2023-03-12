/*  Jan Zakrzeski
    Potyczki Algorytmiczne 2022, Rundy zdalne
    Zadanie Palindrom (pal)
    Rozwiązanie być może błędne */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 20;
int n;
char s[N];

pair<char, int> arr[3*N];
int p, q;

long long ans = 0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;
    n = strlen(s);

    p = N;
    q = N;
    arr[q] = make_pair(s[0], 1);
    for(int i = 1; i < n; ++i) {
        if(s[i] == arr[q].first) arr[q].second++;
        else arr[++q] = make_pair(s[i], 1);
    }

    //int i = 0;
    while(q - p > 0) {
        //if(i > 10) break; i++;
        //cout << p-N << " " << q-N << "\n";
        if(arr[p].first == arr[q].first) {
            int m = min(arr[p].second, arr[q].second);
            arr[p].second -= m;
            arr[q].second -= m;
            while(arr[p].second == 0) p++;
            while(arr[q].second == 0) q--;
        } else {
            if(q - p == 1) {
                if((arr[p].second == 1) && (arr[q].second == 1)) {
                    ans = -1;
                    break;
                }
            }
            if(arr[p].second < arr[q].second) {
                ans += arr[p].second;
                if(arr[p+1].second > 1) {
                    arr[p+1].second--;
                    arr[p-1] = make_pair(arr[p+1].first, 1);
                    p--;
                } else {
                    arr[p+2].second += arr[p].second;
                    p++;
                }
            } else {
                ans += arr[q].second;
                if(arr[q-1].second > 1) {
                    arr[q-1].second--;
                    arr[q+1] = make_pair(arr[q-1].first, 1);
                    q++;
                } else {
                    arr[q-2].second += arr[q].second;
                    q--;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}