/*
    Jan Zakrzewski
    XXI Olimpiada Informatyczna, Etap II
    Rozwiązanie Zadania Przestępcy (prz)
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'020;
constexpr int INF = 1'000'090'000;

int n, k;
int c[N];
int m, l;
int x[N], y[N];
vector<int> where_c[N];
int bound_low[N];
int bound_high[N];
int sth_else[N] = { 0 };
int good_c;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> c[i];

    cin >> m >> l;
    for(int i = 1; i <= m; ++i) cin >> x[i];
    for(int i = 1; i <= l; ++i) cin >> y[i];
    good_c = x[m];

    for(int i = 1; i <= n; ++i) {
        where_c[c[i]].push_back(i);
    }

    {
        vector<int> next_arr;
        vector<int> prev_arr = where_c[x[m]];
        
        //for(auto elm : prev_arr) cout << (elm == INF ? 100 : elm) << " ";
        //cout << "\n";

        for(int i = m - 1; i >= 1; --i) {

            next_arr.resize(where_c[x[i]].size());
            int p = 0, q = 0;
            while(p < where_c[x[i]].size() && q < where_c[x[i+1]].size()) {
                //cout << where_c[x[i]][p] << " " << where_c[x[i+1]][q] << "\n";
                if(where_c[x[i]][p] < where_c[x[i+1]][q]) {
                    // pair (p, q) is good
                    next_arr[p] = prev_arr[q];
                    ++p;
                } else ++q;
            }
            for(; p < where_c[x[i]].size(); ++p) next_arr[p] = INF;
            prev_arr = next_arr;

            //for(auto elm : prev_arr) cout << (elm == INF ? 100 : elm) << " ";
            //cout << "\n";    
        }

        int p = 1, q = 0;
        while(p <= n && q < prev_arr.size()) {
            if(p < where_c[x[1]][q]) {
                bound_low[p] = prev_arr[q];
                ++p;
            } else ++q;
        }
        for(; p <= n; ++p) bound_low[p] = INF;
    }

    {
        vector<int> next_arr;
        vector<int> prev_arr = where_c[y[l]];

        //for(auto elm : prev_arr) cout << (elm == INF ? 100 : elm) << " ";
        //cout << "\n";    

        for(int i = l - 1; i >= 1; --i) {

            next_arr.resize(where_c[y[i]].size());
            int p = where_c[y[i]].size() - 1, q = where_c[y[i+1]].size() - 1;
            while(p >= 0 && q >= 0) {
                //cout << where_c[x[i]][p] << " " << where_c[x[i+1]][q] << "\n";
                if(where_c[y[i]][p] > where_c[y[i+1]][q]) {
                    // pair (p, q) is good
                    next_arr[p] = prev_arr[q];
                    --p;
                } else --q;
            }
            for(; p >= 0; --p) next_arr[p] = -INF;
            prev_arr = next_arr;

            //for(auto elm : prev_arr) cout << (elm == INF ? 100 : elm) << " ";
            //cout << "\n";    
        }

        int p = n, q = prev_arr.size() - 1;
        while(p >= 1 && q >= 0) {
            if(p > where_c[y[1]][q]) {
                bound_high[p] = prev_arr[q];
                --p;
            } else --q;
        }
        for(; p >= 1; --p) bound_high[p] = -INF;
    }

    //for(int i = 1; i <= n; ++i) cout << bound_low[i] << " "; cout << "\n";
    //for(int i = 1; i <= n; ++i) cout << bound_high[i] << " "; cout << "\n";

    for(int i = 1; i <= k; ++i) {
        if(where_c[i].size() == 0) continue;
        int a = where_c[i][0];
        int b = where_c[i][where_c[i].size() - 1];
        int p = bound_low[a];
        int q = bound_high[b];
        if(p > q) continue;
        ++sth_else[p];
        --sth_else[q+1];
    }

    int x = 0;
    vector<int> ans;
    for(int i = 1; i <= n; ++i) {
        x += sth_else[i];
        if(x > 0 && c[i] == good_c) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for(int el : ans) cout << el << " ";
    cout << "\n";

    return 0;
}

/*
33 5
1 4 4 1 1 1 4 5 2 4 1 3 3 1 1 1 2 2 2 4 2 1 5 5 2 5 1 2 2 4 3 3 3
5 5
1 2 3 4 5
1 2 3 4 5
*/