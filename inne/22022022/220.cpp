/* Jan Zakrzewski
   https://szkopul.edu.pl/problemset/problem/LF7mpaHOYLYAUMyWhG5Q1UeY/site/?key=statement
   Zadanie `22.02.2022 (220)' */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 30;
int t, n;
char date[N];

int Days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void inc() {
    date[1]++;
    if(date[1] == 10) {
        date[1] = 0;
        date[0]++;
    }
    int day = date[0] * 10 + date[1];
    int mon = date[2] * 10 + date[3];
    int year = date[n-4] * 1000 + date[n-3] * 100 + date[n-2] * 10 + date[n-1];

    bool leap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
    
    int days = Days[mon];
    if(mon == 2 && leap) days++;
    
    if(day > days) {
        date[0] = 0;
        date[1] = 1;
        date[3]++;
        if(date[3] == 10) {
            date[3] = 0;
            date[2]++;
        }
        mon = date[2] * 10 + date[3];
        if(mon > 12) {
            date[2] = 0;
            date[3] = 1;
            date[n-1]++;
            int k = n-1;
            while(date[k] == 10) {
                if(k == 4) {
                    date[4] = 1;
                    date[n] = 0;
                    date[n+1] = 0;
                    n++;
                    break;
                } else {
                    date[k] = 0;
                    date[k-1]++;
                    k--;
                }
            }
        }
    }

}

bool palindrom() {
    for(int i = 0; i < n-1; ++i) {
        int j = n-1 - i;
        if(date[i] != date[j]) return false;
    }
    return true;
}

void shf(char c) {
    for(int i = 0; i < n; ++i) date[i] += c;
}

int main() {

    cin >> t;
    while(t--) {
        cin >> date;
        n = strlen(date);
        shf('0' * -1);
        inc();

        while(!palindrom()) inc();
        
        shf('0');
        cout << date << "\n";
    }

    return 0;
}
