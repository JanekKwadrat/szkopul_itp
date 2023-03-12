/*  Jan Zakrzewski
    XX Olimpiada Informatyczna, Etap II
    Zadanie Spacer (spa) */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;

u64 bin2int(char* s) {
    char c;
    u64 ans = 0;
    while(c = *(s++)) {
        ans *= 2;
        ans += c - '0';
    }
    return ans;
}

int dist(u64 x, u64 y) {
    x = x ^ y;
    int ans = 0;
    while(x) {
        ans += x % 2;
        x /= 2;
    }
    return ans;
}

char s[100];
constexpr int N = 1e6+20;
int n, k;
u64 A, B;
u64 inexistent[N];

bool exists(u64 x) {
    int itr = (int)(lower_bound(inexistent, inexistent + k, x) - inexistent);
    if(itr <  0) return true;
    if(itr >= k) return true;
    return inexistent[itr] != x;
}

set<u64> neighborhood;
bool goodA = false, goodB = false;
int d = 0;
bool answer = false;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    cin >> s; A = bin2int(s);
    cin >> s; B = bin2int(s);
    for(int i = 0; i < k; ++i) {
        cin >> s; inexistent[i] = bin2int(s);
    }
    sort(inexistent, inexistent + k);

    neighborhood.clear();
    d = 0;
    neighborhood.insert(A);
    while(neighborhood.size() <= k + 20 && neighborhood.size() > 0) {
        set<u64> new_one;
        for(u64 u : neighborhood) {
            for(int i = 0; i < n; ++i) {
                u64 v = u ^ (1ull << i);
                if(v == B) { answer = true; goto printAnswer; }
                if(!exists(v)) continue;
                if(dist(A, v) != d+1) continue;
                new_one.insert(v);
            }
        }
        //for(int u : new_one) cout << u << " "; cout << "\n";
        neighborhood.swap(new_one);
        d++;
    }
    if(neighborhood.size() > k) goodA = true;

    neighborhood.clear();
    d = 0;
    neighborhood.insert(B);
    while(neighborhood.size() <= k + 20 && neighborhood.size() > 0) {
        set<u64> new_one;
        for(u64 u : neighborhood) {
            for(int i = 0; i < n; ++i) {
                u64 v = u ^ (1ull << i);
                if(v == A) { answer = true; goto printAnswer; }
                if(!exists(v)) continue;
                if(dist(B, v) != d+1) continue;
                new_one.insert(v);
            }
        }
        neighborhood.swap(new_one);
        d++;
    }
    if(neighborhood.size() > k) goodB = true;

    if(goodA && goodB) answer = true;

    printAnswer:
    if(answer) cout << "TAK\n";
    else cout << "NIE\n";

    return 0;
}