#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1050;
int n, m, q;
int i, j, ii, jj;
bool tab[N][N] = { false };
int answer = 0;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;
    while(q--) {
        cin >> i >> j;
        cin >> ii >> jj;
        queue<pair<int, int>> my_queue;
        my_queue.push(make_pair(ii, jj));
        if(i != 1) my_queue.push(make_pair(i-1, jj));
        if(j != 1) my_queue.push(make_pair(ii, j-1));
        if(i != 1 && j != 1) my_queue.push(make_pair(i-1, j-1));
        while(my_queue.size() > 0) {
            int iii = my_queue.front().first;
            int jjj = my_queue.front().second;
            my_queue.pop();
            if(tab[iii][jjj]) answer--;
            else answer++;
            tab[iii][jjj] = !tab[iii][jjj];
        }
        cout << answer << "\n";
    }

    return 0;
}