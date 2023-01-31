/*  Jan Zakrzewski
    XXVIII Olimpiada Informatyczna, Etap II
    Zadanie `Projekt planszy (pro)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 93;
constexpr int L = 30;

unsigned long long K;
struct Maze {
    char arr[N*N+N+1];
    inline char& operator()(const int &x, const int &y) {
        return arr[x + y * (N+1)];
    }
    Maze() {
        for(int i = 0; i < N; ++i) operator()(N, i) = '\n';
        operator()(N+1, N) = '\0';
    }
} A;

int main() {

    cin >> K;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            A(i, j) = '#';
    for(int i = 0; i < N-2; ++i) A(i, 0) = '.';
    for(int i = 0; i < N-2; ++i) A(0, i) = '.';
    for(int i = 2; i < N; ++i) A(N-1, i) = '.';
    for(int i = 0; i < L; ++i) {
        for(int j = 0; i + j < L; ++j) {
            int x = 2 + 3*i + j;
            int y = 2 + i + 3*j;
            A(x, y) = '.';
            A(x+1, y) = '.';
            A(x, y+1) = '.';
            A(x+1, y+1) = '.';
            if(i + j + 1 < L) {
                A(x+1, y+2) = '.';
                A(x+2, y+1) = '.';
            } else {
                int z = x + 2;
                while(z < N-1) {
                    A(z, y+1) = '.';
                    z++;
                }
            }
        }
    }
    for(int k = 0; k < 64; ++k) {
        if((K >> k) % 2 == 0) continue;
        int i = L - k / 2 - 1;
        if(k % 2 == 0) {
            int x = 2 + 3*i;
            int y = 2 + i;
            x++;

            y--;
            while(y > 0) {
                A(x, y) = '.';
                y--;
            }
        } else {
            int x = 2 + i;
            int y = 2 + 3*i;

            x--;
            while(x > 0) {
                A(x, y) = '.';
                x--;
            }
        }
    }

    cout << N << "\n" << A.arr;
    return 0;
}
