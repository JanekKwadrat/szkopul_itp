/*
    Jan Zakrzewski
    XXX Olimpiada Informatyczna, Etap I
    Rozwiązanie podzadania 1 zadania 'Zboże (zbo)'
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100'050;
int n, k;
vector<pair<int,int>> neighbor[N];
bool castle[N];
vector<int> princes;
vector<int> answer;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n-1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        neighbor[a].push_back(make_pair(b, c));
        neighbor[b].push_back(make_pair(a, c));
    }

    for(int i = 1; i <= k; ++i) {
        int p;
        cin >> p;
        princes.push_back(p);
    }

    fill(castle + 1, castle + n + 1, false);
    castle[1] = true;
    int ans = 0;

    for(int p : princes) {
        vector<bool> visited(N);
        fill(visited.begin(), visited.end(), false);
        queue<pair<int,int>> my_queue;
        my_queue.push(make_pair(p, 0));
        while(my_queue.size() > 0) {
            int u = my_queue.front().first;
            int d = my_queue.front().second;
            my_queue.pop();
            if(visited[u]) continue;
            visited[u] = true;
            if(castle[u]) ans += d;
            for(auto elm : neighbor[u]) {
                int v = elm.first;
                int dd = elm.second;
                if(visited[v]) continue;
                my_queue.push(make_pair(v, d + dd));
            }
        }
        castle[p] = true;
        answer.push_back(ans);
    }

    for(int a : answer) cout << 2 * a << "\n";

    return 0;
}