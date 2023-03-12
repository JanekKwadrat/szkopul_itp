/*  Jan Zakrzewski
    XXIV Olimpiada Informatyczna, Etap II
    Zadanie Strajki (str)
    Rozwiązanie w złożoności O(n) */


#include <bits/stdc++.h>
using namespace std;

int sgn(int val) {
    return (0 < val) - (val < 0);
}

constexpr int N = 5e5+20;

int n, m;
vector<int> neighbor[N];
int ancestor[N]; // ukorzenione drzewo
bool strajk[N]; // strajk[i] = czy w i-tym mieście strajkują
int Count[N]; // count[i] = ile dzieci i-tego wierzchołka strajkuje
int ans;

bool visited[N];
queue<int> my_queue;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n-1; ++i) {
        int a, b;
        cin >> a >> b;
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i) visited[i] = false;
    
    my_queue.push(1);
    while(my_queue.size() > 0) {
        int u = my_queue.front();
        my_queue.pop();
        visited[u] = true;
        for(int v : neighbor[u]) {
            if(visited[v]) ancestor[u] = v;
            else my_queue.push(v);
        }
    }

    for(int u = 1; u <= n; ++u) strajk[u] = false;
    for(int u = 1; u <= n; ++u) Count[u] = 0;
    ans = 1;
    
    cin >> m;
    while(m--) {
        int z, s;
        cin >> z;
        s = sgn(z);
        z = abs(z);
        strajk[z] = !strajk[z];
        Count[ancestor[z]] += s;
        int ile = Count[z] + (int)strajk[ancestor[z]]; // z iloma strajkującymi miastami graniczy z-te miasto
        ans += s * (neighbor[z].size() - ile - 1);
        cout << ans << "\n";
    }
    
    return 0;
}