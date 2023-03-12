/*
    Jan Zakrzewski
    Potyczki Algorytmiczne 2001
    Rozwiązanie zadania Restauracje
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1020;
constexpr int None = INT32_MAX;
int n, k, m;
int roadmap[N][N];
bool visited[N];
priority_queue<pair<int, int>> the_queue;
int answer = 0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k >> m;

    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            roadmap[i][j] = None;

    for(int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        //roadmap[0][a] = 0;
        //roadmap[a][0] = 0;
        the_queue.push(make_pair(0, a));
    }

    for(int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        roadmap[a][b] = d;
        roadmap[b][a] = d;
    }
    
    for(int i = 0; i <= n; ++i) visited[i] = false;
    //the_queue.push(make_pair(0, 0));
    while(the_queue.size() > 0) {
        auto elm = the_queue.top();
        the_queue.pop();
        int d = elm.first * -1;
        int u = elm.second;

        if(visited[u]) continue;
        visited[u] = true;
        
        answer = max(answer, d);
        for(int v = 1; v <= n; ++v) {
            if(roadmap[u][v] == None) continue;
            if(visited[v]) continue;
            the_queue.push(make_pair((d + roadmap[u][v]) * -1, v));
        }
    }

    cout << answer << "\n";

    return 0;
}