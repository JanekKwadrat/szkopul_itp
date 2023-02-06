/* Jan Zakrzewski
   XXIX Olimpiada Informatyczna, Etap II
   Zadanie `Bomberman (bom)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1100;
constexpr int INF = 1e9;

int n;
char board[N][N];
pair<int, int> A, B;

int dist_A[N][N];
int dist_A_hor[N][N];
int dist_A_ver[N][N];

int dist_B[N][N];
int dist_B_hor[N][N];
int dist_B_ver[N][N];

constexpr int NOR = 1, HOR = 2, VER = 3;

queue<pair<pair<int, int>, int>> my_queue;
queue<pair<int, int>> my_queue1;

vector<pair<int, int>> D = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int>> D_hor = {{1, 0}, {-1, 0}};
vector<pair<int, int>> D_ver = {{0, 1}, {0, -1}};

int ans = INF;
pair<int, int> bomb;
string path;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        char str[N];
        cin >> str+1;
        for(int j = 1; j <= n; ++j) {
            board[i][j] = str[j];
            if(board[i][j] == 'P') A = make_pair(i, j);
            if(board[i][j] == 'K') B = make_pair(i, j);
        }
    }

    for(int i = 0; i <= n+1; ++i) {
        board[0][i] = 'X';
        board[i][0] = 'X';
        board[n+1][i] = 'X';
        board[i][n+1] = 'X';
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            dist_A[i][j] = INF;
            dist_A_hor[i][j] = INF;
            dist_A_ver[i][j] = INF;
        }
    dist_A[A.first][A.second] = 0;
    dist_A_hor[A.first][A.second] = 0;
    dist_A_ver[A.first][A.second] = 0;
    my_queue.push(make_pair(A, NOR));
    my_queue.push(make_pair(A, HOR));
    my_queue.push(make_pair(A, VER));
    //int S = 50;
    while(my_queue.size() > 0) {
        //S--;
        //if(S == 0) break;
        pair<int, int> p = my_queue.front().first;
        int t = my_queue.front().second;
        my_queue.pop();
        //cout << p.first << " " << p.second << " " << t << "\n";
        if(t == NOR) {
            //cout << dist_A[p.first][p.second] << "\n";
            for(pair<int, int> d : D) {
                pair<int, int> q = make_pair(p.first + d.first, p.second + d.second);
                if(board[q.first][q.second] == 'X') continue;
                while(board[q.first][q.second] != '#') {
                    if(dist_A[q.first][q.second] < INF) break;
                    dist_A[q.first][q.second] = dist_A[p.first][p.second] + 1;
                    my_queue.push(make_pair(q, NOR));
                    break;
                }
                while(true) {
                    if(dist_A_hor[q.first][q.second] < INF) break;
                    dist_A_hor[q.first][q.second] = dist_A[p.first][p.second] + 1;
                    my_queue.push(make_pair(q, HOR));
                    break;
                }
                while(true) {
                    if(dist_A_ver[q.first][q.second] < INF) break;
                    dist_A_ver[q.first][q.second] = dist_A[p.first][p.second] + 1;
                    my_queue.push(make_pair(q, VER));
                    break;
                }
            }
        } else if(t == HOR) {
            //cout << dist_A_hor[p.first][p.second] << "\n";
            for(pair<int, int> d : D_hor) {
                pair<int, int> q = make_pair(p.first + d.first, p.second + d.second);
                if(board[q.first][q.second] == 'X') continue;
                while(true) {
                    if(dist_A_hor[q.first][q.second] < INF) break;
                    dist_A_hor[q.first][q.second] = dist_A_hor[p.first][p.second] + 1;
                    my_queue.push(make_pair(q, HOR));
                    break;
                }
            }
        } else if(t == VER) {
            //cout << dist_A_ver[p.first][p.second] << "\n";
            for(pair<int, int> d : D_ver) {
                pair<int, int> q = make_pair(p.first + d.first, p.second + d.second);
                if(board[q.first][q.second] == 'X') continue;
                while(true) {
                    if(dist_A_ver[q.first][q.second] < INF) break;
                    dist_A_ver[q.first][q.second] = dist_A_ver[p.first][p.second] + 1;
                    my_queue.push(make_pair(q, VER));
                    break;
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            dist_B[i][j] = INF;
            dist_B_hor[i][j] = INF;
            dist_B_ver[i][j] = INF;
        }
    dist_B[B.first][B.second] = 0;
    dist_B_hor[B.first][B.second] = 0;
    dist_B_ver[B.first][B.second] = 0;
    my_queue.push(make_pair(B, NOR));
    my_queue.push(make_pair(B, HOR));
    my_queue.push(make_pair(B, VER));
    while(my_queue.size() > 0) {
        pair<int, int> p = my_queue.front().first;
        int t = my_queue.front().second;
        my_queue.pop();
        if(t == NOR) {
            for(pair<int, int> d : D) {
                pair<int, int> q = make_pair(p.first + d.first, p.second + d.second);
                if(board[q.first][q.second] == 'X') continue;
                while(board[q.first][q.second] != '#') {
                    if(dist_B[q.first][q.second] < INF) break;
                    dist_B[q.first][q.second] = dist_B[p.first][p.second] + 1;
                    my_queue.push(make_pair(q, NOR));
                    break;
                }
                while(true) {
                    if(dist_B_hor[q.first][q.second] < INF) break;
                    dist_B_hor[q.first][q.second] = dist_B[p.first][p.second] + 1;
                    my_queue.push(make_pair(q, HOR));
                    break;
                }
                while(true) {
                    if(dist_B_ver[q.first][q.second] < INF) break;
                    dist_B_ver[q.first][q.second] = dist_B[p.first][p.second] + 1;
                    my_queue.push(make_pair(q, VER));
                    break;
                }
            }
        } else if(t == HOR) {
            for(pair<int, int> d : D_hor) {
                pair<int, int> q = make_pair(p.first + d.first, p.second + d.second);
                if(board[q.first][q.second] == 'X') continue;
                while(true) {
                    if(dist_B_hor[q.first][q.second] < INF) break;
                    dist_B_hor[q.first][q.second] = dist_B_hor[p.first][p.second] + 1;
                    my_queue.push(make_pair(q, HOR));
                    break;
                }
            }
        } else if(t == VER) {
            for(pair<int, int> d : D_ver) {
                pair<int, int> q = make_pair(p.first + d.first, p.second + d.second);
                if(board[q.first][q.second] == 'X') continue;
                while(true) {
                    if(dist_B_ver[q.first][q.second] < INF) break;
                    dist_B_ver[q.first][q.second] = dist_B_ver[p.first][p.second] + 1;
                    my_queue.push(make_pair(q, VER));
                    break;
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            if(dist_A_hor[i][j] + dist_B_ver[i][j] < ans) {
                ans = dist_A_hor[i][j] + dist_B_ver[i][j];
                bomb = make_pair(i, j);
            }
            if(dist_A_ver[i][j] + dist_B_hor[i][j] < ans) {
                ans = dist_A_ver[i][j] + dist_B_hor[i][j];
                bomb = make_pair(i, j);
            }
        }

    if(ans == INF) cout << "NIE\n";
    else {
        cout << ans << "\n";
        cout << bomb.first << " " << bomb.second << "\n";

        // trzeba wybuchnąć bombę
        int x, y;
        x = bomb.first, y = bomb.second; while(board[x][y] != 'X') { board[x][y] = '.'; x--; }
        x = bomb.first, y = bomb.second; while(board[x][y] != 'X') { board[x][y] = '.'; x++; }
        x = bomb.first, y = bomb.second; while(board[x][y] != 'X') { board[x][y] = '.'; y--; }
        x = bomb.first, y = bomb.second; while(board[x][y] != 'X') { board[x][y] = '.'; y++; }

        for(int i = 0; i <= n+1; ++i)
            for(int j = 0; j <= n+1; ++j)
                dist_B[i][j] = INF;
        dist_B[B.first][B.second] = 0;
        my_queue1.push(make_pair(B.first, B.second));

        while(my_queue1.size() > 0) {
            pair<int, int> p = my_queue1.front();
            my_queue1.pop();
            for(pair<int, int> d : D) {
                pair<int, int> q = make_pair(p.first + d.first, p.second + d.second);
                if(board[q.first][q.second] == 'X') continue;
                if(board[q.first][q.second] == '#') continue;
                if(dist_B[q.first][q.second] < INF) continue;
                dist_B[q.first][q.second] = dist_B[p.first][p.second] + 1;
                my_queue1.push(q);        
            }
        }

        path = "";
        pair<int, int> p = A;
        while(p != B) {
                 if(dist_B[p.first][p.second-1] < dist_B[p.first][p.second]) { path += "L"; p.second--; }
            else if(dist_B[p.first][p.second+1] < dist_B[p.first][p.second]) { path += "P"; p.second++; }
            else if(dist_B[p.first-1][p.second] < dist_B[p.first][p.second]) { path += "G"; p.first--; }
            else if(dist_B[p.first+1][p.second] < dist_B[p.first][p.second]) { path += "D"; p.first++; }
        }

        cout << path << "\n";
    }

    return 0;
}

/*
10
P........X
........X.
.......X..
......X...
.....X....
....X.....
...X......
..X.......
.X........
X.........

*/
