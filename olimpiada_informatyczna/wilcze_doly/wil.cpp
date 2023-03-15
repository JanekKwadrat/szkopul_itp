/* Jan Zakrzewski
   XXII Olimpiada Informatyczna, Etap III
   Zadanie `Wilcze doły (wil)' */

#include <bits/stdc++.h>
using namespace std;

template<class T>
class special_queue {
    deque<T> Queue;
    deque<T> Ordered;
public:
    inline void push(T x) {
        Queue.push_back(x);
        while(Ordered.size() > 0 && Ordered.back() < x)
            Ordered.pop_back();
        Ordered.push_back(x);
    }
    inline void pop() {
        if(Ordered.front() == Queue.front())
            Ordered.pop_front();
        Queue.pop_front();
    }
    inline T top() {
        return Ordered.front();
    }
    inline size_t size() {
        return Queue.size();
    }
    // push() and pop() are of ammortized constant time complexity
    // top() and size() are of constant time complexity
};

// to zadanie może dać się rozwiązać drzewem przedziałowym i gąsienicą
// drzewo przedziałowe niekoniecznie będzie potrzebne

typedef unsigned long long u64;
constexpr int N = 2'000'000 + 20;
int n, d; // n = liczba dołów, d = długość Wielkiej Dechy, 1 <= d <= n <= 2'000'000
u64 P; // P = liczba worków z piaskiem
int w[N]; // w[i] = liczba worków z piaskiem potrzebnych do zasypania i-tego dołu

u64 suma[N]; // suma[i] = w[1] + w[2] + ... + w[i]
special_queue<u64> Queue;
int p, q; // końce gąsienicy
int ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> P >> d;
    for(int i = 1; i <= n; ++i) cin >> w[i];

    suma[0] = 0;
    for(int i = 1; i <= n; ++i)
        suma[i] = suma[i-1] + w[i];

    ans = 0;
    p = 1, q = d;
    Queue.push(suma[d]);
    while(true) {
        // w kolejce Queue przechowywane są sumy głębokości dołów, które przykrywa Wielka Decha jeśli w całości znajduje się w przedziale [p, q]
        u64 ile = suma[q] - suma[p-1] - Queue.top(); // ile worków z piasiem jest potrzebnych by zrównać z ziemią doły na przedziale [p, q]
        if(ile <= P) {
            ans = max(ans, q - p + 1);
            q++;
            if(q > n) break;
            Queue.push(suma[q] - suma[q-d]);
        } else {
            p++;
            Queue.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}