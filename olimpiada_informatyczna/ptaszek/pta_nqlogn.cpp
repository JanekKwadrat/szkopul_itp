/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap II
   Zadanie `Ptaszek (pta)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'000 + 100;
int n, q, k;
int drzewo[N];

priority_queue<tuple<int, int, int>> Queue; // kolejka trójek (-odp, -wys, itr)
int answer;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> drzewo[i];

    cin >> q;
    while(q--) {
        cin >> k;

        Queue.push(make_tuple(0, -drzewo[n], n));
        for(int i = n-1; i >= 1; --i) {
            int odp, wys, j;
            while(true) {
                odp = - get<0>(Queue.top());
                wys = - get<1>(Queue.top());
                j = get<2>(Queue.top());
                if(j <= i + k) break;
                else Queue.pop();
            }
            //cout << i << ": " << odp << " " << wys << " " << j << "\n";
            if(wys >= drzewo[i]) odp++;
            Queue.push(make_tuple(-odp, -drzewo[i], i));
            answer = odp;

        }
        while(Queue.size() > 0) Queue.pop();

        cout << answer << "\n";
    }

    return 0;
}
