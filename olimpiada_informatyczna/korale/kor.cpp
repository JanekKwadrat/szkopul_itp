/*
    Jan Zakrzewski
    XVII Olimpiada Informatyczna, Etap I
    Rozwiązanie zadania 'Korale (kor)'
*/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned int u32;
typedef unsigned long long u64;
constexpr int N = 200'050;
constexpr u64 M = 4'294'967'291;
constexpr u64 p = 200'009;

int n;
u32 A[N];
u64 H;
u32 hash_pow[N];
u32 hash_arr[N];
u32 hash_arr1[N];

int roznorodnosc = 0;
vector<int> good;

int main() {

    cin >> n;
    A[0] = 0;
    for(int i = 1; i <= n; ++i) cin >> A[i];

    H = 1;
    for(int i = 0; i <= n + 5; ++i) {
        hash_pow[i] = H;
        H = H * p % M;
    }
    
    H = 0;
    for(int i = 0; i <= n + 1; ++i) {
        hash_arr[i] = H;
        H = (H * p + A[i]) % M;
    }
    H = 0;
    for(int i = n + 1; i >= 0; --i) {
        hash_arr1[i] = H;
        H = (H * p + A[i]) % M;
    }

    function<u32(u32, u32)> get_hash = [&](int a, int b)->u32 {
        a++, b++;
        u64 H0 = ( (u64) hash_arr[b] - (u64) hash_arr[a] * (u64) hash_pow[b - a] + (u64) M * M ) % M;
        u64 H1 = ( (u64) hash_arr1[a - 1] - (u64) hash_arr1[b - 1] * (u64) hash_pow[b - a] + (u64) M * M ) % M;
        return (H0 * H0 + H1 * H1 + H0 * H1 * 7) % M;
    };

    for(int k = 1; k <= n; ++k) {
        vector<int> sth;        
        int i = 0;
        while(k * (i + 1) <= n) {
            sth.push_back(get_hash(k * i, k * (i + 1)));
            i++;
        }
        sort(sth.begin(), sth.end());
        sth.erase(unique(sth.begin(), sth.end()), sth.end());
        int ans = sth.size();
        if(ans == roznorodnosc) good.push_back(k);
        else if(ans > roznorodnosc) {
            roznorodnosc = ans;
            good.clear();
            good.push_back(k);
        }
    }

    /*for(int i = 0; i < n; ++i) cout << hash_arr[i] << " "; cout << "\n";
    for(int i = 0; i < n; ++i) cout << hash_arr1[i] << " "; cout << "\n";*/

    /*while(1){
    int a, b;
    cin >> a >> b;
    cout << get_hash(a, b) << "\n";}*/
    
    cout << roznorodnosc << " " << good.size() << "\n";
    for(int k : good) cout << k << " ";
    cout << "\n";

    return 0;
}