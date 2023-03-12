#include <bits/stdc++.h>

using namespace std;

long long n;

long long l = 1, r;

long long ternary_search(long long L, long long R)
{
    long long m1 = L + (R-L)/3;
    long long m2 = R - (R-L)/3;

    if (m2 - m1 < 2)
    {
        return min((m1+n-1)/m1 + m1, (m2+n-1)/m2 + m2);
    }
    else if (m2 - m1 == 2)
    {
        return min({(m1+n-1)/m1 + m1, (m1+n)/(m1+1) + m1+1, (m2+n-1)/m2 + m2});
    }

    if ((m1+n-1)/m1 + m1 > (m2+n-1)/m2 + m2)
    {
        return ternary_search(m1, R);
    }
    else if ((m1+n-1)/m1 + m1 < (m2+n-1)/m2 + m2)
    {
        return ternary_search(L, m2);
    }
    else
    {
        return ternary_search(m1, m2);
    }

}

int main()
{
    cin >> n;

    r = n+1;

    cout << ternary_search(l, r);
}