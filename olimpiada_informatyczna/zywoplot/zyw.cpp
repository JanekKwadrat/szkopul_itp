/* Jan Zakrzewski
   XXIII Olimpiada Informatyczna, Etap III
   Zadanie `Żywopłot (zyw)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 + 10;
int m, n; // m = wysokość ogrodu, n = szerokość ogrodu
// pola oznaczamy parami (x, y), gdzie 0 <= x < m oraz 0 <= y < n
char jaki_z_prawej[N][N]; // jaki_z_prawej[x][y] = jaki żywopłot można posadzić z prawej pola (x, y), wymiary (m, n-1)
char jaki_z_dolu[N][N];   // jaki_z_dolu[x][y]   = jaki żywopłot można posadzić z dołu pola (x, y),   wymiart (m-1, n)

char czy_z_prawej[N][N];  // czy_z_prawej[x][y]  = czy zostanie posadzony żywopłot z prawej pola (x, y), może być 'Z' albo '.', wymiary (m, n-1)
char czy_z_dolu[N][N];    // czy_z_dolu[x][y]    = czy zostanie posadzony żywopłot z dołu pola (x, y),   może być 'Z' albo '.', wymiary (m-1, n)

bool osiagalne[N][N]; // osiagalne[x][y] = czy uda się dojść do pola (x, y)

queue<pair<int, int>> Queue_prior;
queue<pair<int, int>> Queue_subsequent;
pair<int, int> odp1;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m >> n;
    for(int x = 0; x < m; ++x) cin >> jaki_z_prawej[x];
    for(int x = 0; x < m-1; ++x) cin >> jaki_z_dolu[x];
    
    for(int x = 0; x < m; ++x) {
        for(int y = 0; y < n-1; ++y)
            czy_z_prawej[x][y] = 'Z';
        czy_z_prawej[x][n-1] = 0;
    }
    for(int x = 0; x < m-1; ++x) {
        for(int y = 0; y < n; ++y)
            czy_z_dolu[x][y] = 'Z';
        czy_z_dolu[x][n] = 0;
    }

    for(int x = 0; x < m; ++x)
        for(int y = 0; y < n; ++y)
            osiagalne[x][y] = false;

    osiagalne[0][0] = true;
    Queue_prior.push(make_pair(0, 1));
    Queue_prior.push(make_pair(1, 0));

    while(true) {
        pair<int, int> u;
        char jak;
        int x, y;

        if(Queue_prior.size() > 0) {
            u = Queue_prior.front();
            Queue_prior.pop();
            jak = 'T';
        } else if(Queue_subsequent.size() > 0) {
            u = Queue_subsequent.front();
            Queue_subsequent.pop();
            jak = 'C';
        } else break;
        x = u.first, y = u.second;
        if(osiagalne[x][y]) continue;
        
        osiagalne[x][y] = true;
             if(x >= 1  && jaki_z_dolu  [x-1][y] == jak && osiagalne[x-1][y]) czy_z_dolu  [x-1][y] = '.'; // od góry
        else if(y >= 1  && jaki_z_prawej[x][y-1] == jak && osiagalne[x][y-1]) czy_z_prawej[x][y-1] = '.'; // od lewej
        else if(x < m-1 && jaki_z_dolu  [x][y]   == jak && osiagalne[x+1][y]) czy_z_dolu  [x][y] = '.'; // od dołu
        else if(y < n-1 && jaki_z_prawej[x][y]   == jak && osiagalne[x][y+1]) czy_z_prawej[x][y] = '.'; // od prawej
        else osiagalne[x][y] = false;

        if(!osiagalne[x][y] && jak == 'T') Queue_subsequent.push(make_pair(x, y));
        if(osiagalne[x][y]) {
            //cout << x << " " << y << "\n";
            if(x >= 1) Queue_prior.push(make_pair(x-1, y));
            if(y >= 1) Queue_prior.push(make_pair(x, y-1));
            if(x < m-1) Queue_prior.push(make_pair(x+1, y));
            if(y < n-1) Queue_prior.push(make_pair(x, y+1));
        }
    }

    odp1 = make_pair(0, 0);
    for(int x = 0; x < m; ++x) {
        for(int y = 0; y < n-1; ++y) {
            if(czy_z_prawej[x][y] == '.') continue;
            odp1.first++;
            if(jaki_z_prawej[x][y] == 'C') odp1.second++;
        }
    }
    for(int x = 0; x < m-1; ++x) {
        for(int y = 0; y < n; ++y) {
            if(czy_z_dolu[x][y] == '.') continue;
            odp1.first++;
            if(jaki_z_dolu[x][y] == 'C') odp1.second++;
        }
    }
    
    cout << odp1.first << " " << odp1.second << "\n";
    for(int x = 0; x < m; ++x) cout << czy_z_prawej[x] << "\n";
    for(int x = 0; x < m-1; ++x) cout << czy_z_dolu[x] << "\n";

    return 0;
}