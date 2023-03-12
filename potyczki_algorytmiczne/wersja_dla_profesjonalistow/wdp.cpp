/*  Jan Zakrzewski
    Potyczki Algorytmiczne 2022
    Zadanie 'Wersja dla profesjonalistów' */

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void line(string &s, i64 n, const string &s1) {
    int c = 0;
    while(true) {
        int d = n % 9;
        n /= 9;
        if(d != 0) {
            if(d != 1) s.push_back(d + '0');
            if(s1.length() != 1) s.push_back('[');
            s.append(s1);
            if(s1.length() != 1) s.push_back(']');
        }
        if(n <= 0) break;
        c++;
        s.append("9[");
    }
    while(c--) s.push_back(']');
    // A9[9[2A9[5A9[2A9[8A9[6A9[3A9[6A9[9[4A9[A9[7A9[3A9[8A9[5A9[8A9[5A9[6A]]]]]]]]]]]]]]]]]] dla n = 1e18, s1 = "A"
}

void diagonal(string &s, i64 n) {
    //cout << n << "\n";

    if(n == 1) s.push_back('E');
    else if(n == 2) s.append("ECEAAECE");
       
    else if((n - 1) % 9 != 0) {
        i64 d = (n - 1) % 9;

        if(d != 1) {
            s.push_back(d + '0');
            s.push_back('[');
        }
        s.append("E");
        line(s, n-1, "CE");
        line(s, n, "A");
        if(d != 1) s.push_back(']');

        diagonal(s, n-d);

        if(d != 1) {
            s.push_back(d + '0');
            s.push_back('[');
        }
        line(s, n, "C");
        s.append("E");
        line(s, n-1, "AE");
        if(d != 1) s.push_back(']');

    } else {
        i64 part = n / 9;

        s.append("9[");

        s.append("E");
        line(s, part-1, "CE");
        s.append("9[");
        line(s, part, "A");
        diagonal(s, part);
        s.append("]");
        line(s, n, "C");

        s.append("]");

        line(s, n-1, "EA");
        s.append("E");
    }
}

void triangle(string &s, i64 n) {
    if(n == 1) s.append("DF");
    else if(n == 2) s.append("DFDBDFF");

    else if(n % 2 == 1) {
        
        line(s, n, "D");
        line(s, n-1, "FB");
        s.append("F");
        triangle(s, n-1);

    } else {
        i64 half = (n - 2) / 2;

        s.append("DF");
        s.append("2[");
        triangle(s, half);
        s.push_back(']');
        line(s, 2*half, "DB");
        line(s, half, "A");
        diagonal(s, half);
        line(s, half, "C");
        s.append("DB");
        line(s, 2*half, "FB");
        line(s, 2*half+1, "D");
        line(s, 2*half+2, "F");
    }
}

int main() {

    string s = "";
    i64 n;
    cin >> n;
    
    triangle(s, n);
    line(s, n, "B");

    cout << s << "\n";

    return 0;
}
