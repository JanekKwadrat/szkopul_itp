/*  Jan Zakrzewski
    XXV Olimpiada Informatyczna, Etap III
    Zadanie `Liczby kompletne (kom)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e9 + 20;
int n;
vector<int> ile(N);
vector<int> ans;

int digits(int x) {
    return (int) (floor(log10(x)) + 1);
}

int main() {

    cin >> n;
    for(int i = 1; i < n; ++i) {
        for(int j = i; j < n; j += i) ile[j]++;
        if(ile[i] == digits(i)) {
            ans.push_back(i);
            cout << i << " ";
            cout.flush();
        }
    }
    cout << "\n";

    cout << ans.size() << " elements\n";

    return 0;
}
