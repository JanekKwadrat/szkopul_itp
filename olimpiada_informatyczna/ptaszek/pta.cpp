/* Jan Zakrzewski
   XXI Olimpiada Informatyczna, Etap II
   Zadanie `Ptaszek (pta)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'000'000 + 100;
int n, q, k;
int drzewo[N];
int odpowiedz[N];

deque<int> Queue; // kolejka indeksów

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> drzewo[i];

    cin >> q;
    while(q--) {
        cin >> k;

        odpowiedz[n] = 0;
        Queue.push_back(n);
        for(int i = n-1; i >= 1; --i) {
            int j;
            while(true) {
                j = Queue.front();
                if(j <= i + k) break;
                else Queue.pop_front();
            }
            odpowiedz[i] = odpowiedz[j];
            //cout << i << " " << j << "\n";
            if(drzewo[j] >= drzewo[i]) odpowiedz[i]++;
            while(Queue.size() > 0
            && make_pair(odpowiedz[Queue.back()], drzewo[Queue.back()]) > make_pair(odpowiedz[i], drzewo[i]))
                Queue.pop_back();
            Queue.push_back(i);
        }
        Queue.clear();

        //for(int i = 1; i <= n; ++i) cout << drzewo[i] << " "; cout << "\n";
        //for(int i = 1; i <= n; ++i) cout << odpowiedz[i] << " "; cout << "\n";

        cout << odpowiedz[1] << "\n";
    }

    return 0;
}
